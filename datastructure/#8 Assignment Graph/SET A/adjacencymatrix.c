#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void acceptmatrix(int a[10][10],int n);
void display(int a[10][10],int n);
void main(){
    int a[10][10];
    struct node * list[10];
    int n,i;
    printf("How many vertices:");
    scanf("%d",&n);
    printf("Enter the elements (0/1):");
    acceptmatrix(a,n);
    display(a,n);
}
void acceptmatrix(int a[10][10], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Is there egde between %d & %d:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[10][10],int n){
    int i,j;
    struct node *temp;
    printf("Adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
    printf("\n");
    }
}