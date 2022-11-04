#include<bits/stdc++.h>
class Solution {
public:
vector<int> PrevSmallest(int n,vector<int>& heights)
{
    vector<int>v(n);
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!= -1 && heights[s.top()]>=heights[i])
        {
          s.pop();
        }
        v[i]=s.top();
        s.push(i);

        

    }
    return v;
}
vector<int> NextSmallest(int n,vector<int>& heights)
{
    vector<int>v(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!= -1 && heights[s.top()]>=heights[i])
        {
            s.pop();
        }
        v[i]=s.top();
        s.push(i);
    }
    return v;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=NextSmallest(n,heights);
        vector<int>prev(n);
        prev=PrevSmallest(n,heights);
        int area=INT_MIN;
        
        int MaxiumArea;

        for(int i=0;i<n;i++)
        {
            if(next[i]== -1)
            next[i]=n;
            int breadth=next[i]-prev[i]-1;
            int areaa=heights[i]*breadth;
            area=max(area,areaa);

        }
        return area;
        
    }
};