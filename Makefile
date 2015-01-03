CC=g++
DEFS=-D_SCREEN_WIDTH=640 -D_SCREEN_HEIGHT=480
CXXFLAGS= -std=c++11 -march=native -fopenmp -Wall -Ofast -ggdb -Iinclude  $(DEFS)
LIBS=-lm -lpthread -lSDL -fopenmp

OBJS=raytracer.o sdlwrap.o
TEST=raytracer

all: $(OBJS) 
	$(CC) -o $(TEST) $(OBJS) $(LIBS) 

clean:
	rm -f $(TEST) $(OBJS) *.core # *.tga

