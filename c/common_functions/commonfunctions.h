/*
 * commonfunctions.h
 *
 *  Created on: Jul 27, 2012
 *      Author: Eleazar Castellanos
 * Description: This header contains common functions  used by the server-side
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

#ifndef COMMONFUNCTION_H_
#define COMMONFUNCTION_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************************** Dependencies **********************/
#ifndef _STDIO_H
# include <stdio.h>
#endif

#ifndef _global_h
#include <my_global.h>
#endif

#ifndef _mysql_h
#include <mysql.h>
#endif

#ifndef IMPORTCONFIG_H_
#include "importconfig.h"
#endif

#ifndef _MATH_H
#include <math.h>
#endif


/********************************** Structures *******************************/
struct market {
	int 	marketID;
	int 	goodID;
	float 	price;
	int		export;
	int		import;
};

struct destination {
	int destinationID;
	int Export1;
	int	Export2;
	int Export3;
	int Export4;
	int Import1;
	int Import2;
	int Import3;
	int Import4;
};

struct shipment {
	int 		goodID;
	int 		sourceID;
	int 		destinationID;
	float 		amount;
	float 		payment;
	MYSQL_TIME 	dueBy;
	int			priority;
	float 		priorityBonus;
	MYSQL_TIME 	priorityDate;
	int 		bulk;
};

typedef struct {
	my_ulonglong rows;
	int 		 priority;
	int 		 bulk;
	int 		 normal;
} destinationShipments;

/************************ Initializing variables *****************************/
struct destination *destinations;	// Pointer to store array with
									// Destination data
int *goodsID;						// Pointer to store array with goodID
struct market *markets;				// Pointer to store array with Market data
int numberOfDestinations;			// Number of entries in the Destination
									// array
int numberOfGoods;					// Number of entries in the Goods array
int *SystemHops;					// Pointer to store System Hop array


/***************************** Prototypes ************************************/
int	connectToDB(void);						// Creates connection to DB
void closeDB(void);							// Closes connection to DB
float 	goodPrice(int, int);				// Returns the price of the
											// specified for the specified
											// system
void  	loadDestinations(void);				// Loads All Available Destinations
void 	loadGoods(void);					// Loads all Available Goods
int		loadMarkets(void);					// Loads All Markets and their data
void 	init_shipment(struct shipment *);	// Initiates the Shipment Object
void	init_markets(struct market *);		// Initiates the Market object
double 	d_round(double ,int);				// Rounds up provided value to the
											// specified decimal place
char 	*addDecimal(char *, int);			// Adds a decimal point to the
											// provided string at the specified
											// location.
char 	*Mid(char *, size_t, int);			// Returns the specified substring
char	*Right(char *, int);				// Returns the n-characters starting
											// from the right.
char	*Left(char *, int);					// Retunrs n-characters starting
											// from the left.
char	*ftoa(float, int);					// Converts a float to string

// Returns the total number of shipments for the specified system.
destinationShipments	totalShipments(long);

#endif
