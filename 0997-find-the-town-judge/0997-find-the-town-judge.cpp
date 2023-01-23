class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>votes;
        unordered_map<int,int>firstEle;
        int size=trust.size();
        if(n==1 && trust.size()==0)
            return n;
        for(int i=0;i<size;i++)
        {
            votes[trust[i][1]]++;
            firstEle[trust[i][0]]++;
        }
        int possAns= -1;
        
        for(auto x:votes)
        {
           // cout<<x.first<<" "<<x.second;
           //  cout<<endl;
            if(x.second==n-1)
                possAns=x.first;
        }
        //cout<<possAns;
        for(auto y:firstEle)
        {
            if(y.first==possAns)
                return -1;
        }
        return possAns;
    }
};