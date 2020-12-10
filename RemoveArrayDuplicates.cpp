class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        int currentValue = nums[i];
        int spacesAssigned = 1;
        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == currentValue) {
                i++;
            }
            if (i == nums.size()) {
                break;
            }
            nums[spacesAssigned] = nums[i];
            currentValue = nums[i];
            spacesAssigned++;
            i++;
        }
        return spacesAssigned;
    }
};