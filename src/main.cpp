#include "../include/header.h"
// Driver function.
const int num_elements = 1000000000;//numero de elementos a ser alocado
/**<Função auxiliar que preenche um vetor com n elementos ordenados*/
std::vector<int> preenche_vetor(std::vector<int> A){
    int i;
    for(i =0; i < num_elements; i++){
        A.push_back(i);
    }
    return A;
}

int main(int argc, char *argv[]){ /**<Função Main*/
    int num_amostras;
    int amostras = 25;
    /*<Recebe o número de amostras do usuário, por padrão o valor é 25*/
    if(argc > 1 && argc < 3){
         num_amostras = atoi(argv[1]);
         if(num_amostras > 0 and num_amostras <= 25){
          amostras = num_amostras;
         }
    }
    int* (*fp_array[])(int*, int*, int*, int) = {linear_s_i, binary_s_i, binary_s_r, ternary_s_i, ternary_s_r, jump_s, fibonacci_s};
    std::vector<int> A; // Data container.

    int targets = -1;
    A.reserve(num_elements); //reserva na memória
    /**<preenche o vetor A com numerados já ordenados*/
    A = preenche_vetor(A);
    /**< ponteiro que aponta pro primeiro enderenço de memória de A */
    int * begin = &(*A.begin());
    /**< ponteiro que aponta pro ultimo enderenço de memória de A*/
    int * end = begin + 1000000;

    /**<Executa os 7 algoritmos de busca.*/
    std::ofstream myfile;
    std::stringstream name;
    for(int i=0; i<7; i++){
        name << "logs/logFUNCTION"<<i<<".csv";
        myfile.open(name.str());
        myfile << "Size,Time\n";

        /**<Executa várias buscar no vetor de dados usando amostras diferentes.*/
        for( auto j(0); j < amostras; j++ ){

          auto aux = std::chrono::steady_clock::now();
          auto media = aux -aux;

          for(auto l(0); l < 100; l++){
            /*<Mede o tempo de execução da função em relação a uma amostra de tamanho n, gerando assim uma média.*/
            auto start = std::chrono::steady_clock::now();
            auto result = (*fp_array[i])(begin, end, end, targets);
            auto finish = std::chrono::steady_clock::now();
            auto diff = finish - start;
            media = media + (diff-media)/(l+1);

          }
            myfile  << *end << "," << std::chrono::duration <double, std::milli> (media).count() << "\n";
            end += 39960000;
        }
        end = begin + 1000000;
        myfile.close();
        name.str("");
    }

    return 0;
}
