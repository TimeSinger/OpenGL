#include<stdlib.h>
#include<stdio.h>

int chery[8][8]={0};
const int N=8;
int sum=0;
int a[50]={0};
int b[50]={0};
int c[50]={0};
void print();

void visit(int x);

int main()
{

	visit(0);
	printf("\n总共有%d种放置方法。\n",sum);
	return 0;
 } 
 
 void visit(int column)
 {
 	if(column>7)
 	{
 		return;
	 }
 	for(int row=0;row<N;row++)
 	{
 		if(a[row]==0 && b[row+column]==0 && c[row-column+7]==0)
 		{
 			a[row]=1;
 			b[row+column]=1;
 			c[row-column+7]=1;
 			chery[row][column]=1;
 			if(column==7)
 			{
 				sum++;
 				if(sum==1)
 				{
 					printf("\n其中一种放置方法：\n");
 					print();
				 }
		    }
			else
			{
			    visit(column+1);
			}
			a[row]=0;
 		   	b[row+column]=0;
 			c[row-column+7]=0;
 			chery[row][column]=0;
		 } 
		 
	 }
	 
	 	
 }
 
 void print()
 {
 	for(int i=0;i<N;i++)
 	{
 		for(int j=0;j<N;j++)
 		{
 		
 			printf("%d ",chery[i][j]);
 			
		 }
		 printf("\n");
	 }
 }
