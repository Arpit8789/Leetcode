class Solution {
private:
    vector<vector<string>> result;
    vector<string> str;

    bool plndchk(string ms)
    {
        int l = 0, r = ms.length() - 1;
        while (l < r)
        {
            if (ms[l] != ms[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string s, int i)
    {
        if (i == s.length())
        {
            result.push_back(str);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            string sbs = s.substr(i, j - i + 1);
            if (!plndchk(sbs))
                continue;

            str.push_back(sbs);
            solve(s, j + 1);   // ✅ FIX
            str.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return result;
    }
};
