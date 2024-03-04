#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
#include <omp.h>

#define M_PI 3.14
#define N 10000000

int main(int argc, char argv[])
{
	std::locale::global(std::locale(""));

	double pi = M_PI;

	std::cout << sin(pi) << std::endl;

	auto start_time_1 = std::chrono::high_resolution_clock::now();

	double *sin_table_1 = new double[N];

	for (int k = 0; k < N; ++k)
	{
		double arg = k / 2 * M_PI;
		sin_table_1[k] = sin(arg);
	}

	auto end_time_1 = std::chrono::high_resolution_clock::now();



	auto start_time_2 = std::chrono::high_resolution_clock::now();

	double* sin_table_2 = new double[N];

#pragma omp parallel for num_threads(2)

	for (int k = 0; k < N; ++k)
	{
		double arg = k / 2 * M_PI;
		sin_table_2[k] = sin(arg);
	}

	auto end_time_2 = std::chrono::high_resolution_clock::now();



	auto start_time_3 = std::chrono::high_resolution_clock::now();

	double* sin_table_3 = new double[N];

#pragma omp parallel for num_threads(4)

	for (int k = 0; k < N; ++k)
	{
		double arg = k / 2 * M_PI;
		sin_table_3[k] = sin(arg);
	}

	auto end_time_3 = std::chrono::high_resolution_clock::now();



	auto duration_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_1 - start_time_1);

	std::cout << duration_1.count() << std::endl;

	auto duration_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_2 - start_time_2);

	std::cout << duration_2.count() << std::endl;

	auto duration_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_3 - start_time_3);

	std::cout << duration_3.count() << std::endl;

	return EXIT_SUCCESS;
}