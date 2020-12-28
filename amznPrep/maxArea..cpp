class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int minLength = (height[l] < height[r]) ? height[l] : height[r];
            maxArea = (maxArea > minLength*(r-l)) ? maxArea : minLength*(r-l);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};