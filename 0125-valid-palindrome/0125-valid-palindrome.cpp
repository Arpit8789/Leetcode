class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for (char c : s) {
            if (isalnum(c)) {                
                result += tolower(c);        
            }
        }
        string res1=result;
        cout<<result<<" ";
        int sz=result.size();
        for(int i=0;i<sz/2;i++)
        {
            if(result[i]!=result[sz-i-1])
            {
                return false;
            }
        }
        return true;
            
        
    }
};