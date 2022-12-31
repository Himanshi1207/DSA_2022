// Given a string S of lowercase english characters. Rearrange characters of the given string such that the vowels and consonants occupy alternate positions and the string so formed should be lexicographically (alphabetically) smallest. 
// Note: Vowels are 'a', 'e', 'i', 'o' and 'u'. 

// Example 1:

// Input:
// S = "aeroplane"
// Output: alanepero
// Explanation: alanepero  
// The vowels and cosonants are arranged 
// alternatively with vowels shown in bold.
// Also, there's no lexicographically smaller
// string possible with required conditions.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string rearrange (string S, int N)
    {
        vector<int> vow(26,0) , cons(26);
        int c1=0,c2=0;
        for(auto &it : S)
        {
            if(it=='a' || it=='i' || it=='e' || it=='o' || it=='u') vow[it-'a']++;
            else 
            {
                c2++;
                cons[it-'a']++;
                continue;
            }
            c1++;
        }
        if(abs(c1-c2)>1) return "-1";
        string ans;
        int l=0,r=0;
        bool f=true;
        while(l<26 && vow[l]==0) l++;
        while(r<26 && cons[r]==0) r++;
        if(c1>c2) 
        {
            ans+= (char)('a'+l);
            vow[l]--;
            f=false;
        }
        else if(c2>c1)
        {
            ans+= (char)('a'+r);
            cons[r]--;
        }
        while(l<26&& r<26)
        {
         while( l<26 && vow[l]==0) l++;
         while(r<26 && cons[r]==0) r++;
          if(f) 
          {
            ans+= (char)('a'+l);
            vow[l]--;
          }
          else 
          {
             ans+= (char)('a'+r);
            cons[r]--;
          }
          f= !f;
        }
        return ans;
        
    }
};


int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}