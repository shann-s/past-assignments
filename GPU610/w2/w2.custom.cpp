// Linear Algebra - Workshop 2
// w2.custom.cpp

#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
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

float sdot(int n, const float* a, const float* b) {

	// insert your custom code here
	double s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i] * b[i];
	}
	return s;
}

void sgemv(const float* a, int n, const float* v, float* w) {

	// insert your custom code here
	for (int i = 0; i < n; i++) {
		float sum = 0;
		for (int x = 0; x < n; x++) {
			sum += a[i * n + x] * v[x];
		}
		w[i] = sum;
	}

}

void sgemm(const float* a, const float* b, int n, float* c) {

	// insert your custom code here
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) {
			float sum = 0;
			for (int y = 0; y < n; y++) {
				sum += a[i * n + y] * b[y * n + x];
			}
			c[i * n + x] = sum;
		}
	}

}

int main(int argc, char** argv) {

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
	reportTime("initialization         ", te - ts);

	// vector-vector - dot product of v and w
	ts = steady_clock::now();
	sdot(n, v, w);
	te = steady_clock::now();
	reportTime("vector-vector operation", te - ts);

	// matrix-vector - product of a and v
	ts = steady_clock::now();
	sgemv(a, n, v, w);
	te = steady_clock::now();
	reportTime("matrix-vector operation", te - ts);

	// matrix-matrix - product of a and b
	ts = steady_clock::now();
	sgemm(a, b, n, c);
	te = steady_clock::now();
	reportTime("matrix-matrix operation", te - ts);

	delete[] v;
	delete[] w;
	delete[] a;
	delete[] b;
	delete[] c;
}