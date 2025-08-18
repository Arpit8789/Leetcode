class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz=nums.size();
        map<int,int> mpp;
        vector<int> answer;
        int prod=1,cnt=0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]==0)
            {
                cnt++;
                continue;
            }
            prod=prod*nums[i];
        }
        cout<<cnt;
        for(int i=0;i<sz;i++)
        {
            if(cnt>=2)
            {
                answer.push_back(0);
            }
            else if(cnt>=1 && nums[i]!=0)
            {
                answer.push_back(0);
            }
            else if(cnt==sz)
            {
                answer.push_back(nums[i]);
            }
            else if(cnt>=1 && nums[i]==0)
            {
                answer.push_back(prod);
            }
            
            else if(nums[i]!=0)
            {
                answer.push_back(prod/nums[i]);
            }
        }
        return answer;
    }
};