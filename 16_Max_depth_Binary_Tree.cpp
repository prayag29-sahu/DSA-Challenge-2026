#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int dl = 0, dr = 0;
        if (!root)
            return 0;
        if ((!root->left) && (!root->right))
            return 1;
        if (root->left)
        {
            dl = maxDepth(root->left) + 1;
        }
        if (root->right)
        {
            dr = maxDepth(root->right) + 1;
        }
        int m = max(dl, dr);
        return m;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Max Depth: " << obj.maxDepth(root) << endl;

    return 0;
}