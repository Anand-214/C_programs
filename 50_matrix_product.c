/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 16/12/2021.
Description: To find the product of the matrix and its transpose.
Sample execution: ./product_matrix.out
Enter rows of matrix:3
Enter columns of matrix:3

Enter elements of 3x3 matrix:
1 2 3 1 2 3 1 2 3
The entered matrix is:
1 2 3 
1 2 3 
1 2 3 
Transpose of Matrix:
1  1  1  
2  2  2  
3  3  3  
The product of entered matrix and its transpose is:
14 14 14 
14 14 14 
14 14 14 
Do you want to continue?(y/Y):
 */


#include<stdio.h>
#include<stdlib.h>
void matrix_function (int, int, int**);   //function prototype.
int main()
{
    char choice;           //character variable declaration.
    do                     //do-while loop initiated.
    {
	int arow, acol, i, j;            //integer variable declaration.
	printf("Enter rows of matrix:");    //user prompt and read the input.
	scanf("%d", &arow);
	printf("Enter columns of matrix:");
	scanf("%d", &acol);
	int **a = malloc(arow * sizeof(int*));  //dynamic memory allocation for the entered matrix rows.
	for ( i = 0; i < arow; i++)              
	{
	    a[i] = malloc(acol * sizeof(int));  //dynamic memory allocation for columns of entered matrix.
	}
	printf("\nEnter elements of %dx%d matrix:\n",arow,acol);   //user prompt and read the elements ont by one.
	for(i = 0; i < arow; i++)
	{
	    for(j = 0; j < acol; j++)
	    {
		scanf("%d", &a[i][j]);    
	    }
	}
	printf("\n");
	//Display the entered matrix.
	printf("The entered matrix is:\n");
	for ( i = 0; i < arow; i++)
	{
	    for (j = 0; j < acol; j++)
	    {
		printf("%d ", a[i][j]);
	    }
	    printf("\n");
	}
	matrix_function (arow, acol, a);   //function call with actual parameters as row,column and the i/p matrix.
	free(a);                           //to free the allocated memory.
	printf("Do you want to continue?(y/Y):");   
	scanf(" %c", &choice);
    }while (choice == 'y' || choice == 'Y');   //do-while loop executed if condition true.
}
void matrix_function (int arow, int acol, int** a)  //function definition.
{
    int trow, tcol, i, j, sum = 0;
    trow = acol;   //for transpose the no. of rows is considered as columns and no. of columns is considered as rows.
    tcol = arow;
    int** transpose = malloc(trow * sizeof(int*));   //dynamic memory allocation for rows of transpose matrix.
    for ( i = 0; i<trow; i++)
    {
	*(transpose + i) = malloc(tcol * sizeof(int));    //dynamic memory for the number of columns of transpose matrix.
    }
    int** product = malloc(sizeof(int*)*arow);     //dynamic memory allocation for rows of product matrix.

    for ( i = 0; i < arow; i++)
    {
	*(product + i) = malloc(tcol * sizeof(int));   //dynamic memory for the number of columns of product matrix.
    }
    // Finding the transpose of matrix and printing it.
    printf("\nTranspose of Matrix:\n");
    for(i = 0; i < trow; i++)
    {
	for(j = 0; j < tcol; j++)
	{
	    transpose[i][j] = a[j][i];  //since the rows of i/p matrix are the columns of the transpose matrix & vise versa.
	    printf("%d  ",transpose[i][j]);   
	}
	printf("\n");    //to shift the new row elements on next line.
    }
    //for the product of matrix.
    printf("\n");
    printf("The product of entered matrix and its transpose is:\n");
    for (i=0; i < arow; i++)
    {
	for (j=0; j < tcol; j++)
	{
	    for (int k = 0; k < trow; k++)
	    {
		sum += a[i][k] * transpose[k][j];   //since product is obtained after travesing row wise and column wise.
	    }
	    product[i][j] = sum;   //the obtained sum is the particular element.
	    printf("%d ", product[i][j]);  //print the obtained element.
	    sum=0;   //again for the next element the sum starts with zero.
	}
	printf("\n");
    }
    free(transpose);   //free the dynamically allocated memory for transpose and product matrix.
    free(product);
}
