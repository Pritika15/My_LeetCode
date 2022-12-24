class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image,vector<vector<int>>& ans,int color, int initialCol)
    {
        ans[sr][sc]=color;
        int r=image.size();
        int c=image[0].size();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i)!=abs(j))
                {
                   int Newsr=sr+i;
                   int Newsc=sc+j;
                    if(Newsr>=0 && Newsr<r && Newsc>=0 && Newsc<c  && image[Newsr][Newsc]==initialCol && ans[Newsr][Newsc]!= color)
                    {
                        dfs(Newsr,Newsc,image,ans,color,initialCol);
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> ans=image;
        int initialCol=image[sr][sc];
        dfs(sr,sc,image,ans,color, initialCol);
        return ans;
    }
};