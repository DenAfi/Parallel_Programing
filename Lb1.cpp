#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

#define NUM_THREADS 4
#define TEST_COUNT 5
int main() {
	setlocale(LC_ALL, "");
	
	
	const int size = (int)pow(1024, 3);
	int* a = new int[size];
	int* b = new int[size];
	int* sum = new int[size];
	double beg, end;
	cout << "Start of initialization" << endl;
	for (int i = 0; i < size; i++) {
		a[i] = 5;
		b[i] = 5;
	}
	cout << "Initialization's end" << endl;
	cout << "Number of threads " << NUM_THREADS << endl;
	omp_set_dynamic(0);
	for(int j = 0; j<TEST_COUNT; j++){
		beg = omp_get_wtime();
		#pragma omp parallel num_threads(NUM_THREADS)
		{
			#pragma omp for
			for (int i = 0; i < size; i++) {
				a[i] = a[i] * b[i];
			}
		}
		end = omp_get_wtime();
		double t = end - beg;
		cout << j+1 << ") Time: " << t << endl;
	}

}