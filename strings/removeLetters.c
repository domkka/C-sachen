// nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
// Zahlen aus String rausschreiben
// Originalstring nicht verändern
// Rückgabestring dynmanisch allokieren
// nur Hilfsfunktionen verwenden und xmalloc
//     - is_letter
//     - s_length
// Beispiele
//     " " --> " "
//     "abc " --> " "
//     "1abc" --> "1"
//     "x11" --> "11"
//     "1a2b3c4d" --> "1234"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *removeLetters(char inputString[]){
	int newLength = 1;
	for (int i = 0; i < strlen(inputString); i++){
		if(inputString[i] >= '0' && inputString[i] <= '9'){
			newLength++;
		}
	}
	
	char *result = (char *)malloc((newLength) * sizeof(char));
	result[0] = ' ';
	int j = 0;
	for(int i = 0; i < strlen(inputString); i++){
		if(inputString[i] >= '0' && inputString[i] <= '9'){
			result[j] = inputString[i];
			j++;
		}
	}
	return result;
}


int main(){
	char testString1[] = "1a2b3c4d";
	char testString2[] = "1abc";
	char *s1 = removeLetters(testString1);
	char *s2 = removeLetters(testString2);
	printf("%s\n", testString1);
	printf("%s\n", s1);
	printf("%s\n", testString2);
	printf("%s\n", s2);
	free(s1);
	free(s2);
	return 0;
	
}