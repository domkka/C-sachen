#include <stdio.h>
#include <stdlib.h>

int *colProd(int *a, int rows, int cols){
	int *result = malloc(sizeof(int) * cols);
	for (int i = 0; i < cols; i++){
		result[i] = 1;
	}
	for(int i = 0; i < rows; i++){
		for (int j = 0; j< cols; j++){
			result[j] *= *(a + i*cols + j);
		}
	}
	return result;
}

int main(){
	int a[3][3] = {

    { 1, 2, 3 },

    { -1, -2, -3 },

    { 3, 4, 5 },

	};
	int *result = colProd(*a,3,3);
	for(int i = 0; i< 3; i++){
		printf("%d",result[i]);
	}
	free(result);
	return 0;
}