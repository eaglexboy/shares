/*
 * economy.h
 *
 *  Created on: Aug 9, 2012
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

#ifndef ECONOMY_H_
#define ECONOMY_H_

/********************************** Dependencies *******************************/

/********************************** Structures ********************************/
typedef struct {
	int goodID;	// GoodID
	float rate; // production/consumption Rate
} goodRate;

typedef struct{
	int systemID;	// System's ID
	int pop;		// System's Population
	int workPop;	// System's Working population
	float funds;	// System's Funds
	float taxes;	// System's Tax collection per Working Citizen.
} systemDemographics;

typedef struct{
	int workers;
	float cost;
} production;

/***************************** Variable Declaration **************************/
goodRate *consumptionRate;				// pointer for consumption Rate Array
goodRate *productionRate;				// pointer for production Rate Array
goodRate *productionFactor;				// pointer for production factor Array
float WorkforceEmploymentCost;			// The cost to product a good per
										// worker

/********************************** Prototypes ******************************/
int 	main(void);							// Main function
int 	loadRates(void);					// Function loads Consumption/
											// Production Rates
float 	WEC(int);							// Calculates Workforce Employment
											// Cost
float 	productionFactorForGood(int);		// Returns the Good's Production
											// Factor
float	productionRateForGood(int);			// Returns the Good's Production
											// Rate
int		importsGood(int, int);				// Returns whether the System
											// Imports the good
int		exportsGood(int, int);				// Returns whether the System
											// Exports the good
void 	updateStock(int, int, int);			// Saves the produced amount into
											// the DB
float 	calculateProductionCost(int, int);	// This function calculates the cost
											// to produce one unit of a the
											// specified Good
float 	consumptionRateForGood(int);		// Returns the Rate of consumption
											// for the specified good in the
											// specified system
float 	stockLevel(int, int);				// Returns stocks current level
void	updatePrice(int, int, float);		// Store New sell price for the good
											// in the specified system
void 	updateTaxes(int, int);				// Updates System's Tax Collection
											// Amount
// Store System's Demographic Data
void 	updateDemographics(systemDemographics);
// Loads the demographic data for the specified system
systemDemographics loadSystemDemographics(int);
production produceGood(int, int, int);		// Produces resource for specified
											// market



#endif /* ECONOMY_H_ */
