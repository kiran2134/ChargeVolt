#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int num;
    struct node *nextptr;
}*stnode;
void creation(int n);
void display();
void main(){
   int n;
   //clrscr();
   stnode=NULL;
   printf("\n\nCircular linked list:create and display a circular linked list:\n");
   printf("-------------------------------------------------------------------\n");
   printf("Input the number of nodes:");
   scanf("%d",&n);
   creation(n);
   display();
   getch();
}
void creation(int n){
   int i,num;
   struct node *preptr,*newnode;
   if(n>=-1){
      stnode=(struct node *)malloc(sizeof(struct node));
      printf("Input data for node 1:");
      scanf("%d",&num);
      stnode->num=num;
      stnode->nextptr=NULL;
      preptr=stnode;
      for(i=2;i<=n;i++){
	      newnode=(struct node *)malloc(sizeof(struct node));
	      printf("Input data for node %d:",i);
	      scanf("%d",&num);
	      newnode->num=num;
	      newnode->nextptr=NULL;
	      preptr->nextptr=newnode;
	      preptr=newnode;
      }
      preptr->nextptr=stnode;
   }
}
void display(){
    struct node *tmp;
    int n=1;
    if(stnode==NULL){
      printf("No data found in the list yet.");
    }else{
    tmp=stnode;
    printf("\n\nData entered in the list are:\n");
    do{
     printf("Data %d=%d\n",n,tmp->num);
     tmp=tmp->nextptr;
     n++;
    }while(tmp!=stnode);
  }
 }