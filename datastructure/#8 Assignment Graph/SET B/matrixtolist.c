#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void acceptmatrix(int a[10][10],int n);
void acceptlist(struct node * list[10], int a[10][10], int n);
void display(int a[10][10], int n);
void displaylist(struct node * list[10],int a[10][10],int n);
void main(){
    int a[10][10],i,j,n;
    printf("how many vertices:");
    scanf("%d",&n);
    printf("Enter the elements(0/1):");
    acceptmatrix(a,n);
    acceptlist(list,a,n);
    display(a,n);
    displaylist(list,a,n);
}
void acceptmatrix(int a[10][10],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;i<n;i++){
            printf("\n is there edge between %d & %d",i,j);
            scanf("%d",a[i][j]);
        }
    }
}
void acceptlist(struct node * list[10], int a[10][10], int n){
    int i,j;
    struct node * newn,*temp;
    for(i=0;i<n;i++){
        list[i]=NULL;
        for(j=0;j<n;j++){
            newn=(struct node *)malloc(sizeof(struct node));
            newn->data=j+1;
            newn->next=NULL;
            newn->data=j;
            if(list[i]==NULL)
                list[i]=temp=newn;
            else{
                temp->next=newn;
                temp=newn;
            }
        }
    }
}
void display(int a[10][10], int n){
    int i,j;
    struct node *temp;
    printf("The Adjacency Matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void displaylist(struct node * list[10],int a[10][10],int n){
    struct node *temp;
    int i;
    printf("The Adjacency List is:");
    for(i=0;i<n;i++){
        printf("%d->",i+1);
        temp=list[i];
        while(temp){
            printf("V%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}