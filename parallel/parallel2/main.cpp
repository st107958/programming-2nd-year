#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>
#include <omp.h>

#define M_PI 3.14
#define N 10000000

double f(double x)
{
	return 1 / (1 + x * x);
}

double arctg(double a, double b, int n)
{
	double sum = 0.0;

	for (int k = 0; k <= n; ++k)
	{
		double arg = ((b-a)*(2.0 * k + 1.0)) / (2.0 * n);
		sum += (f(arg) * ((b - a) / n));
	}

	return sum;
}

int main(int argc, char argv[])
{
	//double pi = M_PI;

	//std::cout << sin(pi) << std::endl;



	auto start_time_1 = std::chrono::high_resolution_clock::now();

	std::cout << arctg(0, 1, N)*4.0 << std::endl;

	auto end_time_1 = std::chrono::high_resolution_clock::now();


	double n;
	double m;
	double sum;

#pragma omp parallel sections
	{
#pragma omp section 
		{
			m = arctg(0, 0.3, N) * 4.0;
			std::cout << arctg(0, 0.5, N) * 4.0 << std::endl;
		}
#pragma omp section 
		{
			n = arctg(0.3, 1, N) * 4.0;
			std::cout << arctg(0.5, 1, N) * 4.0 << std::endl;
		}
	}

	sum = n + m;

	std::cout << sum << std::endl;


	/*auto start_time_2 = std::chrono::high_resolution_clock::now();

	double sum1 = 0.0;

    #pragma omp parallel num_threads(2) reduction(+:sum1)
	{
        #pragma omp for
		for (int k = 0; k < N; ++k)
		{
			double arg = (2.0 * k + 1.0) / (2.0 * N);
			sum1 += (f(arg) * (1.0 / N));
		}
	}

	sum1 = sum1 * 4.0;

	std::cout << sum1 << std::endl;

	auto end_time_2 = std::chrono::high_resolution_clock::now();



	auto start_time_3 = std::chrono::high_resolution_clock::now();

	double sum2 = 0.0;

#pragma omp parallel num_threads(4) reduction(+:sum2)
	{
#pragma omp for
		for (int k = 0; k < N; ++k)
		{
			double arg = (2.0 * k + 1.0) / (2.0 * N);
			sum2 += (f(arg) * (1.0 / N));
		}
	}

	sum2 = sum2 * 4.0;

	std::cout << sum2 << std::endl;

	auto end_time_3 = std::chrono::high_resolution_clock::now();



	auto duration_1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_1 - start_time_1);

	std::cout << duration_1.count() << std::endl;

	auto duration_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_2 - start_time_2);

	std::cout << duration_2.count() << std::endl;

	auto duration_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_3 - start_time_3);

	std::cout << duration_3.count() << std::endl;*/

	return EXIT_SUCCESS;
}