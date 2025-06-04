class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        int ans=-1;
        int m=s+(e-s)/2;
        if (n==1){
            return 0;
        }
        while(s<e){
            if(nums[m]<nums[m+1]){
                s=m+1;
                ans=s;
            
            }
            else{
                e=m;
                ans=e;

            }
            m=s+(e-s)/2;
        }
        return ans;
        
    }
};