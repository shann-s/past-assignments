// Initialize Memory using a Kernel - Two-Dimensional Data
// matrix_thread_id.cu

#include <iostream>
#include <cstdlib>
#include <cuda_runtime.h>

const unsigned ntpb = 32;

__global__ void initialize(float* a, float v, int n) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < n && j < n)
		a[j * n + i] = v;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "***Incorrect number of arguments***\n";
		return 1;
	}
	unsigned n = atoi(argv[1]);
	float v = atof(argv[2]);

	int nb = (n + ntpb - 1) / ntpb;
	std::cout << "n = " << n << ", No of Blocks = " << nb
		<< ", No of Threads Per Block = " << ntpb << std::endl;

	float* d_a = nullptr;
	cudaMalloc((void**)&d_a, n * n * sizeof(float));
	if (!d_a) {
		std::cerr << "***Out of Memory***\n";
		return 2;
	}
	float* h_a = new float[n * n];

	// launch
	dim3 dGrid(nb, nb, 1);
	dim3 dBlock(ntpb, ntpb, 1);
	initialize << <dGrid, dBlock >> >(d_a, v, n);

	// copy from device to host memory
	cudaMemcpy(h_a, d_a, n * n * sizeof(float), cudaMemcpyDeviceToHost);

	// check correctness
	for (int i = 0; i < n * n; i++)
		if (h_a[i] != v) std::cout << h_a[i] << "" << v << std::endl;
	std::cout << "done" << std::endl;

	cudaFree(d_a);
	delete[] h_a;
	cudaDeviceReset();
}