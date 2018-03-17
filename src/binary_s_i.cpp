#include "../include/header.h"
/**<@title Implementa uma busca binária interativa em uma matriz de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/
int *binary_s_i( int *first, int *last, int * abs_last, int value ){
  auto ini (first);
  auto end (last);
  int * m;
  while(ini != end){

    m = ini + ((end-ini)/2);
    if(*m == value){
      return m;
    }else if(value < *m){
      end = m;
    }else{
      ini = m++;
      if(ini == (last-1)){
        return last;
      }
    }
  }
  return last;
}