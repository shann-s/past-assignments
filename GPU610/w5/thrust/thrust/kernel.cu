// Vector Magnitude - Workshop 5
// w5.cu

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <cstdlib>
#include <algorithm>
// insert thrust header files here
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/copy.h>
#include <thrust/functional.h>
#include <thrust/reduce.h>
#include <thrust/transform_reduce.h>
#include <thrust/iterator/constant_iterator.h>
using namespace std::chrono;

// report system time
//
void reportTime(const char* msg, steady_clock::duration span) {
	auto ms = duration_cast<milliseconds>(span);
	std::cout << msg << " - took - " <<
		ms.count() << " millisecs" << std::endl;
}

// Square Function Object - add class definition here

class Square {
	const int inc;
public:

	int operator()(int x) const { return sqrt(x);  }

};



// magnitude - add calculation steps here
//
float magnitude(thrust::host_vector<int> &V) {
	float result;

	// ... add Thrust calls
	thrust::device_vector<int> d_a = V;
	Square(d_a);

	return result;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << argv[0] << ": invalid number of arguments\n";
		std::cerr << "Usage: " << argv[0] << "  size_of_vector\n";
		return 1;
	}
	int n = std::atoi(argv[1]); // number of elements
	steady_clock::time_point ts, te;

	// Thrust definition of host vector
	thrust::host_vector<int> V(n);

	// initialize the host vector
	ts = steady_clock::now();
	std::generate(V.begin(), V.end(), std::rand);
	te = steady_clock::now();
	reportTime("initialization", te - ts);

	// calculate the magnitude of the host vector
	ts = steady_clock::now();
	float len = magnitude(V);
	te = steady_clock::now();
	reportTime("magnitude calculation", te - ts);

	// display the magnitude
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Magnitude : " << len << std::endl;
}