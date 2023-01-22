// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

bool isValid(string s1)
{

   if(s1.size()>3||s1.size()==0) return false;
   
   if(s1.size()>1 && s1[0]=='0') return false;
   
   // using stoi to convert string to integer 
   
   if(s1.size() && stoi(s1)>255) return false;
   
   
   
   return true;
}

void recur(int i, int dots, string temp, vector<string>& ans, string s)
{
	// we have to place 3 dots in the string to make 4 partitions
	
    if(dots==3)
    {
       // pushing last partition after checking its validity
			
        if(isValid(s.substr(i)))
        {
       
            ans.push_back(temp+s.substr(i));
            
        }
        return;
    }
	
    // placing the dot at every valid position
	
    for(int j=i; j<s.size() ;j++)
    {

	if( isValid(s.substr(i, j-i+1)))
	{
		temp.push_back(s[j]);
		temp.push_back('.');

		recur(j+1, dots+1, temp, ans, s);

	   // removing the dot after calling recur function 

	   // note that we don't remove the last digit that was placed in temp string as we just have to change positions of dots only and not digits in string
		temp.pop_back();


        }
    }
    
    return;
    
}

vector<string> restoreIpAddresses(string s) {
    
    vector<string> ans;
    
    if(s.size()<4) return ans;
    
    recur(0, 0, "", ans, s);
    
    return ans;
}
};