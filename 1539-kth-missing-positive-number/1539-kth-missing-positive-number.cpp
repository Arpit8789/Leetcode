class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        int sz=arr.size();
        int ans=0;
        int s=0;
        int e=sz-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]-(mid+1)>=k)
            {
                e=mid-1;
            }
            else
                s=mid+1;
           
        }
        ans=s+k;
        return ans;
        
    }
};