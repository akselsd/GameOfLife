CXX=g++

CFLAGS=-c
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

_DEPS=WorldHandler.hpp GraphicsManager.hpp
_SRCS=WorldHandler.cpp GraphicsManager.cpp main.cpp
_OBJS=$(subst .cpp,.o,$(_SRCS))

SRCDIR=src
OBJDIR=obj

OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))
SRCS = $(patsubst %, $(SRCDIR)/%, $(_SRCS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS) $(OBJDIR)
	$(CXX) $(CFLAGS) -o $@ $<

.DEFAULT_GOAL: life
life: $(OBJS)
	$(CXX) $(OBJS) $(LFLAGS) -o GameOfLife

.PHONY: clean $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o

$(OBJDIR):
	mkdir -p obj