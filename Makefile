CC=g++
OBJS=$(wildcard *.c*)
OBJ_NAME=main

INCLUDE=-IG:\shmydo\cpp\libs\include
LIB=-LG:\shmydo\cpp\libs\Lib\SDL2
COMPILER_FLAGS=-Wall
LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2
main: $(OBJS)
	g++ -std=c++17 $(OBJS) $(INCLUDE) $(LIB) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

.PHONY: clean
clean:
	rm -rf *.o *.exe *~
