// Copyright (C) 2012 Robrecht Dewaele
//
// This file is part of enisim.
//
// enisim is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// enisim is distributed in the hope that it will be useful
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with enisim. If not, see <http://www.gnu.org/licenses/>.

#include "rotors.h"

#include <stdio.h>

// Structure to represent an Enigma rotor and its state
struct enigmaRotor {
	const char * description;
	char wiring[26];
	unsigned entry;
};

static const struct enigmaRotor const enigmaRotors[] = {
	{"Enigma Walze I",
		{'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'},
		0},
	{"Enigma Walze II",
		{'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
		0},
	{"Enigma Walze III",
		{'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
		0},
	{"Enigma Walze IV",
		{'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
		0},
	{"Enigma Walze V",
		{'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'},
		0},
	{"Enigma Walze VI",
		{'J','P','G','V','O','U','M','F','Y','Q','B','E','N','H','Z','R','D','K','A','S','X','L','I','C','T','W'},
		0},
	{"Enigma Walze VII",
		{'N','Z','J','H','G','R','C','X','M','Y','S','W','B','O','U','F','A','I','V','L','P','E','K','Q','D','T'},
		0},
	{"Enigma Walze VIII",
		{'F','K','Q','H','T','L','X','O','C','B','J','S','P','D','Z','R','A','M','E','W','N','I','U','Y','G','V'},
		0},
	{"Enigma Walze Beta",
		{'L','E','Y','J','V','C','N','I','X','W','P','B','Q','M','D','R','T','A','K','Z','G','F','U','H','O','S'},
		0},
	{"Enigma Walze Gamma",
		{'F','S','O','K','A','N','U','E','R','H','M','B','T','I','Y','C','W','L','Q','P','Z','X','V','G','J','D'},
		0},
	{"Enigma Umkehrwalze B",
		{'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'},
		0},
	{"Enigma Umkehrwalze C",
		{'F','V','P','J','I','A','O','Y','E','D','R','Z','X','W','G','C','T','K','U','Q','S','B','N','M','H','L'},
		0},
	{"Enigma Umkehrwalze B, thin",
		{'E','N','K','Q','A','U','Y','W','J','I','C','O','P','B','L','M','D','X','Z','V','F','T','H','R','G','S'},
		0},
	{"Enigma Umkehrwalze C, thin",
		{'R','D','O','B','J','N','T','K','V','E','H','M','L','F','C','W','Z','A','X','G','Y','I','P','S','U','Q'},
		0}
};

void printEnigmaRotors(void) {
	const size_t eNum = sizeof(enigmaRotors) / sizeof(struct enigmaRotor);
	for (unsigned i = 0; i < eNum; ++i) {
		printf("| ");
		for (unsigned j = 0; j < sizeof(((struct enigmaRotor *)0)->wiring); ++j) {
			printf(" %c->%c |", 'A' + j, enigmaRotors[i].wiring[j]);
		}
		printf("\n");
	}
}
