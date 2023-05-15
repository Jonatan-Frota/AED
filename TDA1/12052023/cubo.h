#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

typedef struct CUBO{
    float lado;
    float area;
    float volume;

}CUBO;


void inserir(CUBO *lados);
void printar(CUBO *lados);




#endif // CUBO_H_INCLUDED
