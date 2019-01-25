#include <stdio.h>
#include <math.h>

int main(){
	int n = 0;
	int sqrN = 0;

	printf("What is the max limit?\n");
	scanf("%d", &n);

	//Squareroot of N rounded up
	sqrN = ceil(sqrt(n));

	// Declaration
	int* myArray = 0;

	// Allocation (let's suppose size contains some value discovered at runtime,
	myArray = (int*) malloc(n * sizeof(int));

	// initialize the list with values from 2 to the max limit
	for(int i = 0; i <= n; i++){
		myArray[i] = i;
	}


	// sieve
	for(int i = 2; i < sqrN; i++){
		//printf("i = %d\n", i);
		if (myArray[i] != 0){
			for(int j = i * i; j < n; j = j + i){
				//printf("j = %d\n", j);
				myArray[j] = 0;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(i == 0){
			printf("%d", myArray[0]);
		}
		if(myArray[i] != 0){
			printf(", %d", myArray[i]);
		}
	}

	free(myArray);

	return 0;
}