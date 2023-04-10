#include<stdio.h>
#include<conio.h>
#define max 15
struct queue{
    int data[max];
    int front,rear;
};
void initialize(struct queue *q){
    int i;
    for(i=0;i<max;i++)
        q->data[i]=0;
        q->front=q->rear=-1;
        printf("InQueue is created");
}
void insert(struct queue *q){
    int nw,i,n;
    nw=(q->front+1)%max;
    if(q->front==nw){
        printf("\n Queue is full");
    }else{
        printf("\n Enter Value:");
        for(i=0;i<max;i++){
            scanf("%d",&n);
            q->rear=q->rear+1;
            q->data[q->rear]=n;
        }
    }
}
void del(struct queue*q){
    int num;
    if(q->front==q->rear)
        printf("\n Queue is empty");
    else{
        num=q->data[q->front];
        q->front=(q->front+1)%max;
    }
}
void display(struct queue *q){
    int i;
    for(i=q->front;i!=q->rear;i=(i+1)%max){
        printf("%d\t",q->data[i]);
    }
    printf("%d\t",q->data[q->rear]);
}
void peek(struct queue *q){
    printf("\n Peeked Element is %d",q->front);
}
void isempty(struct queue *q){
    if(q->front==q->rear)
        printf("\n Queue is empty");
    else
        printf("\n Queue is not empty");
}
void main(){
    struct queue q;
    //clrscr();
    initialize(&q);
    insert(&q);
    del(&q);
    display(&q);
    peek(&q);
    isempty(&q);
}