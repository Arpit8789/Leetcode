class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string s : strs) {
            string key = s;                 // copy original
            sort(key.begin(), key.end());   // sort to form key
            mpp[key].push_back(s);          // group anagrams
        }

        vector<vector<string>> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
