#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "stack_vec.h"

STACK_VEC::STACK_VEC() {
    top = -1;
    count = 5;
    mass = (double*)malloc(count * sizeof(double));
}

STACK_VEC::~STACK_VEC() {
    free(mass);
}

bool STACK_VEC::empty() {
    return top < 0;
}

bool STACK_VEC::full() {
    return top == (count - 1);
}

double STACK_VEC::pop() {
    if(empty())
        return LLONG_MIN;
    return mass[top--];
}

void STACK_VEC::push(double element) {
    if(full()){
        count += 5;
        mass = (double*)realloc(mass, count * sizeof(double));
    }
    mass[++top] = element;
}
