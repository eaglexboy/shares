/*
 * commonfunctions.c
 *
 *  Created on: Jul 27, 2012
 *      Author: Eleazar Castellanos
 * Description: This file contains the common functions used by the server-side
 * 				applications.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>
#include <math.h>
#include "commonfunctions.h"
#include "importconfig.h"

void loadDestinations(void){
	// Initializing local variables
	int i;

	/********* Loading Destinations ****/
	char *SQL = "SELECT `ID`, `Export1`, `Export2`, `Export3`, `Export4`, `Import1`, `Import2`, `Import3`, `Import4` FROM `destinations`";
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Storing total number of entries in Destination Array
	numberOfDestinations = totalRows;

	// Allocating memory for Destination Array
	destinations = malloc(numberOfDestinations * sizeof(struct destination));

	// Reseting temporary array pointer
	i=0;
	// Cycling through each Row
	while ((row = mysql_fetch_row(result))) {
		//Storing Destination ID in Array
		destinations[i].destinationID = atoi(row[0]);
		destinations[i].Export1 = atoi(row[1]);
		destinations[i].Export2 = atoi(row[2]);
		destinations[i].Export3 = atoi(row[3]);
		destinations[i].Export4 = atoi(row[4]);
		destinations[i].Import1 = atoi(row[5]);
		destinations[i].Import2 = atoi(row[6]);
		destinations[i].Import3 = atoi(row[7]);
		destinations[i].Import4 = atoi(row[8]);

		// Moving pointer to next locations
		i++;
	}
}

int connectToDB(void) {
	// Loading MYSQL Server

	// Connecting to DB
	conn = mysql_init(NULL);
	if(mysql_real_connect(conn, Server, UserName, Password, Database, 0, NULL, 0) == NULL){
		printf("\nCould not connect to the Server.\n");
		return 1;
	}

	return 0;
}

void loadGoods(void){
	// Initializing local variables
	int i;

	/**** Loading Goods ****/
	char *SQL = "SELECT `ID` FROM `goods`";
	mysql_query(conn, SQL);

	// Storing Query return
	result = mysql_store_result(conn);

	// Storing Total Rows
	totalRows = mysql_num_rows(result);

	// Storing total number of entries in Goods Array
	numberOfGoods = totalRows;

	// Allocating memory for Goods Array
	goodsID = malloc(numberOfGoods * sizeof(int));

	// Reseting temporary array pointer
	i=0;

	// Cycling through each Row
	while ((row = mysql_fetch_row(result))) {
		//Storing Good ID in Array
		goodsID[i] = atoi(row[0]);

		// Moving pointer to next locations
		i++;
	}
}

int loadMarkets(void){

	// Initializing Variables
	int maxMarkets = (numberOfDestinations * numberOfGoods);
	markets = malloc(maxMarkets * sizeof(struct market));
	MYSQL_STMT *stmt;
	MYSQL_BIND param[1], bindS[2];
	int goodID;
	float currentValue;
	int locationID;
	int param_count;
	char *SQL;
	int i, j;

	/******************* Loading Market Data *************************/

	//Creating Statement
	stmt = mysql_stmt_init(conn);
	if(!stmt) {
	  fprintf(stderr, " mysql_stmt_init(), out of memory\n");
	  return 1;
	}

	// Preparing Statement
	SQL = "SELECT `goodID`, `currentValue` FROM `markets` WHERE `locationID` = ?";
	if(mysql_stmt_prepare(stmt, SQL, strlen(SQL))) {
	  fprintf(stderr, " mysql_stmt_prepare(), Destinations failed\n");
	  fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
	  return 1;
	}

	//Binding Parameters
	param_count= mysql_stmt_param_count(stmt);

	/* validate parameter count */
	if(param_count != 1) {
	  fprintf(stderr, " invalid parameter count returned by MySQL\n");
	  return 1;
	}

	memset(bindS, 0, sizeof(bindS));
	memset(param, 0, sizeof(param));
	param[0].buffer_type= MYSQL_TYPE_LONG;
	param[0].buffer= &locationID;
	param[0].is_null= 0;
	param[0].length= 0;

	bindS[0].buffer_type= MYSQL_TYPE_LONG;
	bindS[0].buffer= &goodID;
	bindS[0].is_null= 0;
	bindS[0].length= 0;

	bindS[1].buffer_type= MYSQL_TYPE_FLOAT;
	bindS[1].buffer= &currentValue;
	bindS[1].is_null= 0;
	bindS[1].length= 0;


	/* Bind the parameters */
	if(mysql_stmt_bind_param(stmt, param)) {
		fprintf(stderr, " mysql_stmt_bind_param() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		return 1;
	}

	// Binding the Results
	if(mysql_stmt_bind_result(stmt, bindS)){
		fprintf(stderr, " mysql_stmt_bind_result() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		return 1;
	}

	// Market Array Pointer
	j=0;
	// Cycling through all markets
	for(i=0;i < numberOfDestinations; i++){
		locationID = destinations[i].destinationID;

		// Loading Shipments for the current market
		if(mysql_stmt_execute(stmt)) {
			fprintf(stderr, " mysql_stmt_execute(), failed\n");
			fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
			return 1;
		}

		// Saving to buffer
		if(mysql_stmt_store_result(stmt)){
			fprintf(stderr, " mysql_stmt_store_result(), failed\n");
			fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
			return 1;
		}



		// Cycling through markets
		while (mysql_stmt_fetch(stmt) == 0) {
			// Initiating Market Object
			init_markets(&markets[j]);

			//Saving Market data
			markets[j].marketID = locationID;
			markets[j].goodID = goodID;
			markets[j].price = currentValue;
			// Is this good Exported
			if((destinations[i].Export1 == goodID) || (destinations[i].Export2 == goodID) || (destinations[i].Export3 == goodID) || (destinations[i].Export4 == goodID)){
				markets[j].export = TRUE;
			}

			// Is this good Imported
			if((destinations[i].Import1 == goodID) || (destinations[i].Import2 == goodID) || (destinations[i].Import3 == goodID) || (destinations[i].Import4 == goodID)){
				markets[j].import = TRUE;
			}

			// Allocated memory reached?
			if(++j > (maxMarkets)){
				printf("Not Memory enough allocated for Markets.\n");
				break;
			}
		}

		// Have we maxed out of Memory
		if(j > maxMarkets){
			break;
		}
	}

	// Have we maxed out of Memory
	if(j > maxMarkets){
		return 1;
	}
	return 0;
}

float goodPrice(int goodID, int Destination){
	// This function finds the price of the specified good at the spedified
	// Locations.

	int i;

	//cycling through all of the markets
	for(i=0; i < (numberOfDestinations * numberOfGoods); i++){
		if(markets[i].marketID == Destination){
			if(markets[i].goodID == goodID){
				// Returning the price for the good
				return markets[i].price;
			}
		}
	}

	// Good not found, return 0
	return 0;
}

void init_markets(struct market * t){
	t->export = FALSE;
	t->import = FALSE;

}

void init_shipment(struct shipment *theShipment) {
	theShipment->priority = FALSE;
	theShipment->priorityBonus = 0;
	theShipment->priorityDate.day = NULL;
	theShipment->priorityDate.hour = NULL;
	theShipment->priorityDate.minute = NULL;
	theShipment->priorityDate.month = NULL;
	theShipment->priorityDate.second = NULL;
	theShipment->priorityDate.year = NULL;
	theShipment->bulk = FALSE;

}



double d_round(double in_d,int r2dec) {
	double d_whl=0,d_dec=0,d_last=0,d_rnd=0,d_rlst=0;
	int x, to_dec =10;
	for (x = 0; x<r2dec; x++){
		to_dec = to_dec*10;
	}
	d_whl = floor(in_d);
	d_dec = in_d - d_whl;
	d_dec = floor(d_dec*to_dec);
	d_last = floor(d_dec/10)*10;
	d_rnd = d_dec-d_last;
	if(d_rnd>=5)
	  d_rlst = d_whl + ((d_last+10)/to_dec);
	else
	  d_rlst = d_whl + (d_last/to_dec);
	return d_rlst;
}

char *addDecimal(char *str, int decimal){
	// This function adds a decimal into a string at the specified location
	// by decimal

	// Initializing
	size_t strLen = strlen(str);
	char *s = (char*)malloc(sizeof(char) * (strLen + 2));
	char *temp;

	if(decimal >= 0) {
		strncpy(s, str, decimal);
		strcpy((s + decimal), ".");
		temp = Right(str, (strLen - decimal));
		strcpy((s + decimal + 1), temp);

		return s;
	}
	else {
		return str;
	}
}

char *Mid(char *str, size_t start, int stop) {
// This function return the specified portion of the string provided

	// Initializing
	size_t strLen = strlen(str);
	char *s = (char*)malloc(sizeof(char) * (strLen + 1));

	// Extracting Substring
	strncpy(s, (str + start), (stop - start));

	strcpy((s + (stop - start + 1)), "\0");

	// Returning substring.
	return s;
}

char *Right(char *str, int length) {
// This function return the specified portion of the string provided

	// Initializing
	size_t strLen = strlen(str);
	char *s = (char*)malloc(sizeof(char) * (length + 1));

	// Extracting Substring
	strncpy(s, (str + (strLen - length)), length);

	strcpy((s + length), "\0");

	// Returning substring.
	return s;
}

char *Left(char *str, int length) {
// This function return the specified portion of the string provided

	// Initializing
	char *s = (char*)malloc(sizeof(char) * (length + 1));

	// Extracting Substring
	strncpy(s, str, length);

	strcpy((s + length), "\0");

	// Returning substring.
	return s;
}

char *ftoa(float value, int precision){
	char *buf;
	char *temp = (char*)malloc(sizeof(char) * 3);
	int decimal;
	int sign;
	//double _precision;

	buf = fcvt(value, precision, &decimal, &sign);
	if(precision > 0){
		buf = addDecimal(buf, decimal);
	}

	if(strlen(buf) == 1){
		strcpy(temp, "0");
		strcat(temp, buf);
		strcpy(buf, temp);
	}

	return buf;
}

void closeDB(void){
// This function closes the connection to the DB
	if(conn->user != NULL){
		mysql_close(conn);
	}
}

destinationShipments totalShipments(long sourceID){
// This function checks to see how many shipments exist for the specified
// Destination

	//Initializing Variables
	MYSQL_STMT *stmt;
	MYSQL_BIND param[1], bindS[2];
	char *SQL;
	int param_count;
	int bBulk;
	int bPriority;
	destinationShipments theReturn;

	//Reset connection to DB
	closeDB();
	connectToDB();

	// Preparing statement
	printf("Preparing to determine total shipments for sourceID %li...\n", sourceID);

	//Creating Statement
	stmt = mysql_stmt_init(conn);
	if(!stmt) {
	  fprintf(stderr, " mysql_stmt_init(), out of memory\n");
	  exit(0);
	}

	// Preparing Statement
	SQL = "SELECT `priority`, `bulk` FROM `shipments` WHERE `sourceID`=?";
	if(mysql_stmt_prepare(stmt, SQL, strlen(SQL))) {
	  fprintf(stderr, " mysql_stmt_prepare(), Destinations failed\n");
	  fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
	  exit(0);
	}

	//Binding Parameters
	param_count= mysql_stmt_param_count(stmt);
	/* validate parameter count */
	if(param_count != 1) {
	  fprintf(stderr, " invalid parameter count returned by MySQL\n");
	  exit(0);
	}
	printf("Done.\n");

	printf("Binding Variables...");
	memset(bindS, 0, sizeof(bindS));
	memset(param, 0, sizeof(param));

	bindS[0].buffer_type= MYSQL_TYPE_TINY;
	bindS[0].buffer= (char *)&bPriority;
	bindS[0].is_null= 0;
	bindS[0].length= 0;

	bindS[1].buffer_type= MYSQL_TYPE_TINY;
	bindS[1].buffer= (char *)&bBulk;
	bindS[1].is_null= 0;
	bindS[1].length= 0;

	param[0].buffer_type= MYSQL_TYPE_LONG;
	param[0].buffer= (char *)&sourceID;
	param[0].is_null= 0;
	param[0].length= 0;

	/* Bind the buffers */
	if(mysql_stmt_bind_param(stmt, param)) {
	  fprintf(stderr, " mysql_stmt_bind_param() failed\n");
	  fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
	  exit(0);
	}

	// Binding the Results
	if(mysql_stmt_bind_result(stmt, bindS)){
		fprintf(stderr, " mysql_stmt_bind_result() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}
	printf("Done.\n");

	printf("Loading Market...");
	if(mysql_stmt_execute(stmt)) {
		fprintf(stderr, "mysql_stmt_execute(), failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}
	// Saving to buffer
	if(mysql_stmt_store_result(stmt)){
		fprintf(stderr, " mysql_stmt_store_result(), failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	printf("Done.\n");

	// Storing Total Rows
	theReturn.rows = mysql_stmt_num_rows(stmt);
	theReturn.bulk = 0;
	theReturn.normal = 0;
	theReturn.priority = 0;

	// Cycling through Shipments and counting their types
	while (mysql_stmt_fetch(stmt) == 0) {
		// Is shipment Priority
		if(bPriority){
			// It is, increase counter
			theReturn.priority++;
		}
		// Is shipment Bulk
		else if(bBulk) {
			// It is, increase counter
			theReturn.bulk++;
		}
		// shipment is Normal
		else {
			theReturn.normal++;
		}
	}

	// Closing connection to DB
	closeDB();

	//Returning Result
	return theReturn;
}
