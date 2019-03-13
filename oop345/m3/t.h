#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>


	class Task{

		string taskName, taskSlots, taskAccept, taskFail;
	public:
		Task(vector<string> row);

		void Graph(fstream& os);

		void Print();
	};

	class TaskManager {

		vector < Task > tasklist;
	public:
		TaskManager(vector < vector < string > > & csvData);
		void print();
			void graph(string& filename);
	};