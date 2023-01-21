class Solution {
public:
    void helper(int index,string &s, vector<string> &temp,vector<string> &ans)
    {
        if(index==s.length() && temp.size()==4)
        {
            for(int i=0;i<temp.size();i++)
                cout<<temp[i]<<" ";
            string ss=temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3];
            ans.push_back(ss);
            return;
        }
        string Temps="";
        for(int i=index;i<s.length() && temp.size()<4;i++)
        {
            if(s[i]-'0'>9) continue;
            Temps+=s[i];
            int Tempint=stoi(Temps);
            
            if(Tempint>=0 && Tempint<=255)
            {
                temp.push_back(Temps);
                
                helper(i+1,s,temp,ans);
                temp.pop_back();
            }
            if(Tempint<=0 || Tempint>255) break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
       vector<string>temp;
        vector<string>ans;
        helper(0,s,temp,ans);
        return ans;
    }
};