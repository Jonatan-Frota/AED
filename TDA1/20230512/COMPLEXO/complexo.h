#ifndef COMPLEXO_H_INCLUDED
#define COMPLEXO_H_INCLUDED


typedef struct COMPLEXO{
float x;
float y;

}NUMERO;


void soma(NUMERO *numero1, NUMERO *numero2);
void sub(NUMERO *numero1, NUMERO *numero2);
void mult(NUMERO *numero1, NUMERO *numero2);
void divisao(NUMERO *numero1, NUMERO *numero2);
void liberar(NUMERO *numero1, NUMERO *numero2);

#endif // COMPLEXO_H_INCLUDED
