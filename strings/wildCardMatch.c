#include <string.h>
#include <stdio.h>
#include <stdbool.h>


bool strstrWithWildcards(char searchString[], char stringToCompare[]){
	bool result = false;
	if(strcmp(searchString, stringToCompare) == 0){
		result = true;
	}else {
		char *toComparePointer = stringToCompare;
		while(*toComparePointer){
			char *toComparePointerBegin = toComparePointer;
			char *searchPointer = searchString;
			while(*toComparePointerBegin && *searchPointer && (*toComparePointerBegin == *searchPointer || *searchPointer == '!')){
				toComparePointer++;
				searchPointer++;
			}
			if(!*searchPointer){
				result = true;
			}
			toComparePointer = toComparePointerBegin + 1;
		}
	}
	return result;
}

int main()
{
    char searchString[] = "1";
    char stringToCompare[] = "123";
    printf("%d\n", strstrWithWildcards(searchString, stringToCompare));
    return 0;
}
