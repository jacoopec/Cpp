FILE: a

all:$(FILE)

$(FILE): $(FILE).o
	g++ $(FILE).o -o -std=c++20 project
	del *.o

$(FILE).o: $(FILE).cpp
	g++ -c -std=c++17 $(FILE).cpp -std=c++17



post: move *.exe compiled