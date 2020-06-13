#include <set>
#include <queue>
#include <vector>
#include <tuple>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

/* Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)
   If there are no nodes with an even-valued grandparent, return 0.
*/
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;

        bool even = root->val % 2 == 0;

        auto l = root->left;
        auto r = root->right;

        if (l) {
            sum += sumEvenGrandparent(l);

            if (even) {
                sum += l->left ? l->left->val : 0;
                sum += l->right ? l->right->val : 0;
            }
        }

        if (r) {
            sum += sumEvenGrandparent(r);


            if (even) {
                sum += r->left ? r->left->val : 0;
                sum += r->right ? r->right->val : 0;
            }
        }

        return sum;
    }
    /*
    Given the root of a binary search tree with distinct values,
    modify it so that every node has a new value equal to the sum
    of the values of the original tree that are greater than or equal to node.val.
    */
    TreeNode* bstToGst(TreeNode* root) {
        int sum = { 0 };
        add(root, sum);

        return root;
    }

    void add(TreeNode* root, int& sum) {
        if (!root) return;
        add(root->right, sum);
        sum = root->val = sum + root->val;
        add(root->left, sum);
    }

    TreeNode* bstToGstIterative(TreeNode* root) {
        std::set<int> vals;
        std::vector<TreeNode*> visited;

        std::queue<TreeNode*> ns;
        ns.push(root);

        while (!ns.empty()) {
            auto n = ns.front();
            ns.pop();

            vals.insert(n->val);
            visited.push_back(n);

            if (n->left)
                ns.push(n->left);
            if (n->right)
                ns.push(n->right);
        }

        for (auto const& t : visited) {
            int v = t->val;
            for (auto const& i : vals) {
                if (i > t->val) {
                    v += i;
                }
            }
            t->val = v;
        }

        return root;
    }

    /* Given a binary tree, return the sum of values of its deepest leaves. */
    int deepestLeavesSum(TreeNode* root) {
        auto r = height_sum(root, 0, 0);

        return std::get<0>(r);
    }

    std::tuple<int, int> height_sum(TreeNode* root, int sum, int d) {
        d++;

        if (!root->left && !root->right)
            return std::tuple<int, int>{root->val, d};

        std::tuple<int, int> lres, rres;
        if (root->left) lres = height_sum(root->left, sum, d);
        if (root->right) rres = height_sum(root->right, sum, d);

        int dl = root->left ? std::get<1>(lres) : 0;
        int dr = root->right ? std::get<1>(rres) : 0;
        int s = 0;
        if (dl < dr)      return rres;
        else if (dl > dr) return lres;
        else              return std::make_tuple(std::get<0>(lres) + std::get<0>(rres), dl);
    }
};