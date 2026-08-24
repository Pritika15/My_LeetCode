class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<long long int,int>>maxheap;

        for(int i =0;i<points.size();i++)
        {
            long long x = points[i][0];
            long long y = points[i][1];
            long long dis = x * x + y * y;
            maxheap.push({dis,i});
            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }

        while(maxheap.size()>0)
        {
            ans.push_back(points[maxheap.top().second]);
            maxheap.pop();
        }
        return ans;
        
    }
};