class Solution {
public:
    // class compare{
    //     bool operator()(pair<int,int> a, pair<int,int> b)
    //     {
    //         return a.second<b.second;
    //     }
    // };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        priority_queue<pair<int,int>>pq;
        for(auto x:m)
        {
            pq.push(make_pair(x.second,x.first)); //pair of freq,element: so that we can sort them according to the frq.
        }
       // int a=0;
        while(k--)
        {
            int num=pq.top().second;
           // cout<<num<<endl;
            // int freq=pq.top().second;
            // cout<<num<<" "<<freq;
            // cout<<endl;
            pq.pop();
            v.push_back(num);
           // a++;
        }
        return v;
    }
};