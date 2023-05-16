#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"

int nrows;
int ncolomns;

//function to print matrices.
void printmatrix(double matrix[100][100])
{
    int r,c;
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
            printf("%.2lf\t",matrix[r][c]);
        }
        printf("\n");
    }
}
//function to add matrices.
void addmatrix(double x[100][100],double y[100][100],double z[100][100])
{
    int r,c;
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
            z[r][c]=x[r][c]+y[r][c];
        }
    }
}
//function to subtract matrices
void subtractmatrix(double x[100][100],double y[100][100],double z[100][100])
{
    int r,c;
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
            z[r][c]=x[r][c]-y[r][c];
        }
    }
}
//function to multiply matrices
void multiplymatrix(double x[100][100],double y[100][100],double z[100][100])
{
    int r,c,k;
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
          z[r][c]=0;
          for(k=0;k<nrows;k++)
            z[r][c]+=x[r][k]*y[k][c];
        }
    }
}

void main()
{
  int i,r,c;
  char text[20];
  double x[100][100];
  double y[100][100];
  double z[100][100];

  do
  {
      //get the number of rows and colomns from user.
      printf("enter the number of rows:");
      scanf("%d",&nrows);
      printf("enter the number of colomns:");
      scanf("%d",&ncolomns);
      //get the two matrices.
      printf("enter the first matrix:\n");
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
            printf("enter the element(%d,%d)",r+1,c+1);
            scanf("%lf",&x[r][c]);
        }
    }
      printf("enter the second matrix:\n");
    for(r=0;r<nrows;r++)
    {
        for(c=0;c<ncolomns;c++)
        {
            printf("enter the element(%d,%d)",r+1,c+1);
            scanf("%lf",&y[r][c]);
        }
    }
    //get character from user to add,subtract or multiply.
    printf("enter (+) for addition,(-)for subtraction,(*)for multiplication:");
    switch(getche())
    {
    case '+':
    {
        printf("\n the addition of the two matrices is :\n");
        addmatrix(x,y,z);
        printmatrix(z);
    }
    break;
    case '-':
    {
        printf("\n the subtraction of the two matrices is :\n");
        subtractmatrix(x,y,z);
        printmatrix(z);
    }
    break;
    case '*':
    {
    if(nrows==ncolomns)
       {
        printf("\n the multiplication of the two matrices is :\n");
        multiplymatrix(x,y,z);
        printmatrix(z);
       }
    }
        break;
    }
    printf("if you want to end ,just type (end),if you want to continue , type(continue).\n");
    scanf("%s",text);
    if(strcmp(text,"end")==0) i=1;
    else continue;
  }
    while(i==0);
}
