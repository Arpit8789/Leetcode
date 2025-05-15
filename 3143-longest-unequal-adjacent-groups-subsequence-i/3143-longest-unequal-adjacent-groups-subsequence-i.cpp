class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int sz=words.size();

        if (sz == 0) return result;
        result.push_back(words[0]);
        int lastgroup = groups[0];

        for(int i=0;i<sz;i++)
        {
            if(groups[i]!=lastgroup)
            {
                result.push_back(words[i]);
                lastgroup=groups[i];
            }
        }
        return result;
    }
};