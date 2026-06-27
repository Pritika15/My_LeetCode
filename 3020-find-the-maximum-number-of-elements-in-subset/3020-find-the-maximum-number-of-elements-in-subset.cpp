class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i =0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        sort(nums.begin(),nums.end());
        int max_counter = 1;
        int allOnes = 0;

        for(int i =0;i<nums.size();i++)
        {
            int count = 1;
            if(nums[i]==1)
            {
                allOnes++;
                continue;

            } 
            long long int curr = nums[i];
            while(curr <= 100000 && m.find(curr*curr)!=m.end() && m[curr]>=2 )
            {
                

                    count=count+2;
                    if(m.find(curr*curr)!=m.end()) curr = curr*curr;  
            }
            
            max_counter = max(max_counter,count);
        }

        if(allOnes)
        {
            if(allOnes%2 ==0) max_counter= max(max_counter,allOnes-1) ;
            else max_counter= max(max_counter,allOnes) ;
        }
        return max_counter;
    }
};