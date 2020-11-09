#include<conio.h>
#include<stdio.h>
#include<math.h>
int i,Q[4],A[4]={0,0,0,0};
void add(int *a,int *b)
{
	int x,i,c=0;
	for(i=3;i>=0;i--)
	{
		x=a[i];
		a[i]=c^x^b[i];
		if(((c==1)&&(x==1))||((x==1)&&(b[i]==1))||((b[i]==1)&&(c==1)))
			c = 1;
		else
			c = 0;

	}
}
void binary(int x,int*arr)
{
	int i,p=x,c[4]={0,0,0,1};
	for(i=0;i<4;i++)
		arr[i] = 0;
	if(x < 0)
		x = x *-1;
	i = 3;
	do
	{
		arr[i]=x%2;
		x = x/2;
		i--;
	}while(x!=0);
	if(p<0)   //compliment//
	{
		for(i=0;i<4;i++)
			arr[i]=1-arr[i];
		add(arr,c);
	}
	printf("\n");
	printf("THE BINARY EQUIVALENT OF %d IS : ",p);
	for(i=0;i<4;i++)
	  printf("%d",arr[i]);
       printf("\n");

}


void lshift()
{
	for(i=0;i<=2;i++)
		A[i]=A[i+1];
	A[3]=Q[0];
	for(i=0;i<=2;i++)
		Q[i]=Q[i+1];
	Q[3]=0;
}
void main()
{
  int q,m,M[4],t1[4]={0,0,0,1},c1[4],count=4,sq=0,sr=0;
  clrscr();
  printf("\t\t\t\t DIVISION ALGORITHM \n\n");
  printf("Enter Q(Dividend) and M(Divisor):");
  scanf("%d%d",&q,&m);
  binary(q,Q);
  binary(m,M);
  printf("OPERATION\t\t A\t Q\tcount\n");
  printf("Initial\t\t\t ");

	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");


printf("%d\n",count);
 while(count!=0)
 {
   if(A[0]==1)
   {  lshift();
     add(A,M);
      printf("left shift,A:A+M\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");

printf("%d\n",count);
     }
   else
   { lshift();
   for(i=3;i>=0;i--)
   {
     c1[i]=1-M[i];
    }
  add(c1,t1);
  add(A,c1);
  printf("left shift,A:A-M\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");

printf("%d\n",count);
  }
  if(A[0]==1)
   {  Q[3]=0;
      printf("Q[3]=0\t\t\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");

printf("%d\n",count);
   }
  else
   {  Q[3]=1;
	printf("Q[3]=1\t\t\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");

printf("%d\n",count);
   }
  count--;
 }
 if(A[0]==1)
   {  add(A,M);
	printf("A:A+M\t\t\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");


printf("%d\n",count);
   }
  else
   {      }
     printf("Final\t\t\t ");


	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}
    printf("\t");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");

printf("%d\n",count);
   printf("Q(Quotient):  ");
	for(i=0;i<=3;i++)
	    {printf("%d",Q[i]);}
printf("\t");
printf("A(Remainder):  ");
	for(i=0;i<=3;i++)
	    {printf("%d",A[i]);}

   printf("\n");
printf("Quotient: ");
for(i=0;i<=3;i++)
{
sq=sq+pow(2,3-i)*Q[i];
}
printf("%d\t\t",sq);
printf("Remainder: ");
for(i=0;i<=3;i++)
{
sr=sr+pow(2,3-i)*A[i];
}
printf("%d",sr);

   getch();
   }
