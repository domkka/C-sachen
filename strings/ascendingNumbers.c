#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxLength 4

bool isDigit(char c){
	if(c >= '0' && c <= '9'){
		return true;
	}
	return false;
}

bool checkString(char input[]){
	bool result = false;
	int hitcounter = 1;
	for(int i = 0; i < strlen(input); i++){
		if(isDigit(input[i]) && input[i+1]== input[i] + 1){
			hitcounter++;
		}
	}
	if(hitcounter >= 4){
		result = true;
	}
	return result;
}

int main(){
	char test1[] = "_1234_";
	char test2[] = "as5678e";
	char test3[] = "as5378e";
	printf("--> %d\n", checkString(test1));
	printf("--> %d\n", checkString(test2));
	printf("--> %d\n", checkString(test3));
	return 0;
}