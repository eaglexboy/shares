/*
 * shipments.c
 *
 *  Created on: Jul 25, 2012
 *      Author: Eleazar Castellanos
 * Description: This program randomly creates shipments for all available
 * 				markets.
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
#include <math.h>
#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "importconfig.h"
#include "commonfunctions.h"

/********************************** Prototypes *******************************/
int insert_shipment(struct shipment *);
int main(int argc, char **argv);
int duplicatShipment(int, int, int, float);


/********************************** Functions *******************************/
int insert_shipment(struct shipment *theShipment) {
	// This function inserts a records into the shipments table

	//Initializing Variables
	char *sql = (char*)malloc(sizeof(char) * 1024);
	char *DateTime = (char*)malloc(sizeof(char) * 20);
	char *temp;

	// Check if duplicate
	switch(duplicatShipment(theShipment->goodID, theShipment->sourceID, theShipment->destinationID, theShipment->amount)){
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		default:

			// Connecting to DB
			connectToDB();

			// Preparing statement
			strcpy(sql, "INSERT INTO `shipments` (`ID`, `goodID`, `sourceID`, `destinationID`, `amount`, `payment`, `dueBy`, `priority`, `priorityBonus`, `priorityDate`, `bulk`, `assignedID`) VALUES (NULL, ");

			temp = ftoa(theShipment->goodID, 0);
			strcat(sql, temp);
			strcat(sql, ", ");
			temp = ftoa(theShipment->sourceID, 0);
			strcat(sql, temp);
			strcat(sql, ", ");
			temp = ftoa(theShipment->destinationID, 0);
			strcat(sql, temp);
			strcat(sql, ", ");
			temp = ftoa(theShipment->amount, 2);
			strcat(sql, temp);
			strcat(sql, ", ");
			temp = ftoa(theShipment->payment, 2);
			strcat(sql, temp);

			strcat(sql, ", '");
			temp = ftoa(theShipment->dueBy.year, 0);
			strcpy(DateTime, temp);
			strcat(DateTime,"-");
			temp = ftoa(theShipment->dueBy.month, 0);
			strcat(DateTime, temp);
			strcat(DateTime, "-");
			temp = ftoa(theShipment->dueBy.day, 0);
			strcat(DateTime, temp);
			strcat(DateTime,"T");
			temp = ftoa(theShipment->dueBy.hour, 0);
			strcat(DateTime, temp);
			strcat(DateTime,":");
			temp = ftoa(theShipment->dueBy.minute, 0);
			strcat(DateTime, temp);
			strcat(DateTime, ":");
			temp = ftoa(theShipment->dueBy.second, 0);
			strcat(DateTime, temp);
			strcat(sql, DateTime);
			strcat(sql, "', ");

			strcpy(temp, (theShipment->priority) ? "TRUE":"FALSE");
			strcat(sql, temp);
			strcat(sql, ", ");
			temp = ftoa(theShipment->priorityBonus, 2);
			strcat(sql, temp);

			strcat(sql, ", '");
			temp = ftoa(theShipment->priorityDate.year, 0);
			strcpy(DateTime, temp);
			strcat(DateTime,"-");
			temp = ftoa(theShipment->priorityDate.month, 0);
			strcat(DateTime, temp);
			strcat(DateTime, "-");
			temp = ftoa(theShipment->priorityDate.day, 0);
			strcat(DateTime, temp);
			strcat(DateTime,"T");
			temp = ftoa(theShipment->priorityDate.hour, 0);
			strcat(DateTime, temp);
			strcat(DateTime,":");
			temp = ftoa(theShipment->priorityDate.minute, 0);
			strcat(DateTime, temp);
			strcat(DateTime, ":");
			temp = ftoa(theShipment->priorityDate.second, 0);
			strcat(DateTime, temp);
			strcat(sql, DateTime);
			strcat(sql, "', ");

			strcpy(temp, (theShipment->bulk) ? "TRUE":"FALSE");
			strcat(sql, temp);
			strcat(sql, ", NULL)");
			printf("\n%s\n", sql);

			if(mysql_query(conn, sql) != 0){
				printf("%s\n", mysql_error(conn));
				return 1;
			}

			/* Get the number of affected rows */
			affected_rows = mysql_affected_rows(conn);

			//Closing Connection
			closeDB();

			// Freeing memory
			free(sql);
			free(DateTime);

			if(affected_rows == 0){
				return 2;
			}
			else {
				return 0;
			}
			break;
	}
	return 0;
}

int duplicatShipment(int goodID, int sourceID, int destinationID, float amount){
	// This function check to see if the shipment is a duplicate

	//Initializing
	MYSQL_STMT *stmts;
	MYSQL_BIND param[4];
	char *SQL;
	int param_count;
	int retVal=10;


	//Creating Statement
	connectToDB();
	stmts = mysql_stmt_init(conn);
	if(!stmts) {
	  fprintf(stderr, " mysql_stmt_init(), out of memory\n");
	  return 1;
	}

	// Preparing Statement
	SQL = "SELECT * FROM `shipments` WHERE `goodID` = ? AND `sourceID` = ? AND `destinationID` = ? AND FORMAT(`amount`, 2) = ?";
	if(mysql_stmt_prepare(stmts, SQL, strlen(SQL))) {
	  fprintf(stderr, " mysql_stmt_prepare(), Destinations failed\n");
	  fprintf(stderr, " %s\n", mysql_stmt_error(stmts));
	  return 1;
	}

	//Binding Parameters
	param_count= mysql_stmt_param_count(stmts);

	/* validate parameter count */
	if(param_count != 4) {
	  fprintf(stderr, " invalid parameter count returned by MySQL\n");
	  return 1;
	}

	memset(param, 0, sizeof(param));
	param[0].buffer_type= MYSQL_TYPE_LONG;
	param[0].buffer= (char *)&goodID;
	param[0].is_null= 0;
	param[0].length= 0;

	param[1].buffer_type= MYSQL_TYPE_LONG;
	param[1].buffer= (char *)&sourceID;
	param[1].is_null= 0;
	param[1].length= 0;

	param[2].buffer_type= MYSQL_TYPE_LONG;
	param[2].buffer= (char *)&destinationID;
	param[2].is_null= 0;
	param[2].length= 0;

	param[0].buffer_type= MYSQL_TYPE_FLOAT;
	param[0].buffer= (char *)&amount;
	param[0].is_null= 0;
	param[0].length= 0;

	/* Bind the parameters */
	if(mysql_stmt_bind_param(stmts, param)) {
		fprintf(stderr, " mysql_stmt_bind_param() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmts));
		retVal = 1;
	}

	// Loading Shipments
	if(mysql_stmt_execute(stmts)) {
		fprintf(stderr, " mysql_stmt_execute(), failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmts));
		retVal = 1;
	}

	if(mysql_stmt_num_rows(stmts) > 0){
		retVal = 2;
	}

	// Closing Connection
	closeDB();

	// Return Value
	return retVal % 10;
}

int main(int argc, char **argv) {

	/************************ Initializing variables *************************/
	int i, j;								// Misc. Use
	int k;									// randomized number
	int maxBulkShipment;					// Max Bulk Shipment allowed
	int maxPriorityShipments;				// Max Priority Shipment allowed
	int maxNormalShipments;					// Max Normal Shipments allowed
	destinationShipments marketShipments;	//Shipment data for specified market


	/*************************** Main Program ***************************/
	// Seeding Randomizer
	srand(time(NULL));

	// Loading Settings
	printf("Loading Config.ini....");
	if(loadConfig()){
		exit(0);
	}
	printf("Done.\n");

	// Setting Shipment Maximums
	maxBulkShipment = round(MAX_SHIPMENTS_PER_DESTINATION * BULK_SHIPMENTS);
	maxPriorityShipments = round(MAX_SHIPMENTS_PER_DESTINATION * PRIORITY_SHIPMENTS);
	maxNormalShipments = round(MAX_SHIPMENTS_PER_DESTINATION * NORMAL_SHIPMENTS);

	// Connecting to DB
	printf("Connecting to DB...");
	if(connectToDB()){
		exit(0);
	}
	printf("Done.\n");

	// Loading Destinations
	printf("Loading Destinations...");
	loadDestinations();
	printf("Done.\n");

	// Loading Goods
	printf("Loading goods...");
	loadGoods();
	printf("Done.\n");

	// Loading Markets
	printf("Loading Markets...");
	if(loadMarkets()){
		exit(0);
	}
	printf("Done.\n");

	// Removing all shipments that have expired.
	printf("Removing Expired Shipments...");
	char *SQL = "DELETE FROM `shipments` WHERE ((ISNULL(`assignedID`)) OR (`assignedID`=0)) AND (`dueBy` < NOW());";
	mysql_query(conn, SQL);
	printf("Done.\n");

	printf("Cycling through all markets and checking total shipments.\n");
	/**** Checking to see if each destination has their max number of shipments ***/
	for(i=0; i< numberOfDestinations; i++){

		// Loading Shipments for the current market
		marketShipments = totalShipments((long)destinations[i].destinationID);

		printf("Checking total shipments...");
		// Checking to see if the maximum of shipments has been reached
		if(marketShipments.rows < MAX_SHIPMENTS_PER_DESTINATION){
			printf("\nShipments not maxed. Adding new shipments.\n");
			// Not maxed out, create necessary shipments
			struct shipment Shipment;

			MYSQL_TIME MYSQLDateTime;


			// Setting common value
			Shipment.sourceID = destinations[i].destinationID;

			// Have Priority shipments maxed out
			if(marketShipments.priority < maxPriorityShipments){
				// Creating Priority Shipments

				// Initializing Shipment
				init_shipment(&Shipment);

				for(j=0; j < (maxPriorityShipments - marketShipments.priority); j++){
					printf("Adding priority shipment...");
					// Picking Random Destination
					k = (rand() % numberOfDestinations);
					// Re-picking destination until it's different than current
					// location
					while(k == i){
						k = (rand() % numberOfDestinations);
					}
					//Getting current Time
					time_t current = time(NULL);
					struct tm *ptr = localtime(&current);

					// Setting Shipment data
					Shipment.destinationID = destinations[k].destinationID;
					Shipment.goodID = goodsID[rand() % numberOfGoods];
					Shipment.amount = ((float)rand()/(float)RAND_MAX) * 5;
					Shipment.amount = d_round(Shipment.amount, 2);
					Shipment.priority = TRUE;
					Shipment.payment = (Shipment.amount * 1000) * goodPrice(Shipment.goodID, Shipment.destinationID);

					// Calculating Priority Due By
					ptr->tm_hour += 6;
					mktime(ptr);
					MYSQLDateTime.day    = ptr->tm_mday;
					MYSQLDateTime.month  = ptr->tm_mon + 1;
					MYSQLDateTime.year   = ptr->tm_year + 1900;
					MYSQLDateTime.hour   = ptr->tm_hour;
					MYSQLDateTime.minute = ptr->tm_min;
					MYSQLDateTime.second = ptr->tm_sec;

					Shipment.priorityDate = MYSQLDateTime;

					// Calculating Due By
					ptr->tm_hour += 6;
					mktime(ptr);
					MYSQLDateTime.day    = ptr->tm_mday;
					MYSQLDateTime.month  = ptr->tm_mon + 1;
					MYSQLDateTime.year   = ptr->tm_year + 1900;
					MYSQLDateTime.hour   = ptr->tm_hour;
					MYSQLDateTime.minute = ptr->tm_min;
					MYSQLDateTime.second = ptr->tm_sec;
					Shipment.dueBy = MYSQLDateTime;

					float bonusRate = ((rand() % 25) + 1);

					while(bonusRate<= 0){
						bonusRate = ((rand() % 25) + 1);
					}

					Shipment.priorityBonus = Shipment.payment * (bonusRate/100);

					// Saving Shipment
					switch(insert_shipment(&Shipment)) {
						case 1:
							exit(0);
							break;
						case 2:
							j--;
							break;
						default:
							break;
					}
					printf("Done.\n");
				}

			}

			// Have Bulk shipments maxed out?
			if(marketShipments.bulk < maxBulkShipment){
				// Creating Bulk Shipments

				// Initializing Shipment
				init_shipment(&Shipment);

				for(j=0; j < (maxBulkShipment - marketShipments.bulk); j++){
					printf("Adding Bulk shipment...");
					// Initializing Shipment
					init_shipment(&Shipment);

					// Picking Random Destination
					k = (rand() % numberOfDestinations);
					// Re-picking destination until it's different than current
					// location
					while(k == i){
						k = (rand() % numberOfDestinations);
					}
					//Getting current Time
					time_t current = time(NULL);
					struct tm *ptr = localtime(&current);

					// Setting Shipment data
					Shipment.destinationID = destinations[k].destinationID;
					Shipment.goodID = goodsID[rand() % numberOfGoods];
					Shipment.amount = ((float)rand()/(float)RAND_MAX) * 5;
					Shipment.amount = d_round(Shipment.amount, 2);
					Shipment.bulk = TRUE;
					Shipment.payment = (Shipment.amount * 1000) * goodPrice(Shipment.goodID, Shipment.destinationID);

					// Calculating Due By
					ptr->tm_hour += 24;
					mktime(ptr);
					MYSQLDateTime.day    = ptr->tm_mday;
					MYSQLDateTime.month  = ptr->tm_mon + 1;
					MYSQLDateTime.year   = ptr->tm_year + 1900;
					MYSQLDateTime.hour   = ptr->tm_hour;
					MYSQLDateTime.minute = ptr->tm_min;
					MYSQLDateTime.second = ptr->tm_sec;
					Shipment.dueBy = MYSQLDateTime;

					// Saving Shipment
					switch(insert_shipment(&Shipment)) {
						case 1:
							exit(0);
							break;
						case 2:
							j--;
							break;
						default:
							break;
					}
					printf("Done.\n");
				}
			}

			// Have Normal shipments maxed out
			if(marketShipments.normal < maxNormalShipments){
				// Creating Normal Shipments

				// Initializing Shipment
				init_shipment(&Shipment);

				for(j=0; j < (maxNormalShipments - marketShipments.normal); j++){
					printf("Adding Normal shipment...");
					// Initializing Shipment
					init_shipment(&Shipment);

					// Picking Random Destination
					k = (rand() % numberOfDestinations);
					// Re-picking destination until it's different than current
					// location
					while(k == i){
						k = (rand() % numberOfDestinations);
					}
					//Getting current Time
					time_t current = time(NULL);
					struct tm *ptr = localtime(&current);

					// Setting Shipment data
					Shipment.destinationID = destinations[k].destinationID;
					Shipment.goodID = goodsID[rand() % numberOfGoods];
					Shipment.amount = ((float)rand()/(float)RAND_MAX) * 5;
					Shipment.amount = d_round(Shipment.amount, 2);
					Shipment.payment = (Shipment.amount * 1000) * goodPrice(Shipment.goodID, Shipment.destinationID);

					// Calculating Due By
					ptr->tm_hour += 12;
					mktime(ptr);
					MYSQLDateTime.day    = ptr->tm_mday;
					MYSQLDateTime.month  = ptr->tm_mon + 1;
					MYSQLDateTime.year   = ptr->tm_year + 1900;
					MYSQLDateTime.hour   = ptr->tm_hour;
					MYSQLDateTime.minute = ptr->tm_min;
					MYSQLDateTime.second = ptr->tm_sec;
					Shipment.dueBy = MYSQLDateTime;

					// Saving Shipment
					switch(insert_shipment(&Shipment)) {
						case 1:
							exit(0);
							break;
						case 2:
							j--;
							break;
						default:
							break;
					}
					printf("Done.\n");
				}
			}
		}
	}

	printf("Clearing Memory...");
	// Clearing memory
	mysql_free_result(result);
	iniparser_freedict(settings);
	free(destinations);
	free(markets);

	printf("Done.\n");

	return 0;
}
