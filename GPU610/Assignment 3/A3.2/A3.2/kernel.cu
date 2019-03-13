#include <stdlib.h>
#include <stdio.h>
#include <cuda.h>
#include <math.h>
#include <time.h>
#include <curand_kernel.h>
#include <cstdlib>

#define BLOCKS 128
#define THREADS 32
#define PI 3.1415926535  // known value of pi

__global__ void gpu_monte_carlo(float *estimate, curandState *states, float n) {
	unsigned int tid = threadIdx.x + blockDim.x * blockIdx.x;
	float points_in_circle = 0;
	float x, y;

	curand_init(1234, tid, 0, &states[tid]);  // 	Initialize CURAND


	for (int i = 0; i < n; i++) {
		x = curand_uniform(&states[tid]);
		y = curand_uniform(&states[tid]);
		points_in_circle += (x*x + y*y <= 1.0f); // count if x & y is in the circle.
	}
	estimate[tid] = 4.0f * points_in_circle / n; // return estimate of pi
}

float host_monte_carlo(long trials) {
	float x, y;
	long points_in_circle = 0;
	for (long i = 0; i < trials; i++) {
		x = rand() / (float)RAND_MAX;
		y = rand() / (float)RAND_MAX;
		points_in_circle += (x*x + y*y <= 1.0f);
	}
	return 4.0f * points_in_circle / trials;
}

int main(int argc, char** argv) {
	clock_t start, stop;
	curandState *devStates;
	float n = std::atoi(argv[1]);
	dim3 dimGrid(BLOCKS, 1, 1);  // Grid dimensions
	dim3 dimBlock(THREADS, 1, 1);  // Block dimensions
	float *dev, *host;
	size_t size = BLOCKS * THREADS * sizeof(float);  //Array memory size
	printf("# of trials per thread = %.0f, # of blocks = %d, # of threads/block = %d.\n", n,
		BLOCKS, THREADS);

	start = clock();
	host = (float *)malloc(size);  //  Allocate array on host
	cudaMalloc((void **)&dev, size);  // Allocate array on device
	cudaMemset(dev, 0, size);
	cudaMalloc((void **)&devStates, THREADS * BLOCKS * sizeof(curandState));
	gpu_monte_carlo << <BLOCKS, THREADS >> >(dev, devStates, n);
	cudaMemcpy(host, dev, size, cudaMemcpyDeviceToHost); // return results 

	float pi_gpu = 0.0f;
	for (int i = 0; i < BLOCKS * THREADS; i++) {
		pi_gpu += host[i];
	}

	pi_gpu /= (BLOCKS * THREADS);

	stop = clock();

	printf("GPU pi calculated in %f s.\n", (stop - start) / (float)CLOCKS_PER_SEC);

	start = clock();
	//float pi_cpu = host_monte_carlo(BLOCKS * THREADS * n);
	stop = clock();
	printf("CPU pi calculated in %f s.\n", (stop - start) / (float)CLOCKS_PER_SEC);

	printf("CUDA estimate of PI = %f [error of %f]\n", pi_gpu, pi_gpu - PI);
	//printf("CPU estimate of PI = %f [error of %f]\n", pi_cpu, pi_cpu - PI);

	return 0;
}