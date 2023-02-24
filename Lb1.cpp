#include <iostream>
#include <cmath>
#include "omp.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	const int size = (int)pow(1024, 3);
	int* a = new int[size];
	int* b = new int[size];
	int* sum = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = 5;
		b[i] = 5;
	}
}