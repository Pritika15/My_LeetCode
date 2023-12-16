class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        int maxDeg=0,maxDegNum;
        for(auto itr:m)
        {
            if(itr.second>maxDeg)
            {
                maxDeg=itr.second;
                maxDegNum=itr.first;
            }
        }
        vector<int>maxDegNums;
        maxDegNums.push_back(maxDegNum);
        for(auto itr:m)
        {
            if(itr.second==maxDeg && itr.first!=maxDegNum)
            {
                maxDegNums.push_back(itr.first);
            }
        }
        // cout<<maxDeg<<" "<<maxDegNum<<endl;
        int mini=INT_MAX;
        for(int i=0;i<maxDegNums.size();i++)
        {
            int firstpos,lastpos;
            int reqVal=maxDegNums[i];
            for(int j=0;j<n;j++)
            {
                if(nums[j]==reqVal)
                {firstpos=j; break;}
                
            }
            for(int k=n-1;k>=0;k--)
            {
                if(nums[k]==reqVal)
                {
                    lastpos=k;break;
                }
            }
            
            mini=min(mini,lastpos-firstpos);
        }
        return mini+1;
    }
};