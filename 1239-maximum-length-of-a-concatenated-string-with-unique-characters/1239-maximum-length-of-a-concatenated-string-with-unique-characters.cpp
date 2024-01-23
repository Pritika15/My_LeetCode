class Solution {
public:
    int len=0;
    bool isUnique(string str)
    {
        set<char>s;
        for(auto it:str)
        {
            if(s.find(it)!=s.end()) return false;
            s.insert(it);

        }
        return true;
    }
    void solve(string str,vector<string>& arr,int indx)
    {
        if(!isUnique(str)) return;
        if(str.length()>len) len=str.length();
        for(int i=indx;i<arr.size();i++)
        {
            solve(str+arr[i],arr,i+1);
        }
        
    }
    int maxLength(vector<string>& arr) {
        
        solve("",arr,0);
        return len;
    }
};