#include "../include/header.h"
/**< função auxiliar que calcula o menor entre dois números */
int menor(int num1, int num2){
        if(num1 < num2){
          return num1;
        }else{
          return num2;
        }
}
/// Implements a fibonacci search on an array of integers.
/*!
 * \@param first Pointer to the first element in the range.
 * \@param last Pointer past the last valid element in the range.
 * \@param last Pointer past the last valid element in the range.
 * \@param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int *fibonacci_s(int *first, int *last,  int *abs_last, int value){
        auto lenght = (last - first);
        int fmin2 = 0;
        int fmin1 = 1;
        int fmin = fmin1 + fmin2;
        int offset = -1;
        auto i = (first);
        
        /**<inicia os números de fibonacci até o maior número ser menor que o tamanho do array*/ 
        while(fmin < lenght){
                fmin2 = fmin1;
                fmin1 = fmin;
                fmin = fmin1 + fmin2; 
        }
        /**< inicia a procura do valor enquanto o número de fibonacci seja maior que 1*/ 
        while(fmin > 1){
                /**< seta o endereço de memória de first mais menor entre o menor valor dos três 
                 * números de fibonacci -1 e o lenght da matriz -1*/ 
                i = (first + menor(offset+fmin2, lenght-1));    
                if(*i == value){
                        return i;
                }else if( *i < value){
                        fmin = fmin1;
                        fmin1 = fmin2;
                        fmin2 = fmin - fmin1;
                        offset =  *i;
                }else{
                        fmin = fmin2;
                        fmin1 = fmin1 - fmin2;
                        fmin2 = fmin - fmin1;
                } 
        }
        return last;
 
 }
