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
    int targets = -1;
    A.reserve(num_elements); //reserva na memória
    //preenche o vetor com randons de 0 á 999999;
    A = preenche_vetor(A);
    // ponteiro que aponta pro primeiro enderenço de memória de A
    int * begin = &(*A.begin());
    // ponteiro que aponta pro ultimo enderenço de memória de A
    int * end = begin + 1000000;
    // Executes several searchs in the data container.

    std::ofstream myfile;
    std::stringstream name;
    for(int i=0; i<7; i++){
        name << "logs/logFUNCTION"<<i<<".csv";
        myfile.open(name.str());
        myfile << "Size,Time\n";
        //myfile << ">> RUNING FUNCTION "<< i << " \n";
        for( auto j(0); j < 10; j++ ){

          auto aux = std::chrono::steady_clock::now();
          auto media = aux -aux;
          //std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
          for(auto l(0); l < 1; l++){
            // Look for target in the entire range.
            auto start = std::chrono::steady_clock::now();
            auto result = (*fp_array[i])(begin, end, end, targets);
            auto finish = std::chrono::steady_clock::now();
            auto diff = finish - start;
            media = media + (diff-media)/(l+1);
            // Process the result
            /*if ( result != end ){
                std::cout << ">>> Found \"" << targets << "\" at position "
                            << std::distance(begin ,result) << ".\n";
            }
            else
            {
                std::cout << ">>> Value \"" << targets << "\" not found in array!\n";
            }*/
          }
            //std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (media).count() << " ms" << std::endl;
            myfile  << *end << "," << std::chrono::duration <double, std::milli> (media).count() << "\n";
            end += 39960000;
        }
        end = begin + 1000000;
        myfile.close();
        name.str("");
    }

    return 0;
}
