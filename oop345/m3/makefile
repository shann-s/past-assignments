all : csvdump csvread task item order

csvdump : csvdump.cpp util.h util.cpp
	g++ -std=c++11 csvdump.cpp util.cpp -o csvdump

csvread : csvread.cpp
	g++ -std=c++11 csvread -o csvread

item : item.cpp util.h util.cpp
	g++ -std=c++11 item.cpp util.cpp util.h -o item

task : task.cpp util.h util.cpp
	g++ -std=c++11 task.cpp util.cpp util.h -o task

order : order.cpp util.h util.cpp
	g++ -std=c++11 order.cpp util.cpp -o order
