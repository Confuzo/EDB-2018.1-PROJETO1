#define header
#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()
#include <vector> // vetor propriets
#include <cmath>

int *linear_s_i( int *first, int *last, int *abs_last, int value ); /**< busca linear iterativa*/ 
int *binary_s_i( int *first, int *last, int *abs_last, int value ); /**< busca binária iterativa*/ 
int *binary_s_r( int *first, int *last, int *abs_last, int value ); /**< busca binária recursiva*/
int *ternary_s_i(int *first, int *last, int *abs_last, int value);/**< busca ternária iterativa*/
int *ternary_s_r(int *first, int *last, int *abs_last ,int value);/**< busca ternária recursiva*/
int *jump_s(int *first, int *last,  int *abs_last, int value);
int *fibonacci_s(int *first, int *last,  int *abs_last, int value);