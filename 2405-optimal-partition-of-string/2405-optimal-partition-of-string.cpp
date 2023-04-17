class Solution {
public:
    int partitionString(string s) {
       int ans=0;
        vector<int>count(27,0);
        int n=s.length();
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(count[s[i]-'a']==0)
            {
                temp+=s[i];
                count[s[i]-'a']=1;
            }
            else
            {
                cout<<temp<<" ";
                ans++;
                temp="";
                for(int i=0;i<27;i++)
                    count[i]=0;
                if(count[s[i]-'a']==0)
                {
                    temp+=s[i];
                    count[s[i]-'a']=1;
                    if(i==n-1) 
                    {
                        ans++;
                        temp="";
                    }
                    
                }
            }
        }
        if(temp!= "") ans++;
        return ans;
    }
};