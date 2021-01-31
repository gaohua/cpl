#include<stdio.h>

#define OUT 0
#define IN  1 

int main(){
    int c, state, len;
    state = OUT;    
    len = 0;

    while((c = getchar())){
        if(c == ' ' || c == '\n' || c == '\t'){
            for(int i = 0; i < len; i++){
                printf("#");
            }
            printf("\n");
            len = 0;
        }
        else{ 
            putchar(c);
            len++;
        }
    }
}