//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
         if (str1.length() != str2.length())
            return false;

        int diffCount = 0;
        unordered_map<char, int> freq;

        for (int i = 0; i < str1.length(); i++)
            freq[str1[i]]++;

        for (int i = 0; i < str2.length(); i++) {
            if (freq.find(str2[i]) != freq.end() && freq[str2[i]] > 0) {
                freq[str2[i]]--;
            } else {
                diffCount++;
            }
        }

        return (diffCount <= k);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends