void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("\n %d \t",root->data);
        inorder(root->rchild);
    }
}