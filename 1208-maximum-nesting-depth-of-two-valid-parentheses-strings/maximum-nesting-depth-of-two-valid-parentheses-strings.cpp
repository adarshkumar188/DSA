class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> depth(n);
        int d = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                d++;
                depth[i] = d;
            } else {
                depth[i] = d;
                d--;
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (depth[i] % 2 != 0)
                ans[i] = 1;
        }

        return ans;
    }
};