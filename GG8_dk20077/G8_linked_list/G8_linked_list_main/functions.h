#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct elem {
    int num;
    elem *next;
    elem(int n) { num = n; next = NULL; }
};

void print(elem *first);
void rem(elem *&first);
void append(elem *&first, elem *&last, int n);
void reverse(elem *&first);

#endif // FUNCTIONS_H_INCLUDED
