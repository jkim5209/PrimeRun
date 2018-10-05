//
//  CountingFunctions.cpp
//  RunningFunctions
//
//  Created by Jaeyoon Kim on 9/10/18.
//  Copyright © 2018 Jaeyoon Kim. All rights reserved.
//

#include "CountingFunctions.hpp"
#include <iostream>
#include <primesieve.hpp>


vector<uint64_t> prime_count(uint64_t x, int mod) {
    auto index = [&mod](uint64_t prev, uint64_t curr){return prev % mod;};
    auto increment = [](uint64_t prev, uint64_t curr){return 1;};
    return get_functions(0, x, mod, index, increment);
}

vector<uint64_t> prime_pair_count(uint64_t x, int mod) {
    auto index = [&mod](uint64_t prev, uint64_t curr)
        {return mod * (prev % mod) + curr % mod;};
    auto increment = [](uint64_t prev, uint64_t curr){return 1;};
    return get_functions(0, x, mod * mod, index, increment);
}

vector<uint64_t> prime_run(uint64_t x, int mod) {
    auto index = [&mod](uint64_t prev, uint64_t curr){return prev % mod;};
    auto increment = [](uint64_t prev, uint64_t curr){return curr - prev;};
    vector<uint64_t> val = get_functions(0, x, mod, index, increment);
    edge_case_fix(x, val, index);
    return val;
}

vector<uint64_t> prime_pair_run(uint64_t x, int mod) {
    auto index = [&mod](uint64_t prev, uint64_t curr)
        {return mod * (prev % mod) + curr % mod;};
    auto increment = [](uint64_t prev, uint64_t curr){return curr - prev;};
    vector<uint64_t> val = get_functions(0, x, mod * mod, index, increment);
    edge_case_fix(x, val, index);
    return val;
}
