class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int i = 0;

        while (i < s.length()) {
            char c1 = s[i];
            char c2 = s[i + 1];

            if (c1 != c2) {
                ans++;
            }
            i += 2;
        }

        return ans;
    }
};