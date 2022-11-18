// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

 

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> primes = {2, 3, 5};
    bool isUgly(int n) {
        if (n < 1) return false;
        for (int p: primes) while (n % p == 0) n /=p;
        return n == 1;
    }
};