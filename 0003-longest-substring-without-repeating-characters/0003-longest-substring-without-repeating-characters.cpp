class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // use vector instead of hash[]
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;  // Move left pointer
            }

            hash[s[r]] = r;  // Update last seen index of character
            int len = r - l + 1;
            maxlen = max(len, maxlen);
            r++;
        }

        return maxlen;
    }
};
