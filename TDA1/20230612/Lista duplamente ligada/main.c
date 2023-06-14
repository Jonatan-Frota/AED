#include <stdio.h>
#include <stdlib.h>
#include "dl.h"


int main(int argc, char const *argv[])
{

    /*Creating the nodes for K list*/
    struct DLL* a = allocate();
    struct DLL* b = allocate();
    struct DLL* c = allocate();
    struct DLL* d = allocate();

    /*Creating and initializing a list without ordenating it*/
    struct DLL* n1 = allocate();
    struct DLL* n2 = allocate();
    struct DLL* n3 = allocate();
    struct DLL* n4 = allocate();

    counter1 = allocate();
    d = allocate();

    n1->value = 6;
    n2->value = -5;
    n3->value = 10;
    n4->value = -8;

    n1->past = NULL;
    n2->past = n1;
    n3->past = n2;
    n4->past = n3;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    /*This function finds the greatest value and insert it into the K list*/
    d = greatest(&n1);
    c = greatest(&n1);
    b = greatest(&n1);
    a = greatest(&n1);

    printf("Vetor ordenado: ");
    printf("\n%i\n%i\n%i\n%i\n", d->value, c->value, b->value, a->value);

    return 0;
}