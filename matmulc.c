#include<stdio.h>
#include<stdlib.h>

void printmatrix(int **mat, int r, int c)
{
	printf("\nmatrix entries: ");
	int i,j;
	for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		{
		printf("  %d",mat[i][j]);
		}
	}
}

int ** matmul(int** mat1,int r1, int c1, int** mat2,int r2,int c2)
{  int i,j,k,**result;

	result=(int**) malloc(r1*sizeof(int*));
	for(i=0;i<r1;i++)
	    {
		    result[i]=(int*) malloc(c2*sizeof(int));
	    }
	
	    for(i=0;i<r1;i++)
		for(j=0;j<c2;j++)
	           for(k=0;k<r2;k++)
			result[i][j]+=mat1[i][k]*mat2[k][j];
return result;
}

int main(int argc, char *argv[])
{
int **mat1,**mat2,**mat3;
int i,j,r1,c1,r2,c2;

printf("\nEnter values of rows and cols for matrix1\n");
scanf("\n%d %d",&r1,&c1);
printf("\nEnter values of rows and cols for matrix2\n");
scanf("\n%d %d",&r2,&c2);

if(c1!=r2)
{
    printf("Invalid Order of matrix");
    exit(EXIT_SUCCESS);
}

mat1=(int**)  malloc(r1*sizeof(int*));
mat2=(int**)  malloc(r2*sizeof(int*));

for(i=0;i<r1;i++)
{
	mat1[i]=(int*) malloc(c1*sizeof(int));
	for(j=0;j<c1;j++)
	{
	mat1[i][j]=i+1;
	}

}

for(i=0;i<r2;i++)
{
	mat2[i]=(int*) malloc(c2*sizeof(int));
	
	for(j=0;j<c2;j++)
	{
	mat2[i][j]=i+1;

	}
}

printmatrix(mat1,r1,c1);
printmatrix(mat2,r2,c2);

mat3=matmul(mat1,r1,c1,mat2,r2,c2);
printmatrix(mat3,r1,c2);
for(i=0;i<r1;i++)
free(mat1[i]);
for(i=0;i<r2;i++)
free(mat2[i]);

free(mat1);
free(mat2);
return 0;

}
