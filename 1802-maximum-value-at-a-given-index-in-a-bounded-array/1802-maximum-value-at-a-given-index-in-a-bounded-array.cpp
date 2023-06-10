#define ll long long int 
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int emptyR=n-index-1;
        int emptyL=index;
        
        int l=1,h=maxSum;
        ll res=0;
        while(l<=h)
        {
            int mid=(h-l)/2 + l;
            ll leftSum=0,rightSum=0,ele=mid-1;
            
            if(emptyR<=ele)
                rightSum=(ele*(ele+1))/2 - ((ele-emptyR)*(ele-emptyR+1))/2;
            else
                rightSum=(ele*(ele+1))/2+(emptyR-ele);
            
            if(emptyL<=ele)
                leftSum=(ele*(ele+1))/2-((ele-emptyL)*(ele-emptyL+1))/2;
            else
                leftSum=(ele*(ele+1))/2+(emptyL-ele);
            
            ll sum=leftSum+mid+rightSum;
            if(sum<=maxSum)
            {
                l=mid+1;
                res=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        return res;
    }
};