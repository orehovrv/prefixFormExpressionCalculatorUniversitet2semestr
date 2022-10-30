#ifndef STACK_LIST_H
#define STACK_LIST_H

typedef struct _node{
    double num;
    struct _node *next;
} node;

class STACK_LIST {
    private:
        node *tail;

    public:
        STACK_LIST();
        ~STACK_LIST();
        bool empty();
        bool full();
        double pop();
        void push(double);
};

#endif // STACK_LIST_H
