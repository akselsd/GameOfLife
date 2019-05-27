CXX=g++
RM=rm -f

CFLAGS=-c
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system


SRCS=WorldHandler.cpp GraphicsManager.cpp main.cpp

OBJS=$(subst .cpp,.o,$(SRCS))

$(OBJS): $(SRCS)
	$(CXX) $(CFLAGS) $(SRCS)

life: $(OBJS)
	$(CXX) $(OBJS) $(LFLAGS) -o GameOfLife