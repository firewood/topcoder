#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d) {
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
        Node* insert(Node* root, int data) {
            if (root==NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data<=root->data) {
                    cur=insert(root->left,data);
                    root->left=cur;
                } else {
                   cur=insert(root->right,data);
                   root->right=cur;
                }
                return root;
            }
        }

    void levelOrder(Node * root) {
        //Write your code here
        string s = "";
        vector<Node *> q;
        q.push_back(root);
        while (!q.empty()) {
            vector<Node *> next;
            for (auto n : q) {
                if (n != NULL) {
                    cout << s << n->data;
                    s = " ";
                    next.push_back(n->left);
                    next.push_back(n->right);
                }
            }
            q = next;
        }
        cout << endl;
    }
};
