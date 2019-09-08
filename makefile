Langtons_Ant: main.o ant.o menu.o user_validation.o
	g++ -std=c++11 main.o ant.o menu.o user_validation.o -o Langtons_Ant
main.o: main.cpp
	g++ -c main.cpp
ant.o: ant.cpp ant.hpp
	g++ -c -std=c++11 ant.cpp
menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp
user_validation.o: user_validation.cpp user_validation.hpp
	g++ -c -std=c++11 user_validation.cpp
clean:
	rm *.o Langtons_Ant
