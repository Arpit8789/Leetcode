class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> freq;  // Stores frequency of each element
        
        // Count occurrences of each number
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> uniqueFreq;  // Stores unique occurrence counts
        
        // Check if occurrences are unique
        for (auto pair : freq) {
            if (!uniqueFreq.insert(pair.second).second) {
                return false;  // If insertion fails, it means frequency is not unique
            }
        }

        return true;  // All frequencies are unique
    }
};