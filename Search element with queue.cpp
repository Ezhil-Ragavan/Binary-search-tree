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
            if(present->key==data)
            {
                return true;
            }
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
    return false;
}
