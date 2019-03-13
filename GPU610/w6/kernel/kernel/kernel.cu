// Simple Matrix Multiply - Workshop 6
// w6.cu

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
// add CUDA runtime header file
#include <cuda_runtime.h>
#include "device_launch_parameters.h"
using namespace std::chrono;

const int ntpb = 32; // number of threads per block

					 // - add your kernel here
__global__ void initialize(float* a, float* b, float* c, int n) {

	int col = blockIdx.x*blockDim.x + threadIdx.x;
	int row = blockIdx.y*blockDim.y + threadIdx.y;

	if (row < n && col < n) {
		float sum = 0.0f;
		for (int i = 0; i < n; i++) {
			sum += a[col * n + i] * b[i * n + row];
		}
		c[col * n + row] = sum;
	}
}





					 // check reports error if any
					 //
void check(const char* msg, const cudaError_t err) {
	if (err != cudaSuccess)
		std::cerr << "*** " << msg << ":" << cudaGetErrorString(err) << " ***\n";
}

// display matrix M, which is stored in row-major order
//
void display(const char* str, const float* M, int nr, int nc)
{
	std::cout << str << std::endl;
	std::cout << std::fixed << std::setprecision(4);
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++)
			std::cout << std::setw(10)
			<< M[i * nc + j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// report system time
//
void reportTime(const char* msg, steady_clock::duration span) {
	auto ms = duration_cast<milliseconds>(span);
	std::cout << msg << " - took - " <<
		ms.count() << " millisecs" << std::endl;
}

// matrix multiply
//
void sgemm(float* h_a, float* h_b, float* h_c, int n) {

	// - calculate number of blocks for n rows
	int blocks = (n + ntpb - 1) / ntpb;
	// allocate memory for matrices d_a, d_b, d_c on the device

	// - add your allocation code here
	float* d_a = nullptr;
	float* d_b = nullptr;
	float* d_c = nullptr;
	cudaMalloc((void**)&d_a, n * n * sizeof(float));
	cudaMalloc((void**)&d_b, n * n * sizeof(float));
	cudaMalloc((void**)&d_c, n * n * sizeof(float));
	// copy h_a and h_b to d_a and d_b (host to device)
	// - add your copy code here
	cudaMemcpy(d_a, h_a, n * n * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, h_b, n * n * sizeof(float), cudaMemcpyHostToDevice);


	// launch execution configuration
	// - define your 2D grid of blocks
	dim3 dGrid(blocks, blocks, 1);
	// - define your 2D block of threads
	dim3 dBlock(ntpb, ntpb, 1);
	// - launch your execution configuration
	cudaError_t error = cudaGetLastError();
	initialize << <dGrid, dBlock >> > (d_a, d_b, d_c, n);
	// - check for launch termination
	check("Launch Termination", error);
	// copy d_c to h_c (device to host)
	// - add your copy code here
	cudaMemcpy(h_c, d_c, n * n * sizeof(float), cudaMemcpyDeviceToHost);

	// deallocate device memory
	// - add your deallocation code here
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	// reset the device
	cudaDeviceReset();
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << ": invalid number of arguments\n";
		std::cerr << "Usage: " << argv[0] << "  size_of_vector\n";
		return 1;
	}
	int n = std::atoi(argv[1]); // number of rows/columns in h_a, h_b, h_c 
	steady_clock::time_point ts, te;

	// allocate host memory
	ts = steady_clock::now();
	float* h_a = new float[n * n];
	float* h_b = new float[n * n];
	float* h_c = new float[n * n];

	// populate host matrices a and b
	for (int i = 0, kk = 0; i < n; i++)
		for (int j = 0; j < n; j++, kk++)
			h_a[kk] = h_b[kk] = (float)kk / (n * n);
	te = steady_clock::now();
	reportTime("allocation and initialization", te - ts);

	// h_c = h_a * h_b
	ts = steady_clock::now();
	sgemm(h_a, h_b, h_c, n);
	te = steady_clock::now();
	reportTime("matrix-matrix multiplication", te - ts);

	// display results
	if (n <= 5) {
		display("h_a :", h_a, n, n);
		display("h_b :", h_b, n, n);
		display("h_c = h_a h_b :", h_c, n, n);
	}

	// check correctness
	std::cout << "correctness test ..." << std::endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			float sum = 0.0f;
			for (int k = 0; k < n; k++)
				sum += h_a[i * n + k] * h_b[k * n + j];
			if (std::abs(h_c[i * n + j] - sum) > 1.0e-3f)
				std::cout << "[" << i << "," << j << "]" << h_c[i * n + j]
				<< " != " << sum << std::endl;
		}
	std::cout << "done" << std::endl;

	// deallocate host memory
	delete[] h_a;
	delete[] h_b;
	delete[] h_c;
}