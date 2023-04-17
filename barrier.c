#include<stdio.h>
#include<omp.h>

int main(void){

	const int MAX = 32;

	float x[MAX];
	float y[MAX];
	float arr[MAX];



	#pragma omp parallel default(none) shared(x, y, arr) 
	{

	int i; 
	int j;
	int k;

	#pragma omp for
	for(i = 0; i < MAX; i++){
		x[i] = i * 3;
	}

	#pragma omp for
	for(j = 0; j < MAX; j++){
		y[j] = j / 4 * 9;
	}

	#pragma omp for
	for(k = 0; k < MAX; k++){
		arr[k] = x[k] * y[k];
	}

	#pragma omp master
	{
	       	float sum = arr[0];

		for(i = 1; i < MAX; i++){
			sum += arr[i];
		}
		
		printf("Sum: %f", sum);

	} //master
	} //parallel region





}
