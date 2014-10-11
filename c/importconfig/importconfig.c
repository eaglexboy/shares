/*
 * importconfig.c
 *
 *  Created on: Jul 26, 2012
 *      Author: Eleazar Castellanos
 * Description: This file contains the functions for importing the
 * 				configuration file.
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
#include <my_global.h>
#include <mysql.h>
#include "importconfig.h"




int loadConfig(void){
	// Load Config file
	settings = iniparser_load("config.ini");

	// Checking to see if settings were loaded
	if (settings == NULL) {
		printf("Could not load config file.\n");
		return 1;
	}

	// MYSQL Config Data
	Server = iniparser_getstring(settings, "MYSQL:Server", NULL);
	if(Server == NULL) {
		printf("Could not load MYSQL Server information.\n");
		return 1;
	}

	// Loading MYSQL Username
	UserName = iniparser_getstring(settings, "MYSQL:UserName", NULL);
	if(UserName == 0) {
		printf("Could not load MYSQL Username information.\n");
		return 1;
	}

	// Loading MYSQL Username Password
	Password = iniparser_getstring(settings, "MYSQL:Password", NULL);
	if(Password == 0) {
		printf("Could not load MYSQL Username Password.\n");
		return 1;
	}

	// Loading MYSQL Database
	Database = iniparser_getstring(settings, "MYSQL:Database", NULL);
	if(Database == 0) {
		printf("Could not load MYSQL Database name.\n");
		return 1;
	}


	// Storing Shipment Values
	MAX_SHIPMENTS_PER_DESTINATION = iniparser_getint(settings, "Shipments:MaxShipmentsPerDestination", 0);
	BULK_SHIPMENTS = iniparser_getdouble(settings, "Shipments:BulkShipments", 0.1);
	PRIORITY_SHIPMENTS = iniparser_getdouble(settings, "Shipments:PriorityShipments", 0.2);
	NORMAL_SHIPMENTS = iniparser_getdouble(settings, "Shipments:NormalShipments", 0.7);
	BULK_RATE = iniparser_getdouble(settings, "Shipments:BulkRate", 0.9);

	// Storing Passenger Values
	MAX_PASSENGERS_PER_SYSTEM = iniparser_getint(settings, "Passenger:MaxPassengerPerSystem", 30);
	TOTAL_FIRST_NAME = iniparser_getint(settings, "Passenger:TotalFirstName", 5500);
	TOTAL_LAST_NAME = iniparser_getint(settings, "Passenger:TotalLastName", 8000);
	BULK_MARKUP = iniparser_getdouble(settings, "Passenger:BulkMarkup", 0.9);
	NORMAL_MARKUP = iniparser_getdouble(settings, "Passenger:NormalMarkup", 1.0);
	PRIORITY_MARKUP = iniparser_getdouble(settings, "Passenger:PriorityMarkup", 1.25);
	NORMAL_TRAVEL = iniparser_getdouble(settings, "Passenger:NormalTravel", 0.7);
	PRIORITY_TRAVEL = iniparser_getdouble(settings, "Passenger:PriorityTravel", 0.25);
	BULK_TRAVEL = iniparser_getdouble(settings, "Passenger:BulkTravel", 1.25);
	COST_PER_HOP = iniparser_getdouble(settings, "Passenger:CostPerHop", 1.25);
	SYSTEM_DESTINATIONS = iniparser_getint(settings, "Passenger:SystemDestinations", 15);

	// System Globals
	TICKS_TO_RESERVE_FOR = iniparser_getint(settings, "System:TicksToReserveFor", 100);
	return 0;
}
