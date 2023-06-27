//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class data{
    public:
    int val;
    int r;
    int c;
    data(int d, int rowV, int colV)
    {
        this->val=d;
        this->r=rowV;
        this->c=colV;
    }
};

struct myComp{
bool operator()(data &d1, data &d2)
{
    return d1.val>d2.val; //for min-heap
}
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<data,vector<data>,myComp>pq;
        for(int i=0;i<arr.size();i++)
        {
            data d(arr[i][0],i,0);
            pq.push(d);
            
        }
        
        while(!pq.empty())
        {
            data curr=pq.top();
            pq.pop();
            int rval=curr.r, cval=curr.c, value=curr.val;
            ans.push_back(value);
            if(cval+1<arr.size())
            {
                data d(arr[rval][cval+1],rval,cval+1);
                pq.push(d);
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends