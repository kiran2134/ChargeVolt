#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *create(struct node *root){
    struct node *temp, *newn;
    int i,size;
    printf("Enter size:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        newn=(struct node *)malloc(sizeof(struct node));
        newn->lchild=newn->rchild=NULL;
        printf("\n Enter data:");
        scanf("%d",&newn->data);
        if(root==NULL)
            root=newn;
        else{
            temp=root;
            while(temp!=NULL){
                if(temp->data>newn->data){
                    if(temp->lchild!=NULL){
                        temp=temp->lchild;
                    }else{
                        temp->lchild=newn;
                        break;
                    }
                }else{
                    temp->rchild=newn;
                    break;
                }
            }
        }
    }return (root);
}

void inorder(struct node *root){
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