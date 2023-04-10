int countleaf(struct node *root){
    if((root->lchild==NUL && root->rchild==NULL))
        return 1;
    return countleaf(root->lchild)+countleaf(root->rchild);
}