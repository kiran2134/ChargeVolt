#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[50];
int top=-1;
void push(char c)
{
   top=top+1;
   stack[top]=c;
}
void pop()
{
   char c;
   c=stack[top];
   top=top-1;
   printf("%c",c);
}
void main()
{
   char str[30];
   int len,i;
   //clrscr();
   printf("Enter the string:\n");
   scanf("%s",str);
   len=strlen(str);
   for(i=0;i<len;i++)
   {
      push(str[i]);
   }
   printf("Reverse of a string:\n");
   for(i=0;i<len;i++)
   {
      pop();
   }
   getch();
}