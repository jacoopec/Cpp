OBJS :=
EXE = cinque
CPPFLAGS := -Wall -g -02 -fstrict -pthread -std=c++17
LDFLAGS :=
LIBS = 
INCDIR := -I. 

all: $(EXE)
LFLAGS = -pthread
CPPFLAGS =

%: %.cc
	cc $(LFLAGS) $< -o $@ $(CPPFLAGS) -std=c++17

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@ $(CPPFLAGS) -std=c++17

clean:
	rm *.o $(EXE)