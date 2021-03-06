CC=g++
VSN=2.1
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=date.cpp gregorian.cpp julian.cpp kattistime.cpp 
OBJECTS=$(SOURCES:.cpp=.o)

all: test_$(VSN)

test_calendar:$(OBJECTS) calendar.cpp calendar.h test_calendar.h calobj.h calobj.cpp
	cxxtestgen.pl --error-printer -o $@.cpp $@.h
	make $@.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $@.o

valgrind_calendar:test_calendar
	valgrind --leak-check=yes ./$<

cprog09lab23:$(OBJECTS) cprog09lab23.o calendar.h calendar.cpp calobj.cpp calobj.h Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $@.o
	./$@ < lab23.in > ut
	meld lab23.out ut &

cprog09lab22b:$(OBJECTS) cprog09lab22b.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) cprog09lab22b.o

cprog09lab22c:$(OBJECTS) cprog09lab22c.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) cprog09lab22c.o


test_date:$(OBJECTS) $@.h
	cxxtestgen.pl --error-printer -o $@.cpp $@.h
	make $@.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $@.o

test_valgrind:test_$(VSN)
	valgrind --leak-check=yes ./test_$(VSN)

test_stream:$(OBJECTS) test_stream.o
	$(CC) $(CFLAGS) $(OBJECTS) test_stream.o -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

kattisa:
	submit.py -p cprog09lab22a kattistime.h kattistime.cpp cprog09lab22a.cpp date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp
kattisb:
	submit.py -p cprog09lab22b kattistime.h kattistime.cpp cprog09lab22b.cpp date.h date.cpp gregorian.h gregorian.cpp 
kattisc:
	submit.py -p cprog09lab22c kattistime.h kattistime.cpp cprog09lab22c.cpp date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp

kattisd:
	submit.py -p cprog09lab23 kattistime.h kattistime.cpp cprog09lab23.cpp date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp calobj.h calendar.h

clean:
	rm *.o
	rm cprog09lab23
