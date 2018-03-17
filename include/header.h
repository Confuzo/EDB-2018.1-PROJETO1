#define header
#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()
#include <vector> // vetor propriets
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <sstream>

int *linear_s_i( int *first, int *last, int *abs_last, int value ); /**< Busca linear iterativa.*/
int *binary_s_i( int *first, int *last, int *abs_last, int value ); /**< Busca binária iterativa.*/
int *binary_s_r( int *first, int *last, int *abs_last, int value ); /**< Busca binária recursiva.*/
int *ternary_s_i(int *first, int *last, int *abs_last, int value);  /**< Busca ternária iterativa.*/
int *ternary_s_r(int *first, int *last, int *abs_last ,int value);  /**< Busca ternária recursiva.*/
int *jump_s(int *first, int *last,  int *abs_last, int value); /**< Busca por saltos.*/
int *fibonacci_s(int *first, int *last,  int *abs_last, int value);/**< Busca por método de fibonacci.*/
