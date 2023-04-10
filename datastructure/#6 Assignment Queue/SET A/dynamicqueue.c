#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 4
struct queue{
    int data;
    struct queue *next;
}*front,*rear,*N,*temp,*T;
void create(){
    int i;
    printf("\n Enter elements:");
    for(i=0;i<max;i++){
        N=(struct queue *)malloc(sizeof(struct queue));
        scanf("%d",&N->data);
        N->next=NULL;
        if(front==NULL)
            front=rear=N;
        else{
            rear->next=N;
            rear=N;
        }
    }
}

void display(){
    printf("\n Elements are:");
    for(temp=front;temp!=rear;temp=temp->next){
        printf("%d\t",temp->data);
    }printf("%d",rear->data);
}

void del(){
    if(front==NULL && rear==NULL)
        printf("Queue is empty");
    else
        T=front;
        front=front->next;
        free(T);
}

void isempty(){
    if(front==NULL&&rear==NULL)
        printf("\n Queue is empty");
    else{
        printf("\n Queue is not empty");
    }
}

void peek(){
    printf("\n Peeked Element is:%d",front->data);
}

void main(){
    create();
    isempty();
    display();
    del();
    display();
    peek();
}