#define header
#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()
#include <vector> // vetor propriets

int *binary_s_i( int *first, int *last, int *abs_last, int value ); /**< busca binária iterativa*/ 
int *binary_s_r( int *first, int *last, int *abs_last, int value ); /**< busca binária recursiva*/
int *ternary_s_i(int *first, int *last, int *abs_last, int value);/**< busca ternária iterativa*/
int *ternary_s_r(int *first, int *last, int *abs_last ,int value);/**< busca ternária recursiva*/