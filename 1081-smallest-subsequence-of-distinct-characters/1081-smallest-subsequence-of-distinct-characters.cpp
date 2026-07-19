class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> last_seen(26, 0);
        vector<bool> in_stack(26, false);
        stack<char> st;

        for (int i = 0; i < n; i++) {
            last_seen[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            if (!in_stack[s[i] - 'a']) {
                while (!st.empty() && st.top() > s[i] && last_seen[st.top()-'a'] > i) {
                    char top = st.top();

                    st.pop();
                    in_stack[top - 'a'] = false;
                }
                st.push(s[i]);
                in_stack[s[i] - 'a'] = true;
            } else
                continue;
        }

        string result = "";
        while (!st.empty()) {
            char temp = st.top();
            result += temp;
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};