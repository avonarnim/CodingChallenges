class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> maxes = compute_opt(nums);
        // opt(i) = max(nums[i] + opt(i+2), opt(i+1))
        
        return maxes[nums.size()-1];
    }
    
    vector<int> compute_opt(vector<int>& nums) {
        vector<int> maxes(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                maxes[i] = nums[i];
            } else if (i == 1) {
                maxes[i] = (nums[i] > nums[i-1]) ? nums[i] : nums[i-1];
            } else {
                maxes[i] = (nums[i] + maxes[i-2] > maxes[i-1]) ? nums[i] + maxes[i-2] : maxes[i-1];
            }
        }
        return maxes;
    }
};