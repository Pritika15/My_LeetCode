class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m)
            return false;
        unordered_map<char, char> mappy;
        unordered_map<char, bool> mappy1;

        for (int i = 0; i < n; i++) {
            // Possibility A: s[i] has been seen before
            if (mappy.count(s[i])) {
                if (mappy[s[i]] != t[i])
                    return false;
            }
            // Possibility B: s[i] is new
            else {
                // If t[i] is already claimed by a different s character, it's a
                // conflict!
                if (mappy1.count(t[i]))
                    return false;

                // Otherwise, establish the new bond
                mappy[s[i]] = t[i];
                mappy1[t[i]] = true;
            }
        }
        return true;
    }
};