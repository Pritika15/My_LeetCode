class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
       stack<int>s;
        long long ans=mass;
        for(int i=0;i<n;i++)
        {
            if(ans>=asteroids[i])
            {
                ans+=asteroids[i];
            }
            else
            {
                s.push(asteroids[i]);
                break;
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};