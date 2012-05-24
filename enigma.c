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

#include "enigma.h"
#include "rotors.h"

#include <stdio.h>

struct enigma_I makeEnigma_I(enum rotorID ukw, enum rotorID i, enum rotorID ii, enum rotorID iii) {
	return (struct enigma_I) {
		selectEnigmaRotor(ukw),
		selectEnigmaRotor(i),
		selectEnigmaRotor(ii),
		selectEnigmaRotor(iii),
		selectEnigmaRotor(SB)
	};
}

struct enigma_M4 makeEnigma_M4(enum rotorID ukw, enum rotorID ag, enum rotorID i, enum rotorID ii, enum rotorID iii) {
	return (struct enigma_M4) {
		selectEnigmaRotor(ukw),
		selectEnigmaRotor(ag),
		selectEnigmaRotor(i),
		selectEnigmaRotor(ii),
		selectEnigmaRotor(iii),
		selectEnigmaRotor(SB)
	};
}


char enigma_I_encode(char c, struct enigma_I e) {
	/*
	// input passes the following components in order:
	// input ->| Steckerbrett (SB), rightmost Walze (RW), middle Walze (MW),
	// leftmost Walze (LW), Umkehrwalze, LW, MW, RW, SB |-> output
	c = e.sb.wiring[c - 'A'];
	printf("SB: %c\n", c);
	// first rotate, then keypress
	// TODO implement turnover logic
	e.walze3.rotation = (e.walze3.rotation + 1) % ER_ABC_SZ;
	// TODO maybe modify enigma struct to simple array (do rotations first)
	c = e.walze3.wiring[c - 'A'];
	printf("W3: %c\n", c);
	c = e.walze2.wiring[c - 'A'];
	printf("W2: %c\n", c);
	c = e.walze1.wiring[c - 'A'];
	printf("W1: %c\n", c);

	c = e.ukw.wiring[c - 'A'];
	printf("UKW: %c\n", c);

	c = e.walze1.wiring_inv[c - 'A'];
	printf("W1: %c\n", c);
	c = e.walze2.wiring_inv[c - 'A'];
	printf("W2: %c\n", c);
	c = e.walze3.wiring_inv[c - 'A'];
	printf("W3: %c\n", c);

	c = e.sb.wiring[c - 'A'];
	printf("SB: %c\n", c);
*/
	return c;
}

char enigma_M4_encode(char c, __attribute__((unused)) struct enigma_M4 e) {
	return c;
}
