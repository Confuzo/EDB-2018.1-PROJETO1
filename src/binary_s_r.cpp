#include "../include/header.h"
/**<@title Implementa uma busca binária recursiva em uma matriz de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/
int *binary_s_r( int *first, int *last,  int * abs_last, int value )
{
  auto ini (first);
  auto end (last);
  int * m;

    if(ini != end and end-ini>1){
      m = ini + ((end-ini)/2);
      if(*m == value){
        return m;
      }else if(value < *m){
        return binary_s_r(ini,m,abs_last,value);
      }
        return binary_s_r(m++,end,abs_last,value);
    }
    if(end - ini == 1 and *ini == value){
      return ini;
    }

  return abs_last;
}