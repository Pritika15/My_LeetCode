class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         // vector<int> ans;
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]+=1;
                break;
            }
        }
        if(digits[0]==0)
        {
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
            
        
        return digits;
    }
};