class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // declare a unordered map, which will keep track of frequency of each number present in subarray (left to right)
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int longest = 0;
        while(right < n)
        {
            // add the nums[right] into window and increment the frequency
            mp[nums[right]]++;
            // shrink the window from left side, until the condition is not fulfilled
            while(left < right && mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            // update the longest possible subarray
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};