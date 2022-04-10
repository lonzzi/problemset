#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    ans.push_back(vector<int>({root->val}));
    while (q.size() > 0) {
        int size = q.size();
        while (size--) {
            Node* node = q.front();
            q.pop();
            vector<int> path;
            for (int i = 0; i < node->children.size(); i++) {
                q.push(node->children[i]);
                path.push_back(node->children[i]->val);
            }
            ans.push_back(path);
        }
    }
    return ans;
}

int main() {

}