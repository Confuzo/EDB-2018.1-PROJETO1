#include "../include/header.h"
/**<@title Implementa uma busca linear em um vetor de números inteiros.*/
/*!
 *@param primeiro Ponteiro para o primeiro elemento no intervalo.
 *@param último Ponteiro após o último elemento válido no intervalo.
 *@param value O valor alvo que procuramos dentro do intervalo.
 *@return Um ponteiro para o valor alvo dentro do intervalo; ou o último, caso o valor não esteja no intervalo.*/
int * linear_s_i( int *first, int *last, int * abs_last, int value )
{
    while(first != last){
        if(*first == value){
            return first;
        }else{
            first++;
        }
    }
    return abs_last; // STUB
}
