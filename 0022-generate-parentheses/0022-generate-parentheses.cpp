class Solution {
private:
    void solve(int open,int close,int n,string cur_str,vector<string>& result)
    {
        if(open==n && close==n)
        {
            result.push_back(cur_str);
            return;
        }
        if(open>n || close>open)
            return;
        if(open<n)
        {
            cur_str+="(";
            solve(open+1,close,n,cur_str,result);
            cur_str.pop_back();
        }
        if(close<open)
        {
            cur_str+=")";
            solve(open,close+1,n,cur_str,result);
            cur_str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string cur_str;
        vector<string> result;
        solve(open,close,n,cur_str,result);
        return result;
    }
};