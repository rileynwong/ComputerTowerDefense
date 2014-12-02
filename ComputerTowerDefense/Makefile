

main: main.o bug.o tower.o board.o gamescreen.o
	g++ -g -Wall main.o bug.o tower.o board.o gamescreen.o -o main

main.o : main.cpp
	g++ -g -Wall -c main.cpp

gamescreen.o : gamescreen.cpp
	g++ -g -Wall -c gamescreen.cpp

newgame.o: newgame.cpp
	g++ -g -Wall -c newgame.cpp

board.o: board.cpp board.h
	g++ -g -Wall -c board.cpp

bug.o: bug.cpp bug.h
	g++ -g -Wall -c bug.cpp

tower.o: tower.cpp tower.h
	g++ -g -Wall -c tower.cpp

run: 
	./main

clean:
	rm -f *.o *~ newgame
