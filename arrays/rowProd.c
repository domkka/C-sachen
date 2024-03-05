#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int *rowProd(int *a, int rows, int cols){
	int *result = malloc(sizeof(int)*rows);
	
	for (int i = 0; i < cols; i++){
		result[i] = 1;
	}
	
	for (int i = 0; i< cols; i++){
		for (int j = 0; j < rows; j++){
			result[i] *= a[i * rows + j];
		}
	}
	return result;
}

int main(){
	
	int a[3][3] = {
		{1,2,3},
		{3,-1,4},
		{1,1,1},
	};
	
	int *result = rowProd(*a,3,3);
	for(int i = 0; i< 3; i++){
		printf("%d ",result[i]);
	}
	free(result);
	return 0;
	
}