#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node*left,*right;
};
Node* newnode(int data)
{
    Node* n=new Node();
    n->key=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}   
Node* insert_node(int data,Node* root)
{
    Node* nn = newnode(data);
    if(root == NULL)
    {
        root=nn;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *present=q.front();
            q.pop();
            if(present->left==NULL && present->key > nn->key )
            {
                present->left = nn;
                break;
            }
            if(present->left!=NULL && present->key > nn->key)
            {
                q.push(present->left);
            }
            if(present->right==NULL && present->key < nn->key)
            {
                present->right = nn;
                break;
            }
            if(present->right!=NULL && present->key < nn->key)
            {
                q.push(present->right);
            }
        } 
    }
    return root;
}
