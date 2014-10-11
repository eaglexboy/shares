/*
 * economy.c
 *
 *  Created on: Aug 9, 2012
 *      Author: Eleazar Castellanos
 * Description: This program is the economic engine for Captain's Shares: The
 *              Video Game.
 *
 * (C) Copyright 2012. EC Systems Design, LLC
 *
 *	This file is part of Captain's Shares: The Video Game
 *
 *  Captain's Shares: The Video Game is free software: you can redistribute
 *  it and/or modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Captain's Shares: The Video Game is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 *  Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/********************************** Dependencies *******************************/
#include <stdio.h>
#include <stdlib.h>
#include <my_global.h>
#include <mysql.h>
#include "economy.h"
#include "commonfunctions.h"
#include "importconfig.h"

/********************************** Functions **********************************/
int loadRates(void){
// This function loads consumption and production rates for each good

	// Initializing variables
	int i;	// Misc Counters

	// Loading consumption rates
	char *SQL = "SELECT `goodID`, `consumptionRate` FROM `consumptionRates`";
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Reseting temporary array pointer
	i=0;

	// Cycling through each Row
	while ((row = mysql_fetch_row(result))) {
		//Storing Good ID in Array
		consumptionRate[i].goodID = atoi(row[0]);
		consumptionRate[i].rate = atof(row[1]);

		// Moving pointer to next locations
		i++;
	}

	// Loading production rates
	SQL = "SELECT `goodID`, `productionRate` FROM `productionRates`";
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Reseting temporary array pointer
	i=0;

	// Cycling through each Row
	while ((row = mysql_fetch_row(result))) {
		//Storing Good ID in Array
		productionRate[i].goodID = atoi(row[0]);
		productionRate[i].rate = atof(row[1]);

		// Moving pointer to next locations
		i++;
	}

	// Loading Production Factors
	SQL = "SELECT `goodID`, `productionFactor` FROM `productionFactors`";
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Reseting temporary array pointer
	i=0;

	// Cycling through each Row
	while ((row = mysql_fetch_row(result))) {
		//Storing Good ID in Array
		productionFactor[i].goodID = atoi(row[0]);
		productionFactor[i].rate = atof(row[1]);

		// Moving pointer to next locations
		i++;
	}

	return 0;
}

float WEC(int marketID){
// This function calculates Workforce Employment Cost

	// Initializing Variables
	float fish, food, water, textiles;

	// Setting defualt value
	fish = food = water = textiles = 0;

	// Getting Market price
	fish = goodPrice(2, marketID);
	food = goodPrice(3, marketID);
	water = goodPrice(5, marketID);
	textiles = goodPrice(13, marketID);

	return ((0.15 * fish) + (0.15 * food) + (0.25 * water) + (0.05 * textiles));
}

systemDemographics loadSystemDemographics(int systemID){
// This function return the specified system's Demographics
	// Initializing variables
	systemDemographics theData;
	char *SQL = (char*)malloc(sizeof(char) * 1024);
	char *temp;


	// Loading consumption rates
	strcpy(SQL, "SELECT `Population`, `Funds`, `Taxes` FROM `destinations` WHERE `ID` =");
	temp = ftoa(systemID, 0);
	strcat(SQL, temp);
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	if(totalRows > 0){
		row = mysql_fetch_row(result);
		theData.systemID = systemID;
		theData.pop = atoi(row[0]);
		theData.funds = atof(row[1]);
		theData.taxes = atof(row[2]);
	}
	else {
		theData.systemID = systemID;
		theData.pop = 0;
		theData.funds = 0;
	}

	return theData;
}

production produceGood(int SystemID, int goodID, int availableWorkers){
// This function produces the good in the system specified

	// Initializing
	production theProduct;
	int workers;
	float costPerUnit;
	int Produced;
	float cost;

	// How many workers are producing this good
	workers = (availableWorkers * ((float)((rand() % 50) + 1)/100));

	// Calculating cost per unit
	costPerUnit = calculateProductionCost(SystemID, goodID);

	// Calculating how much product was created
	Produced = workers * productionRateForGood(goodID) * ((importsGood(SystemID, goodID)) ? 0.75 : 1) * ((exportsGood(SystemID, goodID)) ? 1.25 : 1);

	// Calculating Production Cost
	cost = costPerUnit * Produced;

	// Preping data for return
	theProduct.workers = workers;
	theProduct.cost = cost;

	// Saving production
	updateStock(SystemID, goodID, Produced);

	return theProduct;
}

float productionFactorForGood(int goodID){
// This function return	the Production Factor for the specified good

	// Initialize
	int i;

	for(i = 0; i < numberOfGoods; i++){
		if(productionFactor[i].goodID == goodID){
			return productionFactor[i].rate;
			break;
		}
	}

	return 0;
}


float productionRateForGood(int goodID){
// This function return	the Production Factor for the specified good

	// Initialize
	int i;

	for(i = 0; i < numberOfGoods; i++){
		if(productionRate[i].goodID == goodID){
			return productionRate[i].rate;
			break;
		}
	}

	return 0;
}


int importsGood(int SystemID, int goodID){
// This function returns true if System imports the good.

	// Initializing
	int i;

	for(i = 0; i < numberOfDestinations; i++){
		if(markets[i].marketID == SystemID){
			if(markets[i].goodID == goodID){
				return markets[i].import;
			}
		}
	}

	return FALSE;
}

int exportsGood(int SystemID, int goodID){
// This function returns true if System imports the good.

	// Initializing
	int i;

	for(i = 0; i < numberOfDestinations; i++){
		if(markets[i].marketID == SystemID){
			if(markets[i].goodID == goodID){
				return markets[i].export;
			}
		}
	}

	return FALSE;
}

void updateStock(int SystemID, int goodID, int Amount){
// This function updates the resource stock for the system.

	// Initializing
	char *SQL = (char*)malloc(sizeof(char) * 1024);
	float stock;

	// Loading current supply
	strcpy(SQL, "SELECT `supply` FROM `markets` WHERE `locationID`=");
	strcat(SQL, ftoa(SystemID, 0));
	strcat(SQL," AND `goodID`=");
	strcat(SQL, ftoa(goodID, 0));
	strcat(SQL, ";");
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Storing current Stock
	if(totalRows > 0){
		row = mysql_fetch_row(result);
		stock = atof(row[0]);
	}
	else {
		stock = 0;
	}

	stock += Amount;
	if(stock < 0){
		stock = 0;
	}

	strcpy(SQL, "UPDATE `markets` SET `supply`=");
	strcat(SQL, ftoa(stock, 0));
	strcat(SQL, " WHERE `locationID`=");
	strcat(SQL, ftoa(SystemID, 0));
	strcat(SQL," AND `goodID`=");
	strcat(SQL, ftoa(goodID, 0));
	strcat(SQL, ";");

	mysql_query(conn, SQL);

	/* Get the number of affected rows */
	affected_rows = mysql_affected_rows(conn);

	if(affected_rows == 0){
		printf("Could not update System's Stock Level of Good.(%i,  %i, %.0f)\n", SystemID, goodID, stock);
	}
}

float calculateProductionCost(int SystemID, int goodID){
// This function calculates the cost to produce one unit of a the specified
// Good
	return ((productionFactorForGood(goodID) * goodPrice(17, SystemID)) + WEC(SystemID));
}

float consumptionRateForGood(int goodID){
// This function returns the consumption rate for the Specified good in the
// specified system.

	// Initialize
	int i;	// Misc. counters

	for(i = 0; i < numberOfGoods; i++){
		if(consumptionRate[i].goodID == goodID){
			return consumptionRate[i].rate;
			break;
		}
	}

	return 0;

}

float stockLevel(int SystemID, int goodID){
// This function returns the current stock level

	// Initializing
	char *SQL = (char*)malloc(sizeof(char) * 1024);

	/**** Loading Goods ****/
	strcpy(SQL, "SELECT `supply` FROM `markets` WHERE `locationID`=");
	strcat(SQL, ftoa(SystemID, 0));
	strcat(SQL, " AND `goodID`=");
	strcat(SQL, ftoa(goodID, 0));
	strcat(SQL, ";");
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	row = mysql_fetch_row(result);
	if(totalRows == 0){
		return 0;
	}
	else {
		return atoi(row[0]);
	}
}

void updatePrice(int systemID, int goodID, float Price){
// This function will update the price for a good in the specified system

	//Intializing
	char *SQL = (char*)malloc(sizeof(char) * 1024);

	strcpy(SQL, "UPDATE `markets` SET `currentValue`=");
	strcat(SQL, ftoa(Price, 2));
	strcat(SQL, " WHERE `locationID`=");
	strcat(SQL, ftoa(systemID, 0));
	strcat(SQL," AND `goodID`=");
	strcat(SQL, ftoa(goodID, 0));
	strcat(SQL, ";");

	mysql_query(conn, SQL);

	/* Get the number of affected rows */
	affected_rows = mysql_affected_rows(conn);

	if(affected_rows == 0){
		printf("Could not update System's Price of Good.\n");
	}
}

void updateDemographics(systemDemographics SystemDemographics){
// This function will store the System's New Funds

	//Intializing
	char *SQL = (char*)malloc(sizeof(char) * 1024);

	strcpy(SQL, "UPDATE `destinations` SET `Funds`=");
	strcat(SQL, ftoa(SystemDemographics.funds, 2));
	strcat(SQL, ", `Population`=");
	strcat(SQL, ftoa(SystemDemographics.pop, 2));
	strcat(SQL, " WHERE `ID`=");
	strcat(SQL, ftoa(SystemDemographics.systemID, 0));
	strcat(SQL, ";");

	mysql_query(conn, SQL);

	/* Get the number of affected rows */
	affected_rows = mysql_affected_rows(conn);

	if(affected_rows == 0){
		printf("Could not update System's Funds.\n");
	}
}

void updateTaxes(int systemID, int Amount){
// This function updates the amount of tax collected per citizen in the system

	//Initialize
	char *SQL = (char*)malloc(sizeof(char) * 1024);
	float taxes;

	/**** Loading Current Taxes amount****/
	strcpy(SQL, "SELECT `taxes` FROM `destinations` WHERE `ID`=");
	strcat(SQL, ftoa(systemID, 0));
	strcat(SQL, ";");
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Storing Taxes
	if(totalRows > 0){
		row = mysql_fetch_row(result);
		taxes = atof(row[0]);

		taxes += Amount;
		if(taxes < 0){
			taxes = 0;
		}

		strcpy(SQL, "UPDATE `destinations` SET `taxes`=");
		strcat(SQL, ftoa(taxes, 2));
		strcat(SQL, " WHERE `ID`=");
		strcat(SQL, ftoa(systemID, 0));
		strcat(SQL, ";");

		mysql_query(conn, SQL);

		/* Get the number of affected rows */
		affected_rows = mysql_affected_rows(conn);

		if(affected_rows == 0){
			printf("Could not update System's Taxes.\n");
		}
	}
}

int main(void){

/************************** Initializing variables ***************************/
	int i, j;					//Misc counter
	int workforcePercentage;	// Total amount of the population that is
								// workforce.
	int growthPercentage;		// Total amount of population growth
	float taxCollection;		// Money Collected from Taxes.
	float productionCost;		// Cost to produce resources
	int consumed;				// Amount of the Good Consumed.
	float goodReserve;			// Amount of a Good to Reserve
	float fluxFactor;			// Fluctuation Factor
	float fluxPrice;			// Good price based on the fluctuation

	systemDemographics SystemData;	// System Demographics
	production Products;			// Produced Product data


/******************************* Main Program ********************************/

	// Seeding Randomizer
	srand(time(NULL));

	// Loading Settings
	printf("Loading Config.ini....");
	if(loadConfig()){
		exit(0);
	}
	printf("Done.\n");

	// Connecting to DB
	printf("Connecting to DB...");
	if(connectToDB()){
		exit(0);
	}
	printf("Done.\n");

	// Loading Goods
	printf("Loading Goods...");
	loadGoods();
	printf("Done.\n");

	// Setting Good Rates
	productionRate = malloc(numberOfGoods * sizeof(goodRate));
	consumptionRate = malloc(numberOfGoods * sizeof(goodRate));
	productionFactor = malloc(numberOfGoods * sizeof(goodRate));

	// Loading Rates
	printf("Loading Consumption and Production Rates...");
	if(loadRates()){
		exit(0);
	}
	printf("Done.\n");

	// Loading Markets
	printf("Loading Markets...");
	loadDestinations();
	if(loadMarkets()){
		exit(0);
	}
	printf("Done.\n");


	// Cycling through each market
	for(i = 0; i < numberOfDestinations; i++){
		// Loading Demographic Data
		SystemData = loadSystemDemographics(destinations[i].destinationID);

		// Setting Growth
		growthPercentage = ((rand() % 10) + 1) * ((rand() % 2) ? 1:-1);
		SystemData.pop += round(SystemData.pop * ((float)growthPercentage/100));

		// Setting Workforce
		workforcePercentage = ((rand() % 25) + 1);
		SystemData.workPop = round(SystemData.pop * ((float)workforcePercentage / 100));

		// Collecting Taxes
		taxCollection = (SystemData.workPop * SystemData.taxes);
		SystemData.funds += (SystemData.workPop * taxCollection);
		updateDemographics(SystemData);

		//Producing/Consuming Goods
		productionCost = 0;
		for(j = 0; j < numberOfGoods; j++){
			Products = produceGood(SystemData.systemID, goodsID[j], SystemData.workPop);

			// Removing workers used to produce this good from work popultion
			(SystemData.workPop -= Products.workers);
			if(SystemData.workPop < 0){
				SystemData.workPop = 0;
			}

			// Updating Total Production Cost for the System
			productionCost += Products.cost;

			// Calculating Consumption Amount of the Good
			consumed = ((SystemData.pop * consumptionRateForGood(goodsID[j])) * (0 -1));

			// Updating System's Stock
			updateStock(SystemData.systemID, goodsID[j], consumed);

			// Determining Amount to reserve
			goodReserve = ((float)consumed * (0 - 1)) * TICKS_TO_RESERVE_FOR;

			// Calculating  Factor
			fluxFactor = 1 - ((stockLevel(SystemData.systemID, goodsID[j]) - goodReserve)/goodReserve);

			// Calculating New Sell Price
			fluxPrice = fluxFactor * goodPrice(goodsID[j], SystemData.systemID);

			// Did it cost more to produce then the current Sell Price
			if(goodPrice(goodsID[j], SystemData.systemID) - calculateProductionCost(SystemData.systemID, goodsID[j]) < 0){
				// Add the difference to the new Sell Price.
				fluxPrice += (calculateProductionCost(SystemData.systemID, goodsID[j]) - goodPrice(goodsID[j], SystemData.systemID));
			}

			// Update New Sell Price
			updatePrice(SystemData.systemID, goodsID[j], fluxPrice);
		} // Good Cycle for()

		// Update Taxes
		if(taxCollection - productionCost < 0){
			updateTaxes(SystemData.systemID, 1);
		}
		else {
			updateTaxes(SystemData.systemID, -1);
		}
	}// Markets Cycle for()

	// Clearing memory
	printf("Clearing Memory...");
	mysql_free_result(result);
	iniparser_freedict(settings);
	free(destinations);
	free(markets);
	printf("Done.\n");

	return 0;
}
