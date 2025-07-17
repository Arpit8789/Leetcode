class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string current;

        vector<string> mapping ={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        backtrack(digits , 0 ,mapping , current , result);
        return result;
        
    }
    void backtrack(const string& digits,int index, const vector<string>& mapping, string& current, vector<string>& result) {
        if(index == digits.length())
        {
            result.push_back(current);
            return;
        }

        string letters= mapping[digits[index] - '0'];
        for (char c: letters)
        {
            current.push_back(c);
            backtrack(digits,index+1,mapping , current,result);
            current.pop_back();
        }
    }
};