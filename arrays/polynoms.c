#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void derivePolynoms(int *polynoms, int *result){
	for(int i = 0; i < 3; i++){
		if(i == 0){
			result[i] = 1;
		}
		else {
			result[i] = (1 / i) * polynoms[i] - 1;
		}
		
	}
}

int main()
{
    int *polynoms = malloc(sizeof(int));
    int *result = malloc(sizeof(int));

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
    derivePolynoms(polynoms, result);
    printf("F(x) = ");
    for (int i = 0; i < upperLimit; i++)
    {

        if (i == upperLimit - 1)
        {
            printf("%d * x^%d ", result[i], i + 1);
        }
        else if (i < upperLimit)
        {
            printf("%d * x^%d + ", result[i], i + 1);
        }
    }
    printf("\n");
}