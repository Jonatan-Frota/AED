#include <stdio.h>
#include <stdlib.h>
#include "dl.h"


/*Allocates memory for every pointer of type struct DLL*/
struct DLL* allocate () {
    struct DLL* ptr = (struct DLL*) malloc (sizeof(struct DLL));
    ptr->next = (struct DLL*) malloc (sizeof(struct DLL));
    ptr->past = (struct DLL*) malloc (sizeof(struct DLL));

    return ptr;
}


struct DLL* greatest (struct DLL** n1) {

    counter1 = d = *n1;

    //printf("%p\t", counter1->next);

    while (counter1 != NULL) {
        if (counter1->value > d->value) {
            d = counter1;
        }
        counter1 = counter1->next;
    }

    if (d->value == (*n1)->value) {
        *n1 = (*n1)->next;
    } else {
        d->past->next = d->next;
    }
    

    /*counter1 = *n1;
    while (counter1 != NULL) {
        printf("%d\t", counter1->value);
        counter1 = counter1->next;
    }*/

    return d;
}
