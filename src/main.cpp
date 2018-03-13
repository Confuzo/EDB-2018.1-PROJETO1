#include "../include/header.h"
// Driver function.

int main(){
    int* (*fp_array[])(int*, int*, int*, int) = {linear_s_i, binary_s_i, binary_s_r, ternary_s_i, ternary_s_r, jump_s, fibonacci_s};
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Data container.
    int targets[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 3, 59, -6}; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";
    auto ini (std::begin(A));
    // Executes several searchs in the data container.
    for(int i=0; i<7; i++){
        std::cout<< ">> RUNING FUNCTION "<< i <<std::endl;
        for( const auto & e : targets ){
            // Look for target in the entire range.
            auto result = (*fp_array[i])(std::begin(A), std::end(A), std::end(A), e );
            // Process the result
            if ( result != std::end(A) ){
                std::cout << ">>> Found \"" << e << "\" at position "
                            << std::distance(std::begin(A),result) << ".\n";
            }
            else
            {
                std::cout << ">>> Value \"" << e << "\" not found in array!\n";
            }
        }
    }

    return 0;
}
