#include "../include/header.h"

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