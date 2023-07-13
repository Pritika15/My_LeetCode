class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adjList[numCourses];
        
        // for(auto it:prerequisites)
        // {
        //     adjList[it[]].push_back(it.second);
        // }
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>Indegree(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adjList[i])
            {
                Indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(Indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it:adjList[x])
            {
                Indegree[it]--;
                if(Indegree[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};