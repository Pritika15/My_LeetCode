class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string first
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int idx = 0; // The 'write' pointer to compact the string in-place
        
        for (int i = 0; i < n; i++) {
            // Skip any spaces to find the beginning of a word
            if (s[i] != ' ') {
                // If this isn't the first word, append a single space spacer
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                
                // Keep track of where this specific word starts in our clean area
                int start = idx;
                
                // Copy the entire word forward to the write pointer
                while (i < n && s[i] != ' ') {
                    s[idx++] = s[i++];
                }
                
                // Reverse this individual word back to its correct orientation
                reverse(s.begin() + start, s.begin() + idx);
            }
        }
        
        // Step 2: Crop off all trailing extra spaces left at the back
        s.resize(idx);
        return s;
    }
};