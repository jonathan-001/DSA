// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
// 22 oct 2024

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
// so as problem focuses on level --> we use level wise traversal
// insert sum of all nodes at each level -->push into list
// sort increasingly
// return last k element from sum
// O(n+nlogn)  sc- O(n)-in case skewed tree

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
              vector<long long> res;
               queue<TreeNode*> q;

               q.push(root);
               while (!q.empty()) {
                int n = q.size();
                long long sum = 0;

                 while (n--) {
                     TreeNode* node = q.front(); q.pop();
                     sum += (long long)node->val;

                      if (node->left) q.push(node->left);
                      if (node->right) q.push(node->right);
                   }
                res.push_back(sum);
               }

              if (k > res.size()) return -1;

              sort(res.begin(), res.end(), greater<long long>()); // for decreasing order
               return res[k-1];

    }
};
