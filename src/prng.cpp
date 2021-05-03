// Random Number Generators
// Abhiram Kakuturu -- PHYS250 FALL 2020
#include "prng.hpp"

int seed=77777;
int precis;
int IMAX = 2147483647;
double XMAX_INV = 1./IMAX;

int get_seed(){
    return seed;
}

void set_seed(int x){
    seed=x;
    return;
}

float randm(void){
    int y=seed*6539;
    if(y<0) y=y+IMAX+1;
    int rn1=y;
    seed=y;
    return (rn1 * .4656613E-9);
}

float randu(void){
    // if(seed==0) seed=314159;
    seed*= 65539;
    if(seed<0) seed=seed+IMAX+1;
    return (seed * XMAX_INV);
}

// Overload default rand() function with float return type
float f_rand(void){
    srand(seed);
    seed*=6539;
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

// Generate file of n random numbers, extracting the k+1 integer from the decimal string
void generate_randomnumber_file (ofstream* output_file, int n, int k, float prng_func(void)){
    // Generate and write (k+1)th digit of n random numbers
    for(int i=0; i<n; i++){
        float rn1=prng_func();
        // extract (k+1)th digit
        rn1*=(k+1)*10;
        rn1-= int(rn1);
        int val = int(10*rn1);
        *output_file << val << std::endl;
    }
    return;
}

// Return histogram (mapped values 0->9) from file of integers separated by newlines
map<int, int> random_hist(ifstream* input_file){
    // Container for binning occurences of each integer 0-9
    map<int, int> hist;
    for(int i=0; i<10; i++) hist[i]=0; // initialzed with zeros

    // If file is open, iterate through and bin each appearance
    if((*input_file).is_open()){
        // Bin the number
        std::string line;
        int rand_num;
        while(getline(*input_file, line)) hist[stoi(line)]++;
    }
    return hist;
}