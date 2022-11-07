class Solution {
public:
    int maximum69Number (int num) {
        vector<int>v;
        int x=num;
        while(x!=0)
        {
            v.push_back(x%10);
            x=x/10;
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        bool flag=false;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i]==6)
            {
                if(flag==false)
                {
                    v[i]=9;
                   flag=true;
                    
                }
               
            }
        }
        int y=0;
        int j=0;
        for(int i=0;i<v.size();i++)
        {
            y+=v[i]*pow(10,j);
            j++;
        }
        return y;
        //return 0;
    }
};