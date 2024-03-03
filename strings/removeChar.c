// Chars aus einem String entfernen
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *removeChar(char inputString[], char toRemove){
	char *result = (char *)malloc((strlen(inputString) + 1) * sizeof(char));
	int j = 0;
	for(int i = 0;i < strlen(inputString); i++){
		if(inputString[i] != toRemove){
			result[j] = inputString[i];
			j++;
		}
	}
	result[strlen(inputString)] = '\0';
	return result;
} 

int main(){
	char *testString = "ReeeeA";
	char *testString2 = "AAkoisabAiR";
	printf("%s\n", removeChar(testString, 'R'));
	printf("%s\n", removeChar(testString2,'i'));
	return 0;
}