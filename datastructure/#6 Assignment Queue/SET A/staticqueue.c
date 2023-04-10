#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int queue_arr[MAX];
int front=-1;
int rear=+1;
void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();
void main()
{
    int ch,item;
    //clrscr();
    while(1)
    {
       printf("\n1.Insert\n");
       printf("\n2.Delete\n");
       printf("\n3.Display element at peek\n");
       printf("\n4.Display all the elements of the queue\n");
       printf("\n5.Exit");
       printf("\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:printf("\nInput the element for adding in queue:");
		 scanf("%d",&item);
		 insert(item);
		 break;
	  case 2:item=del();
		 printf("\nDeleted element is %d\n",item);
		 break;
	  case 3:printf("\nElement at the front is %d\n",peek());
		 break;
	  case 4:display();
		 break;
	  case 5:exit(1);
		default:printf("Invalid choice");
	  }
	  getch();
    }
}
void insert(int item)
{
     if(isFull())
     {
	 printf("\nQueue overflow\n");
	 return;
     }
     if(front==-1)
	front=0;
	rear=rear+1;
	queue_arr[rear]=item;
}

int del()
{
   int item;
   if(isEmpty())
   printf("\nQueue underflow\n");
   item=queue_arr[front];
   front=front+1;
   return item;
}
int peek()
{
   if(isEmpty())
   {
   printf("\nQueue underflow\n");
   exit(1);
   }
   return queue_arr[front];
}

int isEmpty()
{
   if(front==-1 || front==rear+1)
     return 1;
   else
      return 0;
}
int isFull()
{
    if(rear==MAX-1)
	return 1;
    else
	return 0;
}
void display()
{
   int i;
   if(isEmpty())
   {
     printf("\nQueue is Empty\n");
     return;
   }
   printf("\nQueue is:\n\n");
   for(i=front;i<=rear;i++)
   printf("%d",queue_arr[i]);
   printf("\n\n");
}