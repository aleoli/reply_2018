OBJECTS = bin/main.o bin/reply.o bin/dependencies.o bin/country.o bin/package.o bin/project.o bin/provider.o bin/reader.o bin/region.o bin/service.o bin/output.o bin/lock.o

CC = g++

PROGRAM_NAME = reply

build: $(OBJECTS)
	$(CC) -Wall -std=c++11 -o bin/$(PROGRAM_NAME) $(OBJECTS) -pthread

bin/%.o: src/%.cpp
	$(CC) -Wall -std=c++11 -c -o bin/$*.o src/$*.cpp

run: build
	@bin/$(PROGRAM_NAME)

clear:
	@rm bin/*.o
	@rm bin/$(PROGRAM_NAME)
