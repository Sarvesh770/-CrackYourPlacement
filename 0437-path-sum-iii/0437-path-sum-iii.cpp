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
    int ans=0;
    unordered_map<long, int> mp;
    void dfs(TreeNode* root, int target, long sum)
    {
        if(root)
        {
            sum+=root->val;
            if(mp.find(sum-target)!=mp.end())
                ans+=mp[sum-target];
            mp[sum]++;
            dfs(root->left, target, sum);
            dfs(root->right, target, sum);
            mp[sum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        mp[0]=1;
        dfs(root, targetSum, 0);
        return ans;
    }
};