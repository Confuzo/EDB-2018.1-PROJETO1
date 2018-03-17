#include "../include/header.h"
/**<@title Implementa uma busca ternária recursiva em um vetor de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/
int *ternary_s_r(int * first, int * last, int * abs_last ,int value){
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
      return ternary_s_r(ini,t1,abs_last,value);
    }
    if(value > *t2){
      return ternary_s_r(t2,end,abs_last,value);
    }
    if(value > *t1 and value < *t2){
      if(t2-t1>3){
        return ternary_s_r(t1,t2,abs_last,value);
      }else{
        return t1+1;
      }
    }

  }
  return abs_last;
}
