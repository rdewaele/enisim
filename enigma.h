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

#include "rotors.h"

// The Enigma I was used by the Wehrmacht. It had 1 out of 2 possible
// reflectors (UKW B or UKW C), and 3 out of 5 possible rotors (I to V).
// As it was a military enigma, it also featured a Steckerbrett.
struct enigma_I {
	struct enigmaRotor ukw;
	struct enigmaRotor walze1;
	struct enigmaRotor walze2;
	struct enigmaRotor walze3;
	struct enigmaRotor sb;
};

// The Enigma M4 was used by the Kriegsmarine. It had 1 out of 2 possible
// reflectors (UKW B or UKW C, thin versions), 1 out of 2 possible 'extra'
// rotors (Beta or Gamma), and 3 out of 8 possible regular rotors (I-VIII).
// Note that the 3 additional rotors, compared to the Enigma I, all have
// two notches instead of only one.
struct enigma_M4 {
	struct enigmaRotor ukw;
	struct enigmaRotor ag;
	struct enigmaRotor walze1;
	struct enigmaRotor walze2;
	struct enigmaRotor walze3;
	struct enigmaRotor sb;
};

struct enigma_I makeEnigma_I(enum rotorID, enum rotorID, enum rotorID, enum rotorID);
struct enigma_M4 makeEnigma_M4(enum rotorID, enum rotorID, enum rotorID, enum rotorID, enum rotorID);

char enigma_I_encode(char, struct enigma_I);
char enigma_M4_encode(char, struct enigma_M4);
