/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 25/12/2021.
Description: Implement fragments using array of pointers.
Sample execution: ./37_fragments.out
Enter the number of rows:3
Enter no. of columns in row[0]: 4
Enter no. of columns in row[1]: 3
Enter no. of columns in row[2]: 5
Enter 4 values of row[0]: 1 2 3 4
Enter 3 values of row[1]: 2 5 9
Enter 5 values of row[2]: 1 3 2 4 1
Before sorting output is: 
1 2 3 4 2.5 
2 5 9 5.33333 
1 3 2 4 1 2.2 
After sorting output is: 
1 3 2 4 1 2.2 
1 2 3 4 2.5 
2 5 9 5.33333 
Do yo want to continue?(y/Y):n
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice;   
    do      //do-while initiated.
    {
	int row, i, j;   //varaible declaration.
	printf("Enter the number of rows:");   //user prompt & read input.
	scanf("%d", &row); 
	float* arr[row];        //float type array pointer.
	int col[row];          //array declaration.
	//iterate over argument to get the numbe rof elements.
	for ( i=0; i<row; i++)
	{
	    printf("Enter no. of columns in row[%d]: ", i);   //user prompt and read the column numbers.
	    scanf("%d", &col[i]);
	    arr[i] = malloc ( (col[i] + 1) * sizeof(float));   //dynamic menory allocation.
	}
	//iterate over argument to get each element.
	for ( i = 0; i < row; i++)
	{
	    printf("Enter %d values of row[%d]: ", col[i],i);    //user prompt.
	    for ( j = 0; j < col[i]; j++)
	    {
		scanf("%f", &arr[i][j]);           //read inputs using scanf.
	    }
	}

	float sum = 0;       //initialization.
	//iterate over argument to calculate the sum of each row.
	for (i = 0; i < row; i++)
	{
	    for ( j = 0; j < col[i]; j++)
	    { 
		sum += arr[i][j];    //operation.
	    }
	    arr[i][col[i]] = sum / col[i];   //calculate average and store in the last vacent colum of each row.
	    sum = 0;   //reset sum=0 for next iteration.
	}
	printf("Before sorting output is: \n");  //print the arrays along with the average before sorting.
	for (i = 0; i < row; i++)
	{
	    for (j=0; j < (col[i]+1); j++)
	    {
		printf("%g ", arr[i][j]);     //print each element.
	    }
	    printf("\n");
	}
	float* temp;             //float type temp pointer.
	//iterate over argument and compare the averages to sort in ascending order.
	for (i = 0; i < row; i++)
	{
	    for ( j = 0; j < row-i-1; j++)
	    {
		if ( arr[j][col[j]] > arr[j+1][col[j+1]] )   //comparing the last column of each row i.e the avg element.
		{
		    temp = *(arr + j);    //swapping of the avg elements to sort iascending order.
		    *(arr + j) = *(arr+j+1);
		    *(arr+j+1)= temp;

		    int tmp = col[j];    //after avg is swapped accordingly the complete row is also swapped.
		    col[j] = col[j + 1];
		    col[j + 1] = tmp;
		}
	    }
	}
	printf("After sorting output is: \n");  //display the arrays afte rsorting.
	for (i = 0; i < row; i++)
	{
	    for (j = 0; j < (col[i]+1); j++)
	    {
		printf("%g ", arr[i][j]);   //print element one by one.
	    }
	    printf("\n");
	}
	for (i = 0; i < row; i++)    //free the dynamically allocated memory.
	{
	    free (arr[i]);
	}
	printf("Do yo want to continue?(y/Y):");   //user prompt and reach choice.
	scanf(" %c", &choice); 
    }while ( choice == 'y' || choice == 'Y');   //do-while loop executed if condition true.

}
