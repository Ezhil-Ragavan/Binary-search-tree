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
