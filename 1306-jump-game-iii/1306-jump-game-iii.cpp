class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),0);
        return solve(arr,start,visited);
        
    }

    bool solve(vector<int>& arr, int start,vector<int>& visited){
        if(arr[start]==0) return true;
        visited[start] = 1;
        bool right = false;
        bool left = false;

        if(start+arr[start]< arr.size() && visited[start+arr[start]]==0)
        {   
            right = solve(arr,start+arr[start], visited);
        }
        if(start-arr[start]>= 0 && visited[start-arr[start]]==0){
             left = solve( arr, start-arr[start], visited);
        } 

        return right || left;
    }
};