#include <algorithm> // For std::remove_if
#include <cctype>    // For std::isalnum
#include <iostream>
#include <string>

class Solution {
public:
    void removeNonAlphanumeric(std::string& str) {
        str.erase(
            std::remove_if(str.begin(), str.end(),
                           [](unsigned char c) { return !std::isalnum(c); }),
            str.end());
    }
    bool isPalindrome(string s) {
        removeNonAlphanumeric(s);
        int start = 0, end = s.length() - 1;

        while (start < end) {
            while (start < end && s[start] == ' ') {
                start++;
            }
            while (start < end && s[end] == ' ') {
                end--;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }
};