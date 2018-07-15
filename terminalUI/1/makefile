CC=g++
CFLAGS= -g 
DEPS = 
OBJ = fancyCounter.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fancyCounter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
