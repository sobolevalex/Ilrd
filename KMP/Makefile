CC=g++
CFLAGS= -ansi -pedantic -Wall -Werror
DEBUGFLAG= -g 
DEPS= 
OBJ = main.o 

debug:
	set CFLAGS= $(DEBUGFLAG)$(CFLAGS)
	$(MAKE) KMP_D

release:
	$(MAKE) KMP

KMP: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

KMP_D: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f ./*.o *~ core

