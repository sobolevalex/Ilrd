CC=g++
CFLAGS=
DEPS = 
OBJ = fancyCounter.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SandBox: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
