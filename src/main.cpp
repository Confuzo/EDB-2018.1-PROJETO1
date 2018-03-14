#include "../include/header.h"
// Driver function.
std::vector<int> preenche_vetor(std::vector<int> A){
    int i;
    int num_elements = 1000000;
    int r =0;
    for(i =0; i < num_elements; i++){
        r = rand()%num_elements;
        A.push_back(r);
    }
    return A;
}
int main(){
    int* (*fp_array[])(int*, int*, int*, int) = {linear_s_i, binary_s_i, binary_s_r, ternary_s_i, ternary_s_r, jump_s, fibonacci_s};
    std::vector<int> A; // Data container.
    int targets[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 3, 59, -6}; // Target values for testing.
    int num_elements = 1000000;//numero de elementos a ser alocado 
    A.reserve(num_elements); //reserva na memória
    //preenche o vetor com randons de 0 á 999999;
    A = preenche_vetor(A);
    // Prints out the original data container.
    // ponteiro que aponta pro primeiro enderenço de memória de A 
    int * begin = &(*A.begin())+1;
    // ponteiro que aponta pro ultimo enderenço de memória de A
    int * end = &(*A.end());
    std::cout << "Array: [ ";
    std::copy( begin, end, std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";
    std::cout << begin<<"\n";
    std::cout << end<<"\n";
    // Executes several searchs in the data container.
    for(int i=0; i<7; i++){
        std::cout<< ">> RUNING FUNCTION "<< i <<std::endl;
        for( const auto & e : targets ){
            // Look for target in the entire range.
            auto result = (*fp_array[i])(begin, end, end, e );
            // Process the result
            if ( result != begin ){
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
