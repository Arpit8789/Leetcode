class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        // Step 1: Get common prefix of first two strings
        string str1 = strs[0];
        string str2 = strs[1];
        int minLength = min(str1.length(), str2.length());
        string st = "";

        for (int i = 0; i < minLength; ++i) {
            if (str1[i] == str2[i])
                st += str1[i];
            else
                break;
        }

        // Step 2: Check this prefix with all remaining strings
        for (int i = 2; i < strs.size(); ++i) {
            string curr = strs[i];
            string temp = "";
            for (int j = 0; j < min(st.length(), curr.length()); ++j) {
                if (curr[j] == st[j])
                    temp += curr[j];
                else
                    break;
            }
            st = temp;
            if (st == "") break;
        }

        return st;
    }
};
