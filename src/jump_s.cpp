#include "../include/header.h"

/// Implements a jump search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */

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
