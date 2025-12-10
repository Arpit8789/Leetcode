class Solution {
public:
    void solve(vector<string>&ans,string output,string digits,int index,string mapping[])
    {
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        int val=digits[index]-'0';
        string valstr=mapping[val];
        for(int i=0;i<valstr.length();i++)
        {
            output.push_back(valstr[i]);
            solve(ans,output,digits,index+1,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       string output="";
       vector<string> ans;
       if(digits.length()==0)
            return ans;
       string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
       int index=0;
       solve(ans,output,digits,index,mapping);
       return ans; 
    }
};