class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>s;
        // sort(asteroids.begin(),asteroids.end(),greater<int>());
        // s.push(asteroids[0]);
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || asteroids[i]>0)s.push(asteroids[i]);
            else
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
                {
                    s.pop();
                   
                }
                if(!s.empty() && s.top()==abs(asteroids[i])) s.pop();
                else
                {
                    if(s.empty() || s.top()<0)
                    {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};