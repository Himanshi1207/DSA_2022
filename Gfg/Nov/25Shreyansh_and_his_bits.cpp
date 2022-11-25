// Shreyansh has an integer N. He is really curious about the binary representation of integers. He sees that any given integer has a number of set bits. Now he wants to find out that how many positive integers, strictly less than N, have the same number of set bits as N.
// He is a little weak in maths. Help him find the number of integers.
// Note : Since N takes large values, brute force won't work.

// Example 1:

// Input:
// N = 8
// Output: 3
// Explanation:
// Binary representation of 8 : 1000
// So the integers less than 8 with
// same number of set bits are : 4, 2, 1
// Hence, the result is 3.


#include <iostream>
using namespace std;

class Solution
{

public:
    long long nck(long long n, long long k)
    {

        if (n == 0 || n < k)
            return 0;

        long long res = 1;

        if (k > n - k)

            k = n - k;

        for (int i = 0; i < k; ++i)
        {

            res *= (n - i);

            res /= (i + 1);
        }

        return res;
    }

    long long count(long long x)
    {

        long long r = 0;

        int number_of_set_bits = 0;

        for (int i = 0; i < 64; ++i)
        {

            if (x & 1)
            {

                number_of_set_bits++;

                long long nck_r = nck(i, number_of_set_bits);
                r += nck_r;
            }

            x = x >> 1;
        }

        return r;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long x;
        cin >> x;
        Solution ob;
        cout << ob.count(x) << '\n';
    }
    return 0;
}