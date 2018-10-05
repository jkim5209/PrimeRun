//
//  CountingFunctions.hpp
//  RunningFunctions
//
//  Created by Jaeyoon Kim on 9/10/18.
//  Copyright © 2018 Jaeyoon Kim. All rights reserved.
//

#ifndef CountingFunctions_hpp
#define CountingFunctions_hpp

#include <vector>
#include <thread>
#include <primesieve.hpp>
#include <cassert>

using namespace std;

// Returns a vector of values of the prime count/running functions at x
vector<uint64_t> prime_count(uint64_t x, int mod);
vector<uint64_t> prime_pair_count(uint64_t x, int mod);
vector<uint64_t> prime_run(uint64_t x, int mod);
vector<uint64_t> prime_pair_run(uint64_t x, int mod);


// Assumes count_in is an empty vector
// count_in[i] is sum over {primes start <= p_k <= end that satisfy
// index(p_k, p_{k+1}) = i} with value of ic(p_k, p_{k+1})
template <typename index_type, typename increment_type>
vector<uint64_t> get_functions(uint64_t start, uint64_t end, int vector_size, 
        index_type index, increment_type ic) {
    vector<uint64_t> count(vector_size);
    primesieve::iterator it(start, end + 1); // we need primes < x + 1

    uint64_t prev_prime = it.next_prime(); // p_k
    assert(prev_prime >= start);
    if (prev_prime > end)
        return count;

    uint64_t curr_prime = it.next_prime(); // p_{k+1}
    
    for (;prev_prime <= end; curr_prime = it.next_prime()) {
        count[index(prev_prime, curr_prime)] += ic(prev_prime, curr_prime);
        prev_prime = curr_prime;
    }
    return count;
}

// Fix for the last gap and the beginning
template <typename index_type>
void edge_case_fix(uint64_t x, vector<uint64_t> &count, index_type index) {
    primesieve::iterator it(x + 1);
    uint64_t prev = it.prev_prime();
    uint64_t curr = it.next_prime();
    uint64_t i = index(prev, curr);
    count.at(i) -= (curr - x);
    i = index(0, 2);
    count.at(i) += 2;
}

#endif
