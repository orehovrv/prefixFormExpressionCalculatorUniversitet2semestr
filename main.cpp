#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define reg

#ifdef reg
#include "stack_vec.h"
#else
#include "stack_list.h"
#endif

double conv(char*, int*);
char check_str(char*);

int main() {
    char str[100];
    int i;
    double a, b;

#ifdef reg
    STACK_VEC stack;
#else
    STACK_LIST stack;
#endif

    gets(str);
    if(!check_str(str)){
        printf("Error");
        return 1;
    }

    for(i = strlen(str)-1; i>=0; i--){
        if(str[i] >= '0' && str[i] <= '9')
            stack.push(conv(str, &i));
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            a = stack.pop();
            b = stack.pop();

            if(a == LLONG_MIN || b == LLONG_MIN){
                printf("Error");
                return 10;
            }

            switch(str[i]) {
                case '+': stack.push(a+b); break;
                case '-': stack.push(a-b); break;
                case '*': stack.push(a*b); break;
                case '/': stack.push(a/b); break;
            }
        }
    }

    double answer = stack.pop();
    if(stack.pop() != LLONG_MIN){
        printf("Error");
        return 5;
    }

    printf("answer: %lf", answer);
    return 0;
}

char check_str(char *str){
    while(*str){
        if(!strchr("1234567890+-*/., ", *str++))
            return 0;
    }
    return 1;
}

double conv(char *str, int *i){
    while(str[*i] != ' ' && (*i)--);
    return atof(str + *i);
}
