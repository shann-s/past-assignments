// Linear Algebra - Workshop 2
// w2.cblas.cpp

#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
extern "C" {
#include <gsl/gsl_cblas.h> 
}
using namespace std::chrono;

void init(float* a, int n) {
	const float randf = 1.0f / (float)RAND_MAX;
	for (int i = 0; i < n; i++)
		a[i] = std::rand() * randf;
}

void reportTime(const char* msg, steady_clock::duration span) {
	auto ms = duration_cast<milliseconds>(span);
	std::cout << msg << " - took - " <<
		ms.count() << " millisecs" << std::endl;
}

int main(int argc, char* argv[]) {

	// interpret command-line argument
	if (argc != 2) {
		std::cerr << argv[0] << ": invalid number of arguments\n";
		std::cerr << "Usage: " << argv[0] << "  size_of_matrices\n";
		return 1;
	}
	int n = std::atoi(argv[1]);
	steady_clock::time_point ts, te;
	float* v = new float[n];
	float* w = new float[n];
	float* a = new float[n * n];
	float* b = new float[n * n];
	float* c = new float[n * n];

	// initialization
	std::srand(std::time(nullptr));
	ts = steady_clock::now();
	init(a, n * n);
	init(b, n * n);
	init(v, n);
	init(w, n);
	te = steady_clock::now();
	reportTime("initialization", te - ts);

	// vector-vector - dot product of v and w
	ts = steady_clock::now();
	//add call to cblas here
	cblas_sdot(n, v, 1.0, w, 1.0);
		te = steady_clock::now();
	reportTime("vector-vector operation", te - ts);

	// matrix-vector - product of a and v
	ts = steady_clock::now();
	//add call to cblas here
	cblas_sgemv(CblasRowMajor, CblasNoTrans, n, n, 0.0, a, n, v, 1.0, 1.0, w, n);
		te = steady_clock::now();
	reportTime("matrix-vector operation", te - ts);

	// matrix-matrix - product of a and b
	ts = steady_clock::now();
	//add call to cblas here
	cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, a, n, b, n, 0.0, c, n);
		te = steady_clock::now();
	reportTime("matrix-matrix operation", te - ts);

	delete[] v;
	delete[] w;
	delete[] a;
	delete[] b;
	delete[] c;
}