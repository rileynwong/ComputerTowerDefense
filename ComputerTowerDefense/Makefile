
newgame: newgame.o bug.o tower.o
	g++ -g -Wall newgame.o bug.o tower.o -o newgame

newgame.o: newgame.cpp
	g++ -g -Wall -c newgame.cpp

bug.o: bug.cpp bug.h
	g++ -g -Wall -c bug.cpp

tower.o: tower.cpp tower.h
	g++ -g -Wall -c tower.cpp

clean:
	rm -f *.o *~ newgame