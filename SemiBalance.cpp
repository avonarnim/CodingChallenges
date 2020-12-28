/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        } else {
            return sortedArrayToBST(nums, 0, nums.size()-1);
        }        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left == right) {
            return new TreeNode(nums[left]);
        } else if (left < right) {
            int mid = int (left+right)/2;
            TreeNode* temp = new TreeNode(nums[mid]);
            temp->left = sortedArrayToBST(nums, left, mid-1);
            temp->right = sortedArrayToBST(nums, mid+1, right);
            return temp;
        } else {
            return NULL;
        }
    }
};