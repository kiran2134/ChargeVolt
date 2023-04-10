#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * lchild;
    struct node * rchild;
};
struct node * create(struct node* root){
    struct node * temp,*newn;
    int size,i,direction,flag=0;
    printf("Enter Size:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        newn=(struct node *)malloc(sizeof(struct node));
        newn->lchild=newn->rchild=NULL;
        flag=0;
        printf("\n Enter data:");
        scanf("%d",newn->data);
        if(root==NULL)
            root=newn;
        else{
            temp=root;
            while(flag==0){
                printf("\n Enter direction:");
                scanf("%d",&direction);
                if(direction==1){
                    if(temp->lchild!=NULL){
                        temp=temp->lchild;
                    }else{
                        temp->lchild=newn;
                        flag=1;
                    }
                }
                if(direction==2){
                    if(temp->rchild!=NULL){
                        temp=temp->rchild;
                    }else{
                        temp->rchild=newn;
                        flag=1;
                    }
                }
            }
        }
    }
    return(root);
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}

void main(){
    struct node *root=NULL;
    //clrscr();
    root=create(root);
    inorder(root);
}