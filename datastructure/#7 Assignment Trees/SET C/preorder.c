void preorder(struct node *root){
    if(root!=NULL){
        printf("\n %d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}