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
	I, II, III, IV, V, VI, VII, VIII, BETA, GAMMA, UKW_B, UKW_C, UKW_BT, UKW_CT,
	SB, ROTOR_IDS
};

// TODO further disambiguate and clarify what the wiring arrays exactly mean
// Structure to represent an Enigma rotor and its state
// (this structure assumes that input and output alphabets are of equal size)
#define ER_ABC_SZ 26
struct enigmaRotor {
	const char * name;
	// name to identify this rotor to the end user
	unsigned wiring[ER_ABC_SZ];
	unsigned wiring_inv[ER_ABC_SZ];
	unsigned rotation;
};

void printEnigmaRotors(void);

struct enigmaRotor selectEnigmaRotor(enum rotorID);
