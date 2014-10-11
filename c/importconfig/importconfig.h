/*
 * importconfig.h
 *
 *  Created on: Jul 25, 2012
 *      Author: Eleazar Castellanos
 * Description: This header contains functions for importing the
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

#ifndef IMPORTCONFIG_H_
#define IMPORTCONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/********************************* Dependencies ******************************/
#ifndef _STDIO_H
# include <stdio.h>
#endif

// Getting Config loader
#ifndef _INIPARSER_H_
#include "iniparser.h"
#endif

/*************************** Initializing variables **************************/
dictionary *settings;				// Variable to store configurations
int MAX_SHIPMENTS_PER_DESTINATION;	// The Maximum number of shipments per
									// Destination
float BULK_SHIPMENTS;				// Percentage of shipments that are Bulk
									// haul
float PRIORITY_SHIPMENTS;			// Percentage of shipments that are
									// Priority haul
float NORMAL_SHIPMENTS;				// Percentage of shipments that are Normal
									// haul
float BULK_RATE;					// Rate of sale for bulk shipments
float BULK_MARKUP;					// Markup for Bulk travel
float NORMAL_MARKUP;				// Markup for Normal travel
float PRIORITY_MARKUP;				// Markup for Priority travel
int SYSTEM_DESTINATIONS;			// Total Number of destination in the
									// System
int MAX_PASSENGERS_PER_SYSTEM;		// The Maximum number of passengers per
									// System
int TOTAL_FIRST_NAME;				// Total Number of First Names
int TOTAL_LAST_NAME;				// Total Number of Last Names
float NORMAL_TRAVEL;				// Percentage of Normal Travel
float PRIORITY_TRAVEL;				// Percentage of Priority Travel
float BULK_TRAVEL;					// Percentage of Bulk Travel
float COST_PER_HOP;					// Price per hop of travel
int TICKS_TO_RESERVE_FOR;			// Tick a system should reserve goods for

/************************* MYSQL Variables ***********************************/
MYSQL *conn;					// MYSQL Connections
MYSQL_RES *result;				// MYSQL Query results
MYSQL_ROW row;					// MYSQL Row return
my_ulonglong totalRows;			// Variable to Store Total Returned
my_ulonglong  affected_rows;	// Variable to Store Affected Rows
int num_fields;					// Number of fields
char *Server;					// MYSQL Server
char *UserName;					// MYSQL Username
char *Password;					// MYSQL Username Password
char *Database;					// MYSQL Database to use


/************************** Prototypes ***************************************/
int	 loadConfig(void);

#endif /* IMPORTCONFIG_H_ */
