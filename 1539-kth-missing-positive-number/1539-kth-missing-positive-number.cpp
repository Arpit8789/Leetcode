class Solution {
private:
    void solve(vector<int>& arr,vector<int> v,vector<int> d, int k,int& s1,int n)
    {
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            d.push_back(arr[i]-v[i]);
        }
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(d[mid]>=k)
                e=mid-1;
            else
                s=mid+1;
        }
        int a1=k-d[e];
        s1=arr[e]+a1;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s1=0;
        if(arr[0]==1 && arr[n-1]==n)
            return arr[n-1]+k;
        else if(arr[0]>k )
            return 0+k;
        else
        {
            vector<int> v,d;
           
            solve(arr,v,d,k,s1,n);
            
        }
        return s1;
        
    }
};