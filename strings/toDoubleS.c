#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char *toDoubleS(char inputString[]){
	char *result = (char *)malloc(sizeof(char) * (strlen(inputString) + 1));
	int j = 0;
	for (int i = 0; i < strlen(inputString); i++){
		if(inputString[i] == 's' && inputString[i + 1] == 's' && i + 1 < strlen(inputString)){
			strcat(result,"ß");
			i++;
			j++;
		}else{
			result[j] = inputString[i];
		}
		j++;
	}
	 return result;
	
}

int main(){
	char testString[] = "Wissen";
	
	printf("%s\n", toDoubleS(testString));
	return 0;
}