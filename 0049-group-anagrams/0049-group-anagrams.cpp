

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> sortedWords;

        // Step 1: Store each word along with its sorted form
        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // Sort to identify anagrams
            sortedWords.push_back({sortedWord, word});
        }

        // Step 2: Sort the vector of pairs based on the sorted word
        sort(sortedWords.begin(), sortedWords.end());

        // Step 3: Group anagrams manually
        vector<vector<string>> result;
        vector<string> currentGroup;

        for (int i = 0; i < n; i++) {
            if (i == 0 || sortedWords[i].first == sortedWords[i - 1].first) {
                // Add to the current anagram group
                currentGroup.push_back(sortedWords[i].second);
            } else {
                // Store previous group and start a new one
                result.push_back(currentGroup);
                currentGroup = {sortedWords[i].second};
            }
        }

        // Add the last group
        if (!currentGroup.empty()) {
            result.push_back(currentGroup);
        }

        return result;
    }
};
