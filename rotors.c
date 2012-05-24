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
static const struct enigmaRotor_old const enigmaRotors_old[] = {
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
	 * modelled as one: it does not rotate, but the wirings can be modified.
	 * Note that the Steckerbrett does not translate characters by default
	 * (no cables). For consistency with the other representations, it is still
	 * manually initialized. I double-checked it for errors, I promise! */
	[SB]     = {"Steckerbrett",        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
};

static const struct enigmaRotor const enigmaRotors[] = {
	[I] = 
	{"Walze I",
		{ 4,  9, 10,  2,  7,  1, 23,  9, 13, 16,  3,  8,  2,
			9, 10, 18,  7,  3,  0, 22,  6, 13,  5, 20,  4, 10 }},
	[II] =
	{"Walze II",
		{ 0,  8,  1,  7, 14,  3, 11, 13, 15, 18,  1, 22, 10,
			6, 24, 13,  0, 15,  7, 20, 21,  3,  9, 24, 16,  5 }},
	[III] =
	{"Walze III",
		{ 1,  2,  3,  4,  5,  6, 22,  8,  9, 10, 13, 10, 13,
			0, 10, 15, 18,  5, 14,  7, 16, 17, 24, 21, 18, 15 }},
	[IV] =
	{"Walze IV",
		{ 4, 17, 12, 18, 11, 20,  3, 19, 16,  7, 10, 23,  5,
			20,  9, 22, 23, 14,  1, 13, 16,  8,  6, 15, 24,  2 }},
	[V] =
	{"Walze V",
		{ 21, 24, 25, 14,  2,  3, 13, 17, 12,  6,  8, 18,  1,
			20, 23,  8, 10,  5, 20, 16, 22, 19,  9,  7,  4, 11 }},
	[VI] =
	{"Walze VI",
		{ 9, 14,  4, 18, 10, 15,  6, 24, 16,  7, 17, 19,  1,
			20, 11,  2, 13, 19,  8, 25,  3, 16, 12,  5, 21, 23 }},
	[VII] =
	{"Walze VII",
		{ 13, 24,  7,  4,  2, 12, 22, 16,  4, 15,  8, 11, 15,
			1,  6, 16, 10, 17,  3, 18, 21,  9, 14, 19,  5, 20 }},
	[VIII] =
	{"Walze VIII",
		{ 5,  9, 14,  4, 15,  6, 17,  7, 20, 18, 25,  7,  3,
			16, 11,  2, 10, 21, 12,  3, 19, 13, 24,  1,  8, 22 }},
	[BETA] =
	{"Walze Beta",
		{ 11,  3, 22,  6, 17, 23,  7,  1, 15, 13,  5, 16,  4,
			25, 15,  2,  3,  9, 18,  6, 12, 10, 24, 10, 16, 19 }},
	[GAMMA] =
	{"Walze Gamma",
		{ 5, 17, 12,  7, 22,  8, 14, 23,  9, 24,  2, 16,  7,
			21, 10, 13,  6, 20, 24, 22,  5,  2, 25,  9, 11,  4 }},
	[UKW_B] =
	{"Umkehrwalze B",
		{ 24, 16, 18,  4, 12, 13,  5, 22,  7, 14,  3, 21,  2,
			23, 24, 19, 14, 10, 13,  6,  8,  1, 25, 12,  2, 20 }},
	[UKW_C] =
	{"Umkehrwalze C",
		{ 5, 20, 13,  6,  4, 21,  8, 17, 22, 20,  7, 14, 11,
			9, 18, 13,  3, 19,  2, 23, 24,  6, 17, 15,  9, 12 }},
	[UKW_BT] =
	{"Umkehrwalze B, thin",
		{ 4, 12,  8, 13, 22, 15, 18, 15,  1, 25, 18,  3,  3,
			14, 23, 23, 13,  6,  7,  2, 11, 24, 11, 20,  8, 19 }},
	[UKW_CT] =
	{"Umkehrwalze C, thin",
		{ 17,  2, 12, 24,  5,  8, 13,  3, 13, 21, 23,  1, 25,
			18, 14,  7,  9,  9,  5, 13,  4, 13, 19, 21, 22, 17 }},
	/* The Steckerbrett is technically not a rotor, but it can perfectly be
	 * modelled as one: it does not rotate, but the wirings can be modified.
	 * Note that the Steckerbrett does not translate characters by default
	 * (no cables). For consistency with the other representations, it is still
	 * manually initialized. I double-checked it for errors, I promise! */
	[SB] =
	{"Steckerbrett",
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }}
};

void printEnigmaRotors(void) {
	for (enum rotorID r = I; r < ROTOR_IDS; ++r) {
		struct enigmaRotor cur = selectEnigmaRotor(r);
		printf("%s:\n", cur.name);
		for (int c = 0; c < ER_ABC_SZ; ++c) {
			printf("%c-%c\n", ((c + cur.wiring[c]) % ER_ABC_SZ) + 'A', c + 'A');
		}
	}
}

struct enigmaRotor selectEnigmaRotor(enum rotorID ID) {
	return enigmaRotors[ID];
}
