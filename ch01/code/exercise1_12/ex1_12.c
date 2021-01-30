#include<stdio.h> 

#define IN  1
#define OUT 2

/* print input one word per line */
int main(){
    int c, state;

    c = 0;
    state = OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(state == IN){
                state = OUT;
                putchar('\n');
            }
        }
        else{
            state = IN;
            putchar(c);
        }
    }
    return 0;
}