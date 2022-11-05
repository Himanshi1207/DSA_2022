#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    for (long long i = 1; i <= t; i++)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        long sum = n * (n + 1) / 2;
        long summa = sum * x / (x + y);
        vector<long> answer;
        if (summa * (x + y) != sum * x)
        {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        }
        else
        {
            long ans = n;
            while (ans >= 1)
            {
                if (ans <= summa)
                {
                    summa = summa - ans;
                    answer.push_back(ans);
                }
                ans--;
            }
            reverse(answer.begin(), answer.end());
            cout << "Case #" << i << ": POSSIBLE" << endl;
            cout << answer.size() << endl;
            int size = answer.size(), j = 0;
            while (j < size)
            {
                cout << answer[j] << " ";
                j++;
            }
            cout << endl;
        }
    }
    return 0;
}
