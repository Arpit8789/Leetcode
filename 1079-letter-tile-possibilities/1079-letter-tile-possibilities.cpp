class Solution {
private:
    int solve(vector<int>& freq) {
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            // choose character
            freq[i]--;
            count += 1;               // current sequence is valid
            count += solve(freq);     // extend the sequence
            freq[i]++;                // backtrack
        }

        return count;
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);

        for (char c : tiles) {
            freq[c - 'A']++;
        }

        return solve(freq);
    }
};
