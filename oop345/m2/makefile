all : csvdump csvread task

csvdump : csvdump.cpp util.h util.cpp
	g++ -std=c++11 csvdump.cpp util.cpp -o csvdump

csvread : csvread.cpp
	g++ -std=c++11 csvread -o csvread

task : task.cpp util.h util.cpp
	g++ -std=c++11 task.cpp util.cpp util.h -o task
