// Copyright (C) 2012 Robrecht Dewaele
//
// This file is part of enisim.
//
// enisim is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// enisim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with enisim. If not, see <http://www.gnu.org/licenses/>.

#pragma once

enum rotorID {
	I,II,III,IV,V,VI,VII,VIII,BETA,GAMMA,UKW_B,UKW_C,UKW_BT,UKW_CT,SB
};

// TODO further disambiguate and clarify what the wiring arrays exactly mean
// Structure to represent an Enigma rotor and its state
// (this structure assumes that input and output alphabets are of equal size)
#define ER_ABC_SZ 26
struct enigmaRotor {
	// name to identify this rotor to the end user
	const char * name;
	// target alphabet in the alphabetical order of the source characters
	char wiring[ER_ABC_SZ];
	// turnover: represents ring character, i.e. index in the wiring table
	// (Walzes 6, 7 and 8 have two turnovers, anything else none or just one)
	char turnover[2];
	// rotation step of the rotor (0 - 25)
	unsigned rotation;
	// position of the ring (important for turnovers) (0 - 25)
	unsigned ringpos;

	// inverse of the wiring table (can be calculated)
	char wiring_inv[ER_ABC_SZ];
};


void printEnigmaRotors(void);

struct enigmaRotor selectEnigmaRotor(enum rotorID);
