class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result;
       
        int n=candies.size();
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(candies[i]<mini)
                mini=candies[i];
            if(candies[i]>maxi)
                maxi=candies[i];
        }
        int miniNum=mini+extraCandies;
        int maxiNum=maxi+extraCandies;
        for(int i=0;i<n;i++)
        {
            if((candies[i]+extraCandies)>=maxi)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};