#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntOption
{
	int result;
	int index;
}IntOption;


IntOption analyzer(char c,int from, int to){
	IntOption result = {.result = 0 , .index = 0};
	if (c =='f'){
		int j = 0;
		for (int i = from; i < to; i++){
			if (i == 3){
				result.result = 1;
				result.index = j;
			}
			j++;
		}
	}else if(c == 'g'){
		int j = 0;
		for (int i = from; i < to; i++){
			if (i == 1000){
				result.result = 1;
				result.index = j;
			}
			j++;
		}
	}
	return result;
}

void main(){
	printf("(f, 0, 4) liefert: ");
	IntOption result1 = analyzer('f',0,4);
	printf("%d %d\n",result1.result, result1.index);
	
	printf("(f, 10, 20) liefert: ");
	IntOption result2 = analyzer('f',10,20);
	printf("%d %d\n",result2.result, result2.index);
	
	printf("(g, 999, 10000) liefert: ");
	IntOption result3 = analyzer('g',999,10000);
	printf("%d %d\n",result3.result, result3.index);
	
	printf("(g, 1000, 10000) liefert: ");
	IntOption result4 = analyzer('g',1000,10000);
	printf("%d %d\n",result4.result, result4.index);
}