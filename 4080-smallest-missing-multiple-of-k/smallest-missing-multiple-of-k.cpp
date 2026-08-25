class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }
        int multiplyer=1;
        while(true){
            int num=k*multiplyer;
            if(st.find(num)==st.end()) return num;
            multiplyer++;
        }
        return -1;
        
    }
};