#ifndef DL_H_INCLUDED
#define DL_H_INCLUDED

struct DLL {
    int value;
    struct DLL* past;
    struct DLL* next;
};
struct DLL* counter1;
struct DLL* d;

struct DLL* allocate ();
struct DLL* greatest (struct DLL** n1);

#endif