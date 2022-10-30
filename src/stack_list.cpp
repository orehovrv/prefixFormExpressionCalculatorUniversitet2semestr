#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "stack_list.h"

STACK_LIST::STACK_LIST() {
    tail = NULL;
}

STACK_LIST::~STACK_LIST() {
    node *temp;
    while(tail != NULL){
        temp = tail;
        tail = tail->next;
        free(temp);
    }
}

bool STACK_LIST::empty() {
    return tail == NULL;
}

bool STACK_LIST::full() {
    node *temp = (node*)malloc(sizeof(node));
    bool flag = 0;
    if(temp) flag = 1;
    free(temp);
    return flag;
}

double STACK_LIST::pop() {
    double num;
    node *temp = tail;

    if(empty()){
        return LLONG_MIN;
    }

    num = tail->num;
    tail = tail->next;
    free(temp);

    return num;
}

void STACK_LIST::push(double element) {
    node *temp = (node*)malloc(sizeof(node));
    temp->num = element;

    if(empty()){
        tail = temp;
        temp->next = NULL;
    } else {
        temp->next = tail;
        tail = temp;
    }
}
