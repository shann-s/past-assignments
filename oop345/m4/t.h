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

		Task() {}

		void Graph(fstream& os);

		void Print();

		std::string& getTaskName() { return taskName; }
		std::string& getTaskPass() { return taskPass; }
		std::string& getTaskFail() { return taskFail; }
	};

	class TaskManager {

		vector < Task > tasklist;
	public:
		TaskManager(vector < vector < string > > & csvData);
		void print();
		void graph(string& filename);
		void IntegrityCheck();
		Task* FindTask(std::string& name);
		size_t size() { return tasklist.size(); }
		Task* getTask(size_t t) { return &tasklist[t];  }
	};