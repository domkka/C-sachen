// ersten Buchstaben eines Wortes groß den Rest klein
//     Eingabe: HELLO WORLD
//     Ausgabe: Hello World

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *autoCorrect(char inputString[]){
	char *result = (char *)malloc(sizeof(char)* (strlen(inputString) + 1));
	for (int i = 0; i < strlen(inputString); i++){
		if(i == 0){
			result[i] = toupper(inputString[i]);
		}else{
			result[i] = tolower(inputString[i]);
		}
	}
	return result;
}

int main(){
	char testString1[] = "HELLO WORLD";
	char testString2[] = "WixXE mitre Eis";
	printf("%s\n%s\n",autoCorrect(testString1),autoCorrect(testString2));
	return 0;
}