#include "../include/header.h"

/**<@title Implementa uma busca de saltos em um vetor de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/

 int *jump_s(int *first, int *last,  int *abs_last, int value){

   int m = sqrt(std::distance(first,last));
   auto ini (first);
   auto end (last);
   auto km = ini + m;
   while(ini != end){

     if(*km == value){
       return km;
     }else if(value < *km){
        return linear_s_i(ini,km,last,value);
     }else{
       ini = km;
       if (ini + m <=last){
         km = ini + m;
       }else{
         return linear_s_i(ini,last,last,value);
       }
     }
   }

   return abs_last;
 }
