class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      int n = A.size();
      vector<int> ans(n), vis(n+1,0);
      int count =0;

      for(int i =0;i<n;i++)
      {
        if(++vis[A[i]]==2) ++count;

        if(++vis[B[i]]==2) ++count;

        ans[i]=count;

      }  
      return ans;
    }
};