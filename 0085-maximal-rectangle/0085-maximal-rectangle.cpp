class Solution {
public:
    int maxArea(vector<int>heights)
    {
       int n=heights.size();
        stack<int>s;
        vector<int>prev(n),next(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty())prev[i]=0;
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
            int b=next[i]-prev[i]+1;
            int maxArea=heights[i]*b;
            area=max(area,maxArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>heights(m,0);
        int arr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int MAXARR=maxArea(heights);
            arr=max(arr,MAXARR);
        }
        
        return arr;
        
    }
};