// Runner file for rnd_test.hpp
// abhivk -- PHYS250 FALL 2020
#include "prng.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
using std::cout;
using std::endl;

// General function to output Histogram Analysis of each PRNG
void histogram_analysis(ofstream* random_output, ifstream* random_input, int average, float std_err, int CL, int sample_size){
    // Generate random numbers using randu()
    (*random_output).open("../Output/randu_out.txt");
    generate_randomnumber_file(random_output, sample_size, 2, randu);
    (*random_output).close();

    // Generate random numbers using randm()
    (*random_output).open("../Output/randm_out.txt");
    generate_randomnumber_file(random_output, sample_size, 2, randu);
    (*random_output).close();

    // Generate random numbers using C++ built-in RAND()
    (*random_output).open("../Output/rand_out.txt");
    generate_randomnumber_file(random_output, sample_size, 2, randu);
    (*random_output).close();

    // RANDU() histogram
    (*random_input).open("../Output/randu_out.txt");
    map<int, int> hist = random_hist(random_input);
    (*random_input).close();

    cout << "===================RANDU() ANALYSIS========================" << endl;
    cout << "Expected Hits Per Bin: " << sample_size/10 << endl;
    cout << "These bins fell more than " << CL << " standard errors away." << endl;
    cout << "BIN #  ||  HITS in BIN  ||  Deviation from Mean" << endl;
    for(auto kv : hist) {
        float dev = abs(kv.second-average)/std_err;
        if(dev>=CL) cout << kv.first << " " << kv.second << " " << (kv.second-average)/std_err << endl;
    }

    // RANDM() histogram
    (*random_input).open("../Output/randm_out.txt");
    hist = random_hist(random_input);
    (*random_input).close();
    cout << "===================RANDM() ANALYSIS========================" << endl;
    cout << "Expected Hits Per Bin: " << sample_size/10 << endl;
    cout << "These bins fell more than " << CL << " standard errors away." << endl;
    cout << "BIN #  ||  HITS in BIN  ||  Deviation from Mean" << endl;
    for(auto kv : hist) {
        float dev = abs(kv.second-average)/std_err;
        if(dev>=CL) cout << kv.first << " " << kv.second << " " << (kv.second-average)/std_err << endl;
    }

    // RAND() histogram
    (*random_input).open("../Output/rand_out.txt");
    hist = random_hist(random_input);
    (*random_input).close();
    cout << "===================RAND() ANALYSIS========================" << endl;
    cout << "Expected Hits Per Bin: " << sample_size/10 << endl;
    cout << "These bins fell more than " << CL << " standard errors away." << endl;
    cout << "BIN #  ||  HITS in BIN  ||  Deviation from Mean" << endl;
    for(auto kv : hist) {
        float dev = abs(kv.second-average)/std_err;
        if(dev>=CL) cout << kv.first << " " << kv.second << " " << (kv.second-average)/std_err << endl;
    }
}

// Call to main: [./hist.o (seed) (sample size) (CL)]
int main(int argc, char** argv){
    int sample_size=1000;
    int CL=2;
    if(argc>1) set_seed(atoi(argv[1]));
    if(argc>2) sample_size=atoi(argv[2]);
    if(argc>3) CL=atoi(argv[3]);

    // establish significance thresholds
    int average = sample_size/10;
    float std_err= sqrt(average);

    // configure I/O objects 
    std::ofstream random_output;
    std::ifstream random_input;

    //*** HISTOGRAM ANALYSES ***//
    histogram_analysis(&random_output, &random_input, average, std_err, CL, sample_size);

    // Perform histogram analysis while varying the seed
    int num_seeds=10;
    int seed_list[] = {77777, 55522, 4563, 3569, 305, 89, 12, 3, 2};
    for(int seed : seed_list){
        set_seed(seed);
        histogram_analysis(&random_output, &random_input, average, std_err, CL, sample_size);
    }

    return 0;
}