all: generate_raw generate_hist

generate_raw: generate_raw.cpp
	g++ -std=c++17 -o raw.o prng.cpp generate_raw.cpp

generate_hist: generate_hist.cpp
	g++ -std=c++17 -o hist.o prng.cpp generate_hist.cpp