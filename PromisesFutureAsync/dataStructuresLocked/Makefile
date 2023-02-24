FILE: a

all:$(FILE)

$(FILE): $(FILE).o
	g++ $(FILE).o -c -std++c17 project 
	del *.o

$(FILE).o: $(FILE).cpp
	g++ -o $(FILE).cpp -std++c17



post: move *.exe compiled