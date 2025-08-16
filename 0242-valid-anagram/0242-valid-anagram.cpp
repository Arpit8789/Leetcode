class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        unordered_map<char,int> mpp;
        unordered_map<char,int> mpp1;
        for(int i=0;i<n1;i++)
        {
            mpp[s[i]]++;
        }
        for(int j=0;j<n2;j++)
        {
            mpp1[t[j]]++;
        }
        return mpp == mpp1;
    }
};