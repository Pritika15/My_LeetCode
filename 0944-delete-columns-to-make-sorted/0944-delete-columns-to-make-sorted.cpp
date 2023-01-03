class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs.size();
        int col=strs[0].size();
        int count=0;
        for(int j=0;j<col;j++)
        {
            
            for(int i=1;i<row;i++)
            {
                int FirstIndex=int(strs[i-1][j]);
                if(int(strs[i][j])<FirstIndex)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};