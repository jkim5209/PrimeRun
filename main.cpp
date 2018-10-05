//
//  main.cpp
//  RunningFunctions
//
//  Created by Jaeyoon Kim on 9/10/18.
//  Copyright © 2018 Jaeyoon Kim. All rights reserved.
//

//#include <iostream>
#include <vector>
#include "CountingFunctions.hpp"
#include <iostream>
#include <primesieve.hpp>

using namespace std;

void print_2d(vector<uint64_t> &v, int mod) {
    for (int i = 0; i < v.size(); ++i) {
        cout << i / mod << " " << i % mod << "\t" << v.at(i) << "\n";
    }
    
}

void print_vec(vector<uint64_t> &v) {
    for (auto c: v) 
        cout << c << "\n";
}

using answer = vector<uint64_t>;
int main() {
    uint64_t mod = 3;
    uint64_t x = 1e10;
    answer count = prime_count(x, mod);
    cout << "counting\n";
    print_vec(count);
    answer double_count = prime_pair_count(x, mod);
    cout << "pair count\n";
    print_2d(double_count, mod);
    answer run = prime_run(x, mod);
    cout << "running\n";
    print_vec(run);
    answer run_pair = prime_pair_run(x,mod); 
    cout << "pair run\n";
    print_2d(run_pair, mod);
}
