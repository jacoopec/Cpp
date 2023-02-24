FILE: l

all:$(FILE)

$(FILE): $(FILE).o
	g++ $(FILE).o -o project
	del *.o

$(FILE).o: $(FILE).cpp
	g++ -c $(FILE).cpp 



post: move *.exe compiled