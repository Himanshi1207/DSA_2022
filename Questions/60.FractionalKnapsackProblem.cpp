#include <bits/stdc++.h>
using namespace std;
bool compare(vector<int> v1, vector<int> v2)
{
    double d1 = v1[0] / v1[1];
    double d2 = v2[0] / v2[1];
    return d1 > d2;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    cout << endl;
    sort(a.begin(), a.end(), compare);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2;j++)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    int weight;
    cin >> weight;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight >= a[i][1])
        {
            ans += a[i][0];
            weight -= a[i][1];
            continue;
        }
        double vw = (double)a[i][0] / a[i][1];
        ans += vw * weight;
        weight = 0;
        break;
    }
    cout << ans << endl;
    return 0;
}