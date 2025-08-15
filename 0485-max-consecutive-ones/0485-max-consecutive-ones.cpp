class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int cnt=0,maxi=0;
        int n=nums.size();
        while(j<n)
        {
            
            if(nums[j]!=0 && j!=n-1)
            {
                cout<<"a ";
                cnt++;
            }          
            else 
            {
                if(nums[j]==1)
                    cnt=cnt+1;
                maxi=max(maxi,cnt);
                cnt=0;
            }
            j++;
        }
        return maxi;
        
    }
};