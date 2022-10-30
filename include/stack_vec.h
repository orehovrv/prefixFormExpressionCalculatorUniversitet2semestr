#ifndef STACK_VEC_H
#define STACK_VEC_H

class STACK_VEC {
    private:
        double *mass;
        int count, top;

    public:
        STACK_VEC();
        ~STACK_VEC();
        bool empty();
        bool full();
        double pop();
        void push(double);
};

#endif // STACK_VEC_H
