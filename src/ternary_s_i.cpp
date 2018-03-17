#include "../include/header.h"
/**<@title Implementa uma busca ternária iterativa em um vetor de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/
int *ternary_s_i(int * first, int * last, int * abs_last, int value){

  auto ini (first);
  auto end (last);
  int * t1;
  int * t2;

  while(end-ini >= 1){
    t1 = ini + ((end - ini)/3);
    t2 = end - ((end - ini)/3);

    if (*t1 == value){
      return t1;
    }
    if(*t2 == value){
      return t2;
    }
    if(value < *t1){
      end = t1;
    }
    if(value > *t2){
      ini = t2;
    }
    if(value > *t1 and value < *t2){
      if(t2-t1>3){
        ini = t1;
        end = t2;
      }else{
        return t1+1;
      }
    }
  }
  return last;
}
