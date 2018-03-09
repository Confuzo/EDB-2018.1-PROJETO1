#include "../include/header.h"
/// Implements an interative binary search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
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