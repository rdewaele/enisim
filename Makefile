# Copyright (C) 2012 Robrecht Dewaele
#
# This file is part of enisim.
#
# enisim is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# enisim is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with enisim. If not, see <http://www.gnu.org/licenses/>.

# Reminders
#
# $@ = The file name of the target of the rule.
# $< = The name of the first dependency.
# $^ = The names of all the dependencies, with spaces between them.
# $? = The names of all the dependencies that are newer than the
#      target, with spaces between them.
# $* = The stem with which an implicit rule matches. If the target is
#      'dir/a.foo.b' and the target pattern is 'a.%.b' then the stem
#      is 'dir/foo'. The stem is useful for constructing names of
#      related files.

# About this makefile:
#
# This (GNU) makefile uses the builtin rules as much as possible. The
# header dependencies for individual objects are generated by $(CC),
# this means that currently GCC is expected. (Or any other compiler
# with the same behaviour for the particular command line switches.)

CWARNINGS=-W -Wall -Wextra -Wundef -Wendif-labels -Wshadow\
          -Wpointer-arith -Wbad-function-cast -Wcast-align\
          -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes\
          -Wnested-externs -Winline -Wdisabled-optimization\
          -Wno-missing-field-initializers
CFLAGS:=-g -O0 -pipe -pedantic -std=c99 -D_POSIX_C_SOURCE=200809L\
        $(CWARNINGS) $(CFLAGS)
LDLIBS=
SOURCES=main.c rotors.c
OBJECTS=$(SOURCES:.c=.o)
MAIN=main
EXECUTABLE=enisim

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN)
	cp $< $@

$(MAIN): $(OBJECTS)

test: $(EXECUTABLE)
	./$<

grind: $(EXECUTABLE)
	valgrind -v --leak-check=full --show-reachable=yes ./$<

clean:
	@rm -f $(OBJECTS) $(EXECUTABLE) $(MAIN)

mrproper: clean
	@rm -f  make.depend

.PHONY: all grind clean mrproper

make.depend: $(SOURCES)
	$(CC) -E -MM $^ > $@

-include make.depend
