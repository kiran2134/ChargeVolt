void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("\n %d\t",root->data);
    }
}
void main(){
    struct node *root=NULL;
    root=create(root);
    inorder(root);
    preorder(root);
    postorder(root);
}