#this target will compile all the files
all: LinkedList
	
LinkedList: main.o CommandProcessor.o Menu.o
		g++ -std=c++11 main.cpp CommandProcessor.cpp Menu.cpp -o LinkedList

main.o: main.cpp CommandProcessor.cpp Menu.cpp
		g++ -std=c++11  main.cpp CommandProcessor.cpp Menu.cpp

CommandProcessor.o: main.cpp CommandProcessor.cpp Menu.cpp
		g++ -std=c++11 main.cpp CommandProcessor.cpp Menu.cpp

Menu.o: Menu.cpp CommandProcessor.cpp main.cpp
	g++ -std=c++11 Menu.cpp CommandProcessor.cpp main.cpp

Clean:
	rm -rf *o LinkedList
