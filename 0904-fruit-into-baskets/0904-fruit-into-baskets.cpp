class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int i=0,j=0;
        int ans=INT_MIN;
        while(j<fruits.size())
        {
            map[fruits[j]]++;
            while(map.size()>2)
            {
                map[fruits[i]]--;
                if(map[fruits[i]]==0)
                {
                    map.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};