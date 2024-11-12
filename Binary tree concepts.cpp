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
Node* min(Node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return min(root->left);//root oda left ahh root ah mathirum
    }
}

Node* deletenode(Node* root,int data)
{
    if(root==NULL)
    {
        cout<<"value not found";
        return NULL;
    }
    //to find the Element side
    //smaller means left side
    if(data < root->key)
    {
        root->left=deletenode(root->left,data);
    }
    //greathen means right side
    else if(data > root->key)
    {
        root->right=deletenode(root->right,data);
    }
    //equal
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            Node*temp=root;//same value
            Node*minNodeForRight=min(temp->right);//caling min function
            root->key=minNodeForRight->key;//swaping the min value to that root position
            root->right=deletenode(root->right,minNodeForRight->key);//again caling the detele function
        }
        else if(root->left!=NULL)
        {
            root=root->left;
        }
        else if(root->right!=NULL)
        {
            root=root->right;
        }
        else
        {
            root=NULL;
        }
    }
    return root;
}

Node* search(Node*root,int data)
{
    if(root==NULL)
    {
     cout<< "false";
    }
    else if(data < root->key)
    {
      root->left=search(root->left,data);  
    }
    else if(data > root->key)
    {
        root->right=search(root->right,data);
    }
    else
    {
        cout<<"true";
    }
    return root;
}

bool search_element(Node* root,int data)
{
    if(root == NULL)
    {
       return false;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *present=q.front();
            q.pop();
            if(present->left!=NULL)
            {
                q.push(present->left);
                if(present->left->key == data)
                {
                    return true;
                }
            }
            if(present->right!=NULL)
            {
                q.push(present->right);
                if(present->right->key==data)
                {
                    return true;
                }
            }
            return false;
        }
    }
    return root;
}
Node* display(Node* root)
{
    if(root == NULL)
    {
        cout<<"No Elements"<<endl;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *present=q.front();
            cout << present->key <<"->";
            q.pop();
            if(present->left!=NULL)
            {
                q.push(present->left);
            }
            if(present->right!=NULL)
            {
                q.push(present->right);
            }
        }
    }
    cout<<"NULL";
    cout<<endl;
    return root;
}
int main(){
    Node* root = NULL;
    root=insert_node(60,root);
    root=insert_node(56,root);
    root=insert_node(35,root);
    root=insert_node(48,root); 
    root=insert_node(7,root);
    root=insert_node(61,root);
    root=insert_node(82,root);
    root=insert_node(96,root);
    root=insert_node(66,root);
    root=insert_node(10,root);
    root=display(root);
    root=deletenode(root,48);
    root=display(root);
    root=search(root,48);
    cout<<search_element(root,56)<<endl;
}
