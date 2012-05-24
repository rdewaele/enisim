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

/* The rotor system is somewhat prototype-based. The intention is to copy the
 * elements needed, and manipulate those copies in the simulation. This caters
 * to multiple instances of enigma machines. */

#include "rotors.h"

#include <stdio.h>

// remember:
// * explicitely uninitialized fields are initialized with zero
// * 'char foo[3] = "FOO";' is somewhat esoteric, but valid standard C
static const struct enigmaRotor const enigmaRotors[] = {
	[I]      = {"Walze I",             "EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q"},
	[II]     = {"Walze II",            "AJDKSIRUXBLHWTMCQGZNPYFVOE", "E"},
	[III]    = {"Walze III",           "BDFHJLCPRTXVZNYEIWGAKMUSQO", "V"},
	[IV]     = {"Walze IV",            "ESOVPZJAYQUIRHXLNFTGKDCMWB", "J"},
	[V]      = {"Walze V",             "VZBRGITYUPSDNHLXAWMJQOFECK", "Z"},
	[VI]     = {"Walze VI",            "JPGVOUMFYQBENHZRDKASXLICTW", "MZ"},
	[VII]    = {"Walze VII",           "NZJHGRCXMYSWBOUFAIVLPEKQDT", "MZ"},
	[VIII]   = {"Walze VIII",          "FKQHTLXOCBJSPDZRAMEWNIUYGV", "MZ"},
	[BETA]   = {"Walze Beta",          "LEYJVCNIXWPBQMDRTAKZGFUHOS"},
	[GAMMA]  = {"Walze Gamma",         "FSOKANUERHMBTIYCWLQPZXVGJD"},
	[UKW_B]  = {"Umkehrwalze B",       "YRUHQSLDPXNGOKMIEBFZCWVJAT"},
	[UKW_C]  = {"Umkehrwalze C",       "FVPJIAOYEDRZXWGCTKUQSBNMHL"},
	[UKW_BT] = {"Umkehrwalze B, thin", "ENKQAUYWJICOPBLMDXZVFTHRGS"},
	[UKW_CT] = {"Umkehrwalze C, thin", "RDOBJNTKVEHMLFCWZAXGYIPSUQ"},
	/* The Steckerbrett is technically not a rotor, but it can perfectly be
	 * modelled as one: it does not rotate, and the wirings can be modified.
	 * Note that the Steckerbrett does not translate characters by default
	 * (no cables). For consistency with the other representations, it is still
	 * manually initialized. I double-checked it for errors, I promise! */
	[SB]     = {"Steckerbrett",        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
};

void printEnigmaRotors(void) {
	const size_t eNum = sizeof(enigmaRotors) / sizeof(struct enigmaRotor);

	for (unsigned i = 0; i < eNum; ++i) {
		printf("%s:\n|", enigmaRotors[i].name);
		for (unsigned j = 0; j < sizeof(((struct enigmaRotor *)0)->wiring); ++j) {
			printf(" %c->%c |", 'A' + j, enigmaRotors[i].wiring[j]);
		}
		printf("\n\n");
	}
}

struct enigmaRotor selectEnigmaRotor(enum rotorID ID) {
	return enigmaRotors[ID];
}
