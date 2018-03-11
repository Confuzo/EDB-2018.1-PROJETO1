#include "../include/header.h"

int menor(int num1, int num2){
        if(num1 < num2){
          return num1;
        }else{
          return num2;
        }
}
int *fibonacci_s(int *first, int *last,  int *abs_last, int value){
        auto lenght = (last - first);
        auto ini (first);
        int fmin2 = 0;
        int fmin1 = 1;
        int fmin = fmin1 + fmin2;
        int offset = -1;
        auto i = ini;
        int * res;
        while(fmin < lenght){
                fmin2 = fmin1;
                fmin1 = fmin;
                fmin = fmin1 + fmin2; 
        }
        while(fmin > 1){ 
                *i = menor(offset+fmin2, lenght-1);
                
                if(*i < value){
                        fmin = fmin1;
                        fmin1 = fmin2;
                        fmin2 = fmin - fmin1;
                        offset = *i;
                }else if(*i > value){
                        fmin = fmin2;
                        fmin1 = fmin1 - fmin2;
                        fmin2 = fmin - fmin1;
                }else{
                        return i; 
                }

        }
        return last;
 
 }
