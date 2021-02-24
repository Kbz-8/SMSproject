########################### MAKEFILE ###########################

DEBUG = yes
CC = gcc
ifeq ($(DEBUG),yes)
	CXXFLAGS = -Wall -g
else
	CXXFLAGS = -Wall
endif
LIBS = -lwiringPi

OBJ = obj/main.o obj/smsManager.o obj/manager.o
EXE = app # App name

all: $(EXE)

$(EXE):	$(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LIBS)

ifeq ($(DEBUG),yes)
	@echo " "
	@echo " "
	@echo " "
	@echo "======================================================="
	@echo " "
	@echo "DEBUG COMPILING SUCCESS"
	@echo " "
	@echo "======================================================="
	@echo " "
	@echo " "
	@echo " "
else
	@echo " "
	@echo " "
	@echo " "
	@echo "======================================================="
	@echo " "
	@echo "RELEASE COMPILING SUCCESS"
	@echo " "
	@echo "======================================================="
	@echo " "
	@echo " "
	@echo " "
endif

obj/main.o: main.c
	$(CC) -o $@ -c $< $(CXXFLAGS)
obj/smsManager.o: src/smsManager.c src/smsManager.h
	$(CC) -o $@ -c $< $(CXXFLAGS)
obj/manager.o: src/manager.c src/manager.h
	$(CC) -o $@ -c $< $(CXXFLAGS)


clean:
	rm  $(EXE)
