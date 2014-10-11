/*
 * passengers.c
 *
 *  Created on: Aug 8, 2012
 *      Author: Eleazar Castellanos
 * Description: This program randomly creates passengers for all stations.
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

/***************************** Global Variables ******************************/
char *FirstName;	// Array of First Names
char *LastName;		// Array of Last Names

/***************************** Structures ***********************************/
typedef struct {
	int DestinationID;	// System ID
	int Total;			// Total Travelers
	int Normal;			// Number of Normal Travel
	int Priority;		// Number of Priority Travel
	int Bulk;			// Number of Bulk Travel
} destinationTravelers;

/********************************** Prototypes *******************************/
int main(void);
int loadSystemHops(void);
int loadPassengers(void);
int insertTraveler(char *, int, int, int, int, int, float);
float travelPrice(int, int);

destinationTravelers totalTravelers(long);

/********************************* Functions *********************************/
int loadSystemHops(void) {
// This function will load the System Hop array that will be used to calculate the cost
// to travel between systems.

	// Initializing
	FILE *fp = fopen("systemhopmatrix.txt", "r");


	// Checking to see if System Hop Raw data was loaded.
	if(fp != NULL) {
		// Initializing
		char SYSTEM_HOPS_STRING[((SYSTEM_DESTINATIONS * (SYSTEM_DESTINATIONS + (SYSTEM_DESTINATIONS - 1))) + 2)];
		char line[128];
		char *ptrLine = line;
		char *element;
		int row, col;

		// Loading Matrix
		strcpy(SYSTEM_HOPS_STRING, "\0");
		while(fgets(line, sizeof(line), fp) != NULL){
			if(strncmp(line, "#", 1) != 0){
				strcat(SYSTEM_HOPS_STRING, Left(ptrLine, (strlen(ptrLine) - 1)));
				strcat(SYSTEM_HOPS_STRING, ",");
			}
		}

		fclose(fp);

		strcpy(SYSTEM_HOPS_STRING, Left(SYSTEM_HOPS_STRING, (strlen(SYSTEM_HOPS_STRING) - 1)));

		// Allocating memory to store array
		SystemHops = malloc((pow(SYSTEM_DESTINATIONS,2)) * sizeof(SystemHops));


		// Parsing System Array Raw Data

		// Creating text array from string
		element = strtok(SYSTEM_HOPS_STRING, ",");

		// Loading values to array
		row = col = 0;
		while(element != NULL) {
			// Loading current value
			SystemHops[((SYSTEM_DESTINATIONS * row) + col)] = atoi(element);
			// Loading Next value
			element = strtok(NULL, ",");

			// Incrementing counters
			if(++col == numberOfDestinations){
				col = 0;
				row++;
			}
		}

		return 0;
	}
	else {
		printf("Could not load System hops matrix.\n");
		return 1;
	}

}

int loadPassengers(void) {
// This function will create the Passenger Name matrix

	// Initializing
	FILE *fp;
	int i = 0;
	char line[32];
	FirstName = (char *)malloc(TOTAL_FIRST_NAME * sizeof(char)* 32);
	LastName = (char *)malloc(TOTAL_LAST_NAME * sizeof(char)* 32);

	// Loading First And Last Name Array

	// Opening First Name File
	fp = fopen("fnames.txt", "r");
	if(fp == NULL){
		printf("\nCould not load First Name Matrix.\n");
		return 1;
	}

	// Reading First Name from the File
	while(fgets(line, sizeof(line), fp) != NULL){

		// Storing into Array
		strcpy(&FirstName[(32 * i)], Left(line, (strlen(line) - 1)));

		// Ensuring we do not run out of memory
		if(++i == TOTAL_FIRST_NAME){
			break;
		}
	}


	// Closing File
	fclose(fp);

	// Opening Last Name File
	fp = fopen("lnames.txt", "r");
	if(fp == NULL){
		printf("\nCould not load Last Name Matrix.\n");
		return 1;
	}

	// Reading First Name from the File and storing it in Array
	i = 0;
	while(fgets(line, sizeof(line), fp) != NULL){

		// Storing into Array
		strcpy(&LastName[(32 * i)], Left(line, (strlen(line) - 1)));

		// Ensuring we do not run out of memory
		if(++i == TOTAL_LAST_NAME){
			break;
		}
	}

	// Closing File
	fclose(fp);

	return 0;
}

destinationTravelers totalTravelers(long SystemID){
	// Initializing
	destinationTravelers SystemData;
	MYSQL_STMT *stmt;
	MYSQL_BIND param[1], bindS[2];
	char *SQL;
	int param_count;
	int bBulk;
	int bPriority;

	//Reset connection to DB
	closeDB();
	if(connectToDB()){
		exit(0);
	}

	// Preparing statement
	printf("Preparing to determine total travelers for SystemID %li...\n", SystemID);

	//Creating Statement
	stmt = mysql_stmt_init(conn);
	if(!stmt) {
	  fprintf(stderr, " mysql_stmt_init(), out of memory\n");
	  exit(0);
	}

	// Preparing Statement
	SQL = "SELECT `priority`, `bulk` FROM `passengers` WHERE `Departing`=?";
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
	param[0].buffer= (char *)&SystemID;
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

	printf("Loading System...");
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
	SystemData.Total = mysql_stmt_num_rows(stmt);
	SystemData.Bulk = 0;
	SystemData.Normal = 0;
	SystemData.Priority = 0;
	SystemData.DestinationID = SystemID;

	// Cycling through Shipments and counting their types
	while (mysql_stmt_fetch(stmt) == 0) {
		// Is shipment Priority
		if(bPriority){
			// It is, increase counter
			SystemData.Priority++;
		}
		// Is shipment Bulk
		else if(bBulk) {
			// It is, increase counter
			SystemData.Bulk++;
		}
		// shipment is Normal
		else {
			SystemData.Normal++;
		}
	}

	// Closing connection to DB
	closeDB();

	return SystemData;
}

int insertTraveler(char *PassengerName, int Departing, int Destination, int HoursTillDue, int Priority, int Bulk, float travelPrice){
// This function inserts the specified traveler

	//Initializing Variables
	char *sql = (char*)malloc(sizeof(char) * 1024);
	char *DateTime = (char*)malloc(sizeof(char) * 20);
	char *temp;

	// Connecting to DB
	if(connectToDB()){
		return 1;
	}

	// Preparing statement
	strcpy(sql, "INSERT INTO `passengers` (`ID`, `PassengerName`, `Departing`, `Destination`, `DueBy`, `priority`, `bulk`, `Payment`, `AssignedID`) VALUES (NULL, '");

	strcat(sql, PassengerName);
	strcat(sql, "', ");
	temp = ftoa(Departing, 0);
	strcat(sql, temp);
	strcat(sql, ", ");
	temp = ftoa(Destination, 0);
	strcat(sql, temp);
	strcat(sql, ", '");

	//Getting current Time
	time_t current = time(NULL);
	struct tm *ptr = localtime(&current);

	ptr->tm_hour += HoursTillDue;
	mktime(ptr);
	temp = ftoa((ptr->tm_year + 1900), 0);
	strcpy(DateTime, temp);
	strcat(DateTime,"-");
	temp = ftoa((ptr->tm_mon + 1), 0);
	strcat(DateTime, temp);
	strcat(DateTime, "-");
	temp = ftoa(ptr->tm_mday, 0);
	strcat(DateTime, temp);
	strcat(DateTime,"T");
	temp = ftoa(ptr->tm_hour, 0);
	strcat(DateTime, temp);
	strcat(DateTime,":");
	temp = ftoa(ptr->tm_min, 0);
	strcat(DateTime, temp);
	strcat(DateTime, ":");
	temp = ftoa(ptr->tm_sec, 0);
	strcat(DateTime, temp);
	strcat(sql, DateTime);
	strcat(sql, "', ");

	strcpy(temp, (Priority) ? "TRUE":"FALSE");
	strcat(sql, temp);
	strcat(sql, ", ");
	strcpy(temp, (Bulk) ? "TRUE":"FALSE");
	strcat(sql, temp);
	strcat(sql, ", ");

	temp = ftoa(travelPrice, 2);
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
		return 1;
	}
	else {
		return 0;
	}

	return 0;
}

float travelPrice(int Departing, int Destination){
// This function return the cost to travel between the specified systems.
	return (COST_PER_HOP * SystemHops[((SYSTEM_DESTINATIONS * (Departing - 1)) + (Destination - 1))]);
}
int main(void) {
	// Initializing Variables
	int i,j,k;	// Misc. counter
	int MaxNormal, MaxPriority, MaxBulk; // Maximum number of travelers per type
	int Departing, Destination; // System IDs
	float theTravelPrice;	// Price to travel to specified System
	char *PassengerName = (char *)malloc(sizeof(char) * 255); // Name of passenger
	destinationTravelers theTravelers;

	/*************************** Main Program ***************************/
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

	// Loading System Hop Matrix
	printf("Loading System Hop Matrix...");
	if(loadSystemHops()){
		exit(0);
	}
	printf("Done.\n");

	// Loading Passenger List
	printf("Loading Passenger Matrix...");
	if(loadPassengers()){
		exit(0);
	}
	printf("Done.\n");

	// Loading Destinations
	printf("Loading Destinations...");
	loadDestinations();
	printf("Done.\n");

	// Removing all shipments that have expired.
	printf("Removing Expired Travel Requests...");
	char *SQL = "DELETE FROM `passengers` WHERE ((ISNULL(`AssignedID`)) OR (`AssignedID`=0)) AND (`dueBy` < NOW());";
	mysql_query(conn, SQL);
	printf("Done.\n");

	// Setting Maximum Traveler Types
	MaxNormal = round(MAX_PASSENGERS_PER_SYSTEM * NORMAL_TRAVEL);
	MaxPriority = round(MAX_PASSENGERS_PER_SYSTEM * PRIORITY_TRAVEL);
	MaxBulk = round(MAX_PASSENGERS_PER_SYSTEM * BULK_TRAVEL);

	printf("Cycling through all Systems and checking total travelers.\n");
	/**** Checking to see if each system has their max number of travelers ***/
	for(i=0; i< numberOfDestinations; i++){

		// Loading Shipments for the current market
		theTravelers = totalTravelers((long)destinations[i].destinationID);

		// Checking to see if system has maximum travelers
		if(theTravelers.Total < MAX_PASSENGERS_PER_SYSTEM){
			printf("Travelers not maxed out in this system.\n");

			// Not maxed out, create necessary travelers

			// Creating Priority
			for(j=0;j<(MaxPriority - theTravelers.Priority);j++){
				strcpy(PassengerName, &FirstName[(32 * (rand() % TOTAL_FIRST_NAME))]);
				strcat(PassengerName, " ");
				strcat(PassengerName, &LastName[(32 * (rand() % TOTAL_LAST_NAME))]);

				// Picking Random Destination
				k = (rand() % numberOfDestinations);
				// Re-picking destination until it's different than current
				// location
				while(k == i){
					k = (rand() % numberOfDestinations);
				}
				// Setting Values
				Departing = destinations[i].destinationID;
				Destination = destinations[k].destinationID;
				theTravelPrice = (travelPrice(Departing, Destination) * PRIORITY_MARKUP);

				// Saving Traveler
				if(insertTraveler(PassengerName, Departing, Destination, 6, TRUE, FALSE, theTravelPrice)){
					j--;
				}
			}

			// Creating Bulk
			for(j=0;j<(MaxBulk - theTravelers.Bulk);j++){
				strcpy(PassengerName, &FirstName[(32 * (rand() % TOTAL_FIRST_NAME))]);
				strcat(PassengerName, " ");
				strcat(PassengerName, &LastName[(32 * (rand() % TOTAL_LAST_NAME))]);

				// Picking Random Destination
				k = (rand() % numberOfDestinations);
				// Re-picking destination until it's different than current
				// location
				while(k == i){
					k = (rand() % numberOfDestinations);
				}
				// Setting Values
				Departing = destinations[i].destinationID;
				Destination = destinations[k].destinationID;
				theTravelPrice = (travelPrice(Departing, Destination) * BULK_MARKUP);

				// Saving Traveler
				if(insertTraveler(PassengerName, Departing, Destination, 24, FALSE, TRUE, theTravelPrice)){
					j--;
				}
			}

			// Creating Normal
			for(j=0;j<(MaxNormal - theTravelers.Normal);j++){
				strcpy(PassengerName, &FirstName[(32 * (rand() % TOTAL_FIRST_NAME))]);
				strcat(PassengerName, " ");
				strcat(PassengerName, &LastName[(32 * (rand() % TOTAL_LAST_NAME))]);

				// Picking Random Destination
				k = (rand() % numberOfDestinations);
				// Re-picking destination until it's different than current
				// location
				while(k == i){
					k = (rand() % numberOfDestinations);
				}
				// Setting Values
				Departing = destinations[i].destinationID;
				Destination = destinations[k].destinationID;
				theTravelPrice = (travelPrice(Departing, Destination) * NORMAL_MARKUP);

				// Saving Traveler
				if(insertTraveler(PassengerName, Departing, Destination, 12, TRUE, FALSE, theTravelPrice)){
					j--;
				}
			}// Normal Travels for()
		} // Max travlers IF
	} // Destination Cycle




	// Clearing Memory
	printf("Clearing Memory...");
	free(SystemHops);
	free(FirstName);
	free(LastName);
	free(PassengerName);
	printf("Done.\n");

	return 0;
}


