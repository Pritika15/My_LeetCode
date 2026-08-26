class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxHeap;

        for(int i =0;i<arr.size();i++)
        {
            int diff = abs(arr[i]-x);
            maxHeap.push({diff,i});
            
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<int>ans(k,0);
        int cnt = k;

        while(maxHeap.size()>0)
        {
            pair<int,int> topVal = maxHeap.top();
            ans[cnt-1] = arr[topVal.second];
            cnt--;
            maxHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};