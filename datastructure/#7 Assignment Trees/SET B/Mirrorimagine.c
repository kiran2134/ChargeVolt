struct node * mirror(struct node *root){
    struct node *temp=root,*temp 1;
    if(temp!=NULL){
        if(temp->lchild!=NULL)
            mirror(temp=>lchild);
        if(temp->rchild!=NULL)
            mirror(temp->rchild);
            temp1=temp->lchild;
            temp->lchild=temp->rchild;
            temp->rchild-temp1;
    }
    return(root);
}
void main(){
    struct node * root=NULL,*root1=NULL;
    clrscr();
    root=create(root);
    root1=mirror(root);
    inorder(root1);
}