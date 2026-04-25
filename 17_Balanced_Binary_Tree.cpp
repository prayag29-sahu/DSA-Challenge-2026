#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return check(root) != -1;
    }

    int check(TreeNode *node)
    {
        if (!node)
            return 0;

        int left = check(node->left);
        if (left == -1)
            return -1;

        int right = check(node->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout << "Balanced Tree: ";
    cout << (obj.isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
