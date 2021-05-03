// Abhiram Kakuturu
#include "prng.hpp"
#include <iostream>
#include <fstream>

// Call to main with seed argument [./raw.o (seed)]
int main(int argc, char** argv){
    std::ofstream output;
    int seed_list[] = {77777, 314159, 4563, 3569, 305, 89, 12, 3, 2};
    if(argc>1) seed_list[0]=atoi(argv[1]);
    int size = 9;

    for(int seed : seed_list){
        set_seed(seed);

        output.open("../Output/raw_randm"+std::to_string(seed)+".txt");
        for(int i=0; i<1002; i++){
            float res = randm();
            output << res << std::endl;
        }
        output.close();
        output.open("../Output/raw_randu"+std::to_string(seed)+".txt");
        for(int i=0; i<1002; i++){
            float res = randu();
            output << res << std::endl;
        }
        output.close();
        output.open("../Output/raw_rand"+std::to_string(seed)+".txt");
        for(int i=0; i<1002; i++){
            float res = f_rand();
            output << res << std::endl;
        }
        output.close();
    }
    return 0;
}