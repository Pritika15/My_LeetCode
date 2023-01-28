class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string>v;
        int n=number.length();
        for(int i=0;i<n;i++)
        {
            if(number[i]==digit)
            {
                string temp=number.substr(0,i)+number.substr(i+1);
                v.push_back(temp);
                temp="";
            }
        }
        sort(v.begin(),v.end(),greater<string>());
        return v[0];
    }
};