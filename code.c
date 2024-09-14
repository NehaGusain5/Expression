#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
bool isEmpty(int *top)
{
    if(*top==-1)
    return true;
    else
    {return false;}
}
void push(char s[],int *top, char val)
{
    s[++(*top)]=val;
}
char pop(char s[],int *top)
{
    return s[(*top)--];
}
bool opr(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {return true;}
    else
    {return false;}
}
int prec(char x)
{
    if(x=='+'||x=='-')
    {return 1;}
    else if(x=='*'||x=='/')
    {return 2;}
    else
    {return 0;}
}
void conversion(char infix[],char prefix[],char s[],int *top)
{   int j=0;
    for(int i=strlen(infix)-1;i>=0;i--)
    {
        if(infix[i]==' ') continue;
        if(infix[i]=='(')
        {
           while(!isEmpty(top)&&s[*top]!=')')
           {
            prefix[j++]=pop(s,top);
           }
           
           if(!isEmpty(top)&&s[*top]==')')
           {pop(s,top);}
        }
        else if(infix[i]==')')
        {
            push(s,top,infix[i]);
        }
        else if(opr(infix[i]))
        {
            while(!isEmpty(top)&&s[*top]!='('&&prec(s[*top])>=prec(infix[i])){
                prefix[j++]=pop(s,top);
            }push(s,top,infix[i]);
        }
        else{
            prefix[j++]=infix[i];
        }
    }
    while(!isEmpty(top))
    {prefix[j++]=pop(s,top);}
    prefix[j]='\0';
    int start=0,end=strlen(prefix)-1;
     printf("Prefix Before reverse:%s\n",prefix);
    while(start<end)    //reverse string
    {
        char temp=prefix[start];
        prefix[start]=prefix[end];
        prefix[end]=temp;
        start++;
        end--;
    }
    
}
int main()
{
    char infix[100],prefix[100];
    char s[100];
    int top=-1;
    printf("Enter infix:");
    scanf("%s",infix);
    infix[strcspn(infix,"\n")]=0;
    conversion(infix,prefix,s,&top);
    printf("Prefix:%s",prefix);
    getchar();

} 
