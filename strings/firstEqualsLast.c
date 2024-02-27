#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool firstEqualsLast(char inputString[]){
	return inputString[0] == inputString[strlen(inputString) - 1];
}


int main()
{
    char testString[] = "anna";
	char testString2[] = "annb";
    printf("%d\n", firstEqualsLast(testString));
	printf("%d\n", firstEqualsLast(testString2));
    return 0;
}