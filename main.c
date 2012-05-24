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

int main(__attribute__((unused)) int argc, __attribute__((unused)) char * argv[]) {
	struct enigma_I e1;
	struct enigma_M4 em4;

	e1 = makeEnigma_I(UKW_B, III, II, I);
	em4 = makeEnigma_M4(UKW_B, BETA, III, II, I);

	puts("Welcome to enisim v0.1");

	printf("Enigma I:  'A' => '%c'\n", enigma_I_encode('A', e1));
	printf("Enigma M4: 'A' => '%c'\n", enigma_M4_encode('A', em4));

	return 0;
}
