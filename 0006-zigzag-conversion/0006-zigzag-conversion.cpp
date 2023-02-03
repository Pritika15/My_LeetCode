class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int pos=numRows-1;
        int len=s.length();
        int k=0;
        int col;
        string ans="";
        vector<vector<char>>v(numRows,vector<char>(len));
        for(int j=0;j<len;j++)
        {
            if(k>len)
            {
                col=j;
                break;

            }
        
        if(pos==0)
            pos=numRows-1;
        if(numRows-1==pos)
        {
            for(int i=0;i<numRows;i++)
            {
                if(k<len)
                    v[i][j]=s[k++];
                else
                    v[i][j]='$';
            }
        }
            else
            {
                for(int i=0;i<numRows;i++)
                {
                    if(pos==i && k<len)
                        v[i][j]=s[k++];
                    else
                        v[i][j]='$';
                }
            }
            pos--;
        }
       for(int i=0;i<numRows;i++)
       {
           for(int j=0;j<len;j++)
           {
               if(v[i][j]!='$')
                   ans.push_back(v[i][j]);
              // cout<<v[i][j]<<" ";
           }
       }
        return ans;
    }
};