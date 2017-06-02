hunt_the_wumpus: hunt_the_wumpus.cpp game.o room.o wumpus.o gold.o pit.o bat.o empty.o event.hpp
	g++ hunt_the_wumpus.cpp game.o room.o  wumpus.o gold.o pit.o bat.o empty.o -o hunt_the_wumpus
game.o: game.cpp game.hpp
	g++ -c game.cpp
room.o: room.cpp room.hpp event.hpp

	g++ -c room.cpp
gold.o: gold.cpp gold.hpp
	g++ -c gold.cpp
wumpus.o: wumpus.cpp wumpus.hpp
	g++ -c wumpus.cpp

pit.o: pit.cpp pit.hpp
	g++ -c pit.cpp
bat.o: bat.cpp bat.hpp
	g++ -c bat.cpp
empty.o: empty.cpp empty.hpp
	g++ -c empty.cpp







