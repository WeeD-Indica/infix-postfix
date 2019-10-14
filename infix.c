#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char q[10];
void postfix();
void infix();

int main()
{
  int c,s=1;
  while(s)
    {
      printf("\n1.Infix\n2.Postfix\nChoose your option(1-2): ");
      scanf("%d",&c);
      switch(c)
	{
	case 1:
	  infix();
	  break;
	case 2:
	  postfix();
	  break;
	default:
	  printf("\nError!!!\n");
	} 
      printf("\nDo you want to continue(0|1): ");
      scanf("%d",&s);
    }
}

void infix()
{
}
  

void postfix()
{
  int queue[10],st[10];
  int i=0,a=0;
  int ch=1;
  printf("\nEnter the postfix operators bit by bit(enter 0 to stop adding operator after entering the bit): \n");
  while(ch)
    {
      scanf("%c",&q[i]);
      scanf("%d",&ch);
      if(q[i]!='+'||q[i]!='-'||q[i]!='/'||q[i]!='*'||q[i]!='^')
	{
	  printf("Enter value of %c:",q[i]);
	  scanf("%d",&st[a]);
	  a++;
	}
      if(ch==0)
	q[i]='\0';
      i++;
    }
  i=0;
  while(q[i]!='\0')
    {
      i++; 
      if(q[i]=='+')
	{
	  st[a-1]+=st[a];
	  a--;
	}
      if(q[i]=='-')
	{
	  st[a-1]-=st[a];
	  a--;
	}
      if(q[i]=='*')
	{
	  st[a-1]*=st[a];
	  a--;
	}
      if(q[i]=='/')
	{
	  st[a-1]/=st[a];
	  a--;
	}
      if(q[i]=='^')
	{
	  st[a-1]=pow(st[a-1],st[a]);
	  a--;
	}
    }
  printf("\nInfix value: %d\n",st[0]);
}


