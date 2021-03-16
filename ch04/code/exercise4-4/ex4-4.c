/* Add command to print the top element of the stack
   without popping, to duplicate it, and to swap the
   top two elements. Add a command to clear the stack.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVALUE 100    /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

void showTop(void);
void duplicate(void);
void clearStack(void);
void swapTopTwoItem(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type= getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break; 
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '%':
            op2 = pop();
            push(fmod(pop(),op2));
            break;
        case 't':
            showTop();
            break;
        case 'd':
            duplicate();
            break;
        case 'S':
            swapTopTwoItem();
            break;
        case 'c':
            clearStack();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknow command %s\n",s);
            break;
        }
    }
    return 0;
}

int sp = 0;             /* next free stack position */
double val[MAXVALUE];   /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if(sp < MAXVALUE)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f); 
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* showTop: print the top element of the stack without popping */
void showTop(void)
{
    if(sp > 0)
        printf("%.8g\n",val[sp - 1]);    
    else
    {
        printf("error: stack empty\n");
    }
}

/* duplicate: duplicate the top element of stack */
void duplicate(void)
{
    double tmp = pop();
    push(tmp);
    push(tmp);
}

/* clearStack: clear the stack */
void clearStack(void)
{
    sp = 0;
}

/* swapTopTwoItem: swap the top two elements */
void swapTopTwoItem(void)
{
    double item1 = pop();
    double item2 = pop();
    push(item1);
    push(item2);
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getchar()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}