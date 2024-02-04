#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void bubbleSort(int *array, int arraySize){
	for(int j = 0; j < arraySize; j++){
		for(int i = 0; i < arraySize - 1; i++){
			if (array[i] > array[i+1]){
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

int main(){
	int maxAmount = 8;
	int upperLimit = 50;
	int *testData = malloc(maxAmount * sizeof(int));
	testData[0] = 1;
	srand(time(NULL));
	for (int i = 0; i < maxAmount; i++){
		int randomNumber = rand() % upperLimit;
		testData[i] = randomNumber;
		printf("%d, ", testData[i]);
	}
	bubbleSort(testData, maxAmount);
	printf("\n");
	for(int i = 0; i < maxAmount; i++){
		printf("%d, ", testData[i]);
	}
	
	printf("\n");
	free(testData);
	return 1;
}