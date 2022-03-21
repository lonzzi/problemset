#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printSet(unordered_set<int>* set) {
    for (auto &item : *set) {
        cout << item << " ";
    }
    cout << endl;
}

bool dfs(unordered_set<int> *hashTable, TreeNode* root, int k) {
    if (root != nullptr) {
        if (hashTable->count(k - root->val)) {
            return true;
        }
        hashTable->insert(root->val);
        printSet(hashTable);
        return dfs(hashTable, root->left, k) || dfs(hashTable, root->right, k);
    }
    return false;
}

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> hashTable;
    return dfs(&hashTable, root, k);
}

int main() {
    // some code...
    TreeNode* root = new TreeNode();
    root->val = 2;
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    vector<int> test({0, 1});

    cout << findTarget(root, 4) << endl;

    return 0;
}