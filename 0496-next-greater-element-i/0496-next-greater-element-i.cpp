class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans;
        vector<int> ans1;
        unordered_map<int,int> mpp;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(-1) ;
            else 
                ans.push_back(st.top());
            st.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++)
        {
            mpp[nums2[i]]=ans[i];
        }
        int n1=nums1.size();
        for(int j=0;j<n1;j++)
        {
            ans1.push_back(mpp[nums1[j]]);
        }
        return ans1;
    }
};