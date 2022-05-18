/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/12/2021.
Description:  Program to print n*n magic square based.
Sample i/p: ./32_magic_square.out
Enter the number:3

The 3x3 magic square is:
8   1   6 
3   5   7 
4   9   2 

Do you want to continue?(y/Y):y
Enter the number:12
Error:Enter only positive odd numbers.
Do you want to continue?(y/Y):y
Enter the number:-10
Error:Enter only positive odd numbers.
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int function (int, int, int**);    //function prototype.
int main()
{
    char choice;                   //character and integer variable declaration.
    int i, entry, row, col;
    do
    {
	printf("Enter the number:");   //user prompt and read the input.
	scanf("%d", &entry);
	__fpurge(stdin);               //to clear the std buffer.
	row = col = entry;             //for further reference the row & column is assigned to the input value.
	if ( entry > 0)                //condition to check valid input.
	{
	    if ( entry % 2 != 0)
	    {
		int** magic_square = calloc (row, sizeof(int*));  //dynamic memory allocation for rows.
		for (i=0; i <row; i++)
		{
		    magic_square[i] = calloc (col, sizeof(int));  //dynamic memory allocation for columns.
		}
		function (row, col, magic_square);          //function call with row, col and base address of array . 
		printf("\n");
		printf("The %dx%d magic square is:\n", row, col);    //o/p message.
		//to print the received matrix.
		for (row = 0; row < entry; row++) 
		{
		    for (col = 0; col < entry; col++)
		    {
			printf("%3d ", magic_square[row][col]);   //print element by element.
		    }
		    printf("\n");
		}
		printf("\n");
		free (magic_square);    //free the allocated memory.
	    }
	    else
		printf("Error:Enter only positive odd numbers.\n");   //error for invalid inputs.
	}
	else
	    printf("Error:Enter only positive odd numbers.\n");
	printf("Do you want to continue?(y/Y):");      //user prompt.
	scanf("%c", &choice);
	__fpurge(stdin);
    }while (choice == 'y' || choice == 'Y');        //do-while loop executes if user enters y/Y.
}
int function (int row, int col, int** magic_square)  //function definition.
{
    int  matrix,num;             //variable declaration.
    num = row;
    col = num/2;
    row = 0;
    matrix = num * num;
    for( int i = 1; i <= matrix ; i++ )   //loop to iterate till the last element of matrix.
    {
	magic_square[row][col] = i;       //we enter the element in 0th row and n/2 column as 1.
	if( (i % num) == 0 )              //if element is 0 we hop to next row.
	{
	    row++;                       //increase row.
	}
	else
	{
	    if( row == 0 )               //boundary for row number.
	    {
		row = num - 1;
	    }
	    else //next entry.
	    {
		row--;
	    }
	    if( col == ( num - 1 ) )     //boundary for column.
	    {
		col = 0;
	    }
	    else // hop for next entry.
	    {
		col++;                  //column incremented to shift right.
	    }
	}
    }
}
