class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0,j=0;
    if(m==0)
    {
        nums1.clear();
        for(int i=0;i<n;i++)
            nums1.push_back(nums2[i]);
        return;
    }
    if(n==0) return ;
	while(i<m)
	{
		if(nums1[i]>nums2[j])
		{
			int temp=nums1[i];
			nums1[i]=nums2[j];
			nums2[j]=temp;
			sort(nums2.begin(),nums2.end());

		}
		i++;
		
	}
	// sort(arr2.begin(),arr2.end());
	while(j<n)
	{
		nums1[i]=nums2[j];
		i++;
		j++;

	}
	
    }
};