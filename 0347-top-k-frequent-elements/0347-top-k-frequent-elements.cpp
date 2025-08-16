class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Bucket sort (index = frequency)
        int n = nums.size();
        vector<vector<int>> bucket(n+1); 

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Step 3: Collect from highest frequency
        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
