int countNonleaf(struct node *root){
    if(root==NULL||(root->lchild==NULL&&root->rchild==NULL))
        return 0;
    return 1+countNonleaf(root->lchild)+countNonleaf(root->rchild);
}