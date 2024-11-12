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
