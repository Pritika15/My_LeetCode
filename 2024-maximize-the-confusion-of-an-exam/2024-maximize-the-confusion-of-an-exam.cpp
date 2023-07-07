class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        string s=answerKey;
        int size=s.size(),left=0,res=0,cnt=0;
      //  maximum substring of 'T' which contains k 'F'
        for(int i=0;i<size;i++){
            if(s[i]=='F')
                cnt++;
            while(cnt>k){
                if(s[left]=='F')
                    cnt--;
                left++;
            }
            res=max(i-left+1,res);
        }
    //maximum  substring of 'F' which contains k 'T'
      cnt=0;left=0;
      for(int i=0;i<size;i++){
            if(s[i]=='T')
                cnt++;
            while(cnt>k){
                if(s[left]=='T')
                    cnt--;
                left++;
            }
            res=max(i-left+1,res);
        }
        return res;       
    }
};