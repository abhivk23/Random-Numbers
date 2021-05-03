// (Pseudo) Random Number Generators Header
// abhivk -- PHYS250 FALL 2020

//*** Dependencies ***//
#include <stdlib.h>
#include <map>
#include <fstream>
using std::map;
using std::ofstream;
using std::ifstream;

// Get global seed variable
int get_seed();

// Set global seed variable; default 77777
void set_seed(int x);

// Return random decimal between 0 and 1
float randm(void);

// Return random decimal between 0 and 1
float randu(void);

// Return float between 0 and 1 using built-in rand()
float f_rand(void);

// Generate file of n random numbers via specified PRNG
// input: [output file], [sample size], [digit sampled], [PRNG to be used]
void generate_randomnumber_file (ofstream* output_file, int n, int k, float prng_func(void));

// Return histogram (mapped values 0->9) from file of integers separated by newlines
map<int, int> random_hist(ifstream* input_file);