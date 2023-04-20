#include<stdio.h>  
#include<conio.h>
#include<stdlib.h>
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};        
struct node *head, *tail = NULL;    

void addNode(int data){   
    struct node *newNode = (struct node *)malloc(sizeof(struct node));  
    newNode->data = data;    
    if(head == NULL) {  
        head = tail = newNode;   
        head->previous = NULL;    
        tail->next = NULL;  
    }else{ 
        tail->next = newNode;    
        newNode->previous = tail;  
        tail = newNode;   
        tail->next = NULL;  
    }  
}    
void display(){  
    struct node *current = head;  
    if(head == NULL){  
        printf("List is empty\n");  
        return;  
    }
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL){  
        printf("%d ", current->data);  
        current = current->next;  
    }
    printf("\n");
}
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted at Front: ");
    scanf("%d", &data);
    temp->data = data;
  
    // Pointer of temp will be
    // assigned to start
    temp->next = head;
    head = temp;
}
void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
  
    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
  
    // Change Links
    temp = head;
    newnode->data = data;
    newnode->next = 0;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
    }
}
int main(){   
int ch,temp;
while(1){
    printf("Enter 1 to create new node\n Enter 2 to display New nOde\n Enter 3 to Insert Element at First \n Enter 4 to Insert Element at Position \n Enter 10 to exit\n Enter Choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter Data into Node:");
            scanf("%d",&temp);
            addNode(temp);
            break;
        case 2:
            display();
            break;
        case 3:
            insertAtFront();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 10:
            exit(0);
        default:
            printf("Wrong Input!");
            break;
    }
} 
return 0;  
}