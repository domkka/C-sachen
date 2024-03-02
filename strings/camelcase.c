// strings mit xmalloc kopieren über string laufen und alle lowercases in string direkt übergeben, leerzeichen auch,
// uppercases je nach position übergeben oder zu "\_x" transformieren.
// die zusätzliche größenveränderung beim allocieren natürlich vorher beachten.
// Originalstring nicht verändern.
// Rückgabestring dynmanisch allokieren.
//   - nur wenn Uppercase \_ untermische und und die innere Buchstabe zu lowercase
//   - Hilfsfunktionen
//      - is_letter()....
//      - is_upper()....
//      - is_lower()....
//      - to_upper()...
//      - to_lower()...
//   - Beispiele
//     - abcd --> abcd
//     - Abcd --> Abcd
//     - ABCD --> A_b_c_d
//     - ABCDEF --> A_b_c_d_e_f
//     - ABCD EF --> A_b_c_d E_f

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isLetter(char inputChar)
{
    bool result = false;
    if (inputChar >= 'a' && inputChar <= 'z' || inputChar >= 'A' && inputChar <= 'Z')
    {
        result = true;
    }
    return result;
}

char *camelCase(char inputString[]){
	char *result = (char *)malloc(2*strlen(inputString) * sizeof(char));
	bool entireStringUpperCase = true;
	for(int i = 0; i < strlen(inputString); i++){
		if(islower(inputString[i])){
			entireStringUpperCase = false;
			break;
		}
	}
	
	int j = 0;
	
	if(entireStringUpperCase){
		for(int i = 0; i < strlen(inputString); i++){
			if(i == 0){
				result[j] = inputString[i];
			}else{
				result[j] = '_';
				j++;
				result[j] = tolower(inputString[i]);
			}
			j++;
		}
	}else{
		for(int i = 0; i < strlen(inputString); i++){
			if(i == 0){
				result[j] = inputString[i];
			}else{
				if(islower(inputString[i])){
					result[j] = inputString[i];
				}else{
					result[j] = '_';
					j++;
					result[j] = tolower(inputString[i]);
				}
			}
			j++;
		}
	}
	
	return result;
		
}

int main()
{
    char testString1[] = "ABCEDTL";
    printf("%s\n", camelCase(testString1));
	char testString2[] = "AjhvSjkSTn";
    printf("%s\n", camelCase(testString2));
    return 0;
}