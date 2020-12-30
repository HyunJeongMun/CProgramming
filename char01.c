#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int is_in(char *s, char key, int j){
	int c = 0;
	int i;
	
	for(i = j; s[i] != '\0'; i++){
		if(s[i] != key)
			return c;
		c++;
	}

	return c;
}


int solution(char *s) {     
	int c;
	int len = 0;
	int i = 0;

	while(s[i] != '\0'){
		c = is_in(s, s[i], i);
		if(c > 1){
            printf("%d%c", c, s[i]);
            len += 2;
        }
			
		else{
            printf("%c", s[i]);
            len += 1;
        }		

		i = i + c;

	}

	return len;
} 
int main(void) {  
	char s[1001];  
	scanf("%s", s);  
	
	printf("\n%d\n", solution(s));
}