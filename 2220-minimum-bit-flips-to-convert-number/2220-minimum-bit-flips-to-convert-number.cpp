class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips=0;
        while(start>0 || goal>0)
        {
            int bitStart=start&1;
            int bitGoal=goal&1;
            if(bitGoal!=bitStart) flips++;
            
            start>>=1;
            goal>>=1;
        }
        return flips;
    }
};