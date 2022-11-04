class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        vector<int>prev(n),next(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty()) prev[i]=0;
            else prev[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty()) next[i]=n-1;
            else next[i]=s.top()-1;
            s.push(i);
        }
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int MaxArea=heights[i]*(next[i]-prev[i]+1);
            area=max(area,MaxArea);
        }
        return area;
    }
};