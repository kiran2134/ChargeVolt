#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 100	


int top=-1;
int item;

char stack_string[MAX];


void pushChar(char item);


char popChar(void);


int isEmpty(void);

int isFull(void);
 
void main()
{
    char str[MAX];
    
    int i;
    //clrscr();
    printf("Input a string: ");
    scanf("%[^\n]s",str); /*read string with spaces*/
    /*gets(str);-can be used to read string with spaces*/

    for(i=0;i<strlen(str);i++)
	pushChar(str[i]);

    for(i=0;i<strlen(str);i++)
	str[i]=popChar();

    printf("Reversed String is: %s\n",str);

    getch();
}

void pushChar(char item)
{
    /*check for full*/
    if(isFull())
    {
	printf("\nStack is FULL !!!\n");
	return;
    }

    /*increase top and push item in stack*/
    top=top+1;
    stack_string[top]=item;
}

 char popChar()
{
    
    if(isEmpty())
    {
	printf("\nStack is EMPTY!!!\n");
	return 0;
    }

    /*pop item and decrease top*/
    item = stack_string[top];
    top=top-1;
    return item;
}


int isEmpty()
{
    if(top==-1)
	return 1;
    else
	return 0;
}

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}