#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int *derivePolynoms(int *polynoms){
	
	int *result = malloc(sizeof(int)*sizeof(polynoms));
	for (int i = 0; i < sizeof(polynoms); i++){
		result[i] = polynoms[i] * i;
	}
	return result;
}

int main()
{
    int *polynoms = malloc(sizeof(int) * 3);
    

    int upperLimit = 3;
    srand(time(NULL));
    printf("f(x) = ");

    for (int i = 0; i < upperLimit; i++)
    {
        polynoms[i] = i + 1; // rand() % upperLimit;
        if (i == upperLimit - 1)
        {
            printf("%d * x^%d ", polynoms[i], i);
        }
        else if (i < upperLimit)
        {
            printf("%d * x^%d + ", polynoms[i], i);
        }
    }
    printf("\n");
    int *result = derivePolynoms(polynoms);
    printf("f'(x) = ");
    for (int i = 0; i < upperLimit; i++)
    {
		printf("%d * x^%d +", result[i],i - 1);
    }
    printf("\n");
	free(result);
	return 0;
}