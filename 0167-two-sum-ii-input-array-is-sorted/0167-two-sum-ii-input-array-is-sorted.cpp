class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp; // value -> index
        int sz = numbers.size();

        for (int i = 0; i < sz; i++) {
            int comp = target - numbers[i];
            if (mpp.find(comp) != mpp.end()) {
                return {mpp[comp] + 1, i + 1}; 
                
            }
            mpp[numbers[i]] = i;
        }
        return {};
    }
};
