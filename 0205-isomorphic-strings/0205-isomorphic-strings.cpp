class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> freqS, freqT;
        for(int i=0;i<s.size();i++)
        {
            char cs=s[i];
            char ct=t[i];

            if(freqS.count(cs))
            {
                if(freqS[cs]!=ct) 
                    return false;
            }
            else
            {
                freqS[cs]=ct;
            }
            if(freqT.count(ct))
            {
                if(freqT[ct]!=cs) 
                    return false;
            }
            else
            {
                freqT[ct]=cs;
            }
            
        }

    return true;  
    }
};