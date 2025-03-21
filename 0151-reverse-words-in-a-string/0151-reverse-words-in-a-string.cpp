class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word, result;
        
        // Extract words from the input string
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse the order of words and construct the result string
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) result += " ";  // Add space between words but not at the end
        }
        
        return result;
    }

};



