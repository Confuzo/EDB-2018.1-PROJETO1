#include "../include/header.h"
// Driver function.
const int num_elements = 1000000000;//numero de elementos a ser alocado
std::vector<int> preenche_vetor(std::vector<int> A){
    int i;
    for(i =0; i < num_elements; i++){
        A.push_back(i);
    }
    return A;
}
int main(){
    int* (*fp_array[])(int*, int*, int*, int) = {linear_s_i, binary_s_i, binary_s_r, ternary_s_i, ternary_s_r, jump_s, fibonacci_s};
    std::vector<int> A; // Data container.
    //int targets[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 3, 59, -6}; // Target values for testing.
    int targets[] = {-6};
    A.reserve(num_elements); //reserva na memória
    //preenche o vetor com randons de 0 á 999999;
    A = preenche_vetor(A);
    // Prints out the original data container.
    // ponteiro que aponta pro primeiro enderenço de memória de A
    int * begin = &(*A.begin());
    // ponteiro que aponta pro ultimo enderenço de memória de A
    int * end = &(*A.end());
    // Executes several searchs in the data container.
    for(int i=0; i<7; i++){
        std::cout<< ">> RUNING FUNCTION "<< i <<std::endl;
        for( const auto & e : targets ){
            // Look for target in the entire range.
            auto result = (*fp_array[i])(begin, end, end, e );
            // Process the result
            if ( result != end ){
                std::cout << ">>> Found \"" << e << "\" at position "
                            << std::distance(begin ,result) << ".\n";
            }
            else
            {
                std::cout << ">>> Value \"" << e << "\" not found in array!\n";
            }
        }
    }

    return 0;
}
