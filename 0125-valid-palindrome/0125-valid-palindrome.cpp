#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;   // Skip non-alphanumeric
            while (left < right && !isalnum(s[right])) right--; // Skip non-alphanumeric
            
            if (tolower(s[left]) != tolower(s[right])) return false;
            
            left++;
            right--;
        }
        return true;
    }
};
