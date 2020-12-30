#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int is_in(char *s, char *key){
	int c = 0;
	int i = strlen(key);
	char cpy[2];
    
    while(s != '\0'){
		strncpy(cpy, s, 2);
		cpy[i] = '\0';

        if(strcmp(cpy, key) != 0)
            return c;
        
        c++;
        s += i;
    }

	return c;
}

int solution(char *s) {     
	int c;
    int len = 0;
    char key[2];

    while(s != '\0'){
        strncpy(key, s, 2);
        key[2] = '\0';
        
        c = is_in(s, key);
        
        if(c > 1){
            len += (c + 1);
            printf("%d%s", c, key);        
        }
        else{
            len += strlen(key);
            printf("%s", key);
        }
        
        s += strlen(key);
    }
    
    return len;
} 

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("%d\n", solution(s));
}