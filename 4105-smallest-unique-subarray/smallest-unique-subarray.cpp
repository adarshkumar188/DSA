class Solution {
private:
    bool check(vector<int>& nums, int k) {
        unsigned long long base = 1000000007;
        unsigned long long hash = 0, power = 1;

        unordered_map<unsigned long long, int> mp;

        for(int i = 0; i < k; i++){
            hash = hash * base + nums[i];
            power *= base;
        }

        mp[hash]++;

        for(int i = k; i < nums.size(); i++){
            hash = hash * base + nums[i] - nums[i-k] * power;
            mp[hash]++;
        }

        for(auto& it : mp){
            if(it.second == 1)
                return true;
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int l = 1, r = nums.size();

        while(l < r){
            int mid = l + (r-l)/2;

            if(check(nums, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
