

main: main.o bug.o tower.o board.o gamescreen.o projectile.o
	g++ -g -Wall -o main main.o bug.o tower.o board.o gamescreen.o projectile.o

newgame: bug.o tower.o board.o newgame.o projectile.o
	g++ -g -Wall -o newgame bug.o tower.o board.o newgame.o projectile.o

main.o: main.cpp
	g++ -g -Wall -c main.cpp

gamescreen.o: gamescreen.cpp gamescreen.h
	g++ -g -Wall -c gamescreen.cpp

newgame.o: newgame.cpp
	g++ -g -Wall -c newgame.cpp

board.o: board.cpp board.h
	g++ -g -Wall -c board.cpp

projectile.o: projectile.cpp projectile.h
	g++ -g -Wall -c projectile.cpp

bug.o: bug.cpp bug.h
	g++ -g -Wall -c bug.cpp

tower.o: tower.cpp tower.h
	g++ -g -Wall -c tower.cpp

run: 
	./main

clean:
	rm -f *.o *~ newgame main
