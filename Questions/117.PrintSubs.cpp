#include <bits/stdc++.h>
using namespace std;
void PrintSubs(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    PrintSubs(input.substr(1), output);
    PrintSubs(input.substr(1), output + input[0]);
}
int main()
{
    string input;
    cin >> input;
    string output = "";
    PrintSubs(input, output);
}