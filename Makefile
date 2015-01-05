CC=g++
LIB=-lwiringPi -lwiringPiDev
FLAGS=-Wall -c
DESTDIR=/usr/local
BIN=lcd
OBJ=lcd.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LIB) $(OBJ) -o $(BIN)

lcd.o: lcd.cpp
	$(CC) $(FLAGS) lcd.cpp

clean:
	rm -f $(OBJ) $(BIN)

install:
	install -m 0755 lcd $(DESTDIR)/bin/

uninstall:
	rm -f $(DESTDIR)/bin/lcd
