/*Documentation.
Name: Anand Arvind Kulkarni.
Date: 2/12/2021
Description: Print the value in sorted order without modifying array.
Sample Execution: ./sort_array.out
Enter the count of float elements need to store:5
[0] = 10.0
[1] = 1.2
[2] = 3.2
[3] = 8.2
[4] = -1.4
After sorting: -1.4 1.2 3.2 8.2 10 
Do you want to continue?(y/Y):n

 */
#include<stdio.h>
int array_sort (float*, int);    //function prototype.
int main()                     
{
    char choice;           //varaible with character datatype declared.
    do                    //do-while loop initiated.
    {
	int size,i;       //integer variables.
	printf("Enter the count of float elements need to store:");   //size of array input from user.
	scanf("%d", &size);
	float arr[size];            //array declaration.
	for (i = 0; i < size; i++)
	{
	    printf("[%d] = ", i);  //user input for each element of array.
	    scanf("%f", &arr[i]);  //the i/p is real hence %f format specifier. 
	}
	array_sort (arr, size);    //function call.
	printf("Do you want to continue?(y/Y):");  
	scanf(" %c", &choice);
    }while ( choice == 'y' || choice == 'Y');   //do-while loop executes if the i/p is y or Y only.
    return 0;
}
int array_sort (float* arr, int size)    //function declaration.
{
    int i, j;
    float min, max, least;
    min = *(arr);        //the first element stored as min.
    max = *(arr);        //the first element stored as max.

    for (i = 0; i < size; i++)
    {
	if (min > *(arr + i) )
	{
	    min = *(arr + i);   //minimum value is stored here.
	}
	if (max < *(arr + i) )
	{
	    max = *(arr + i);   //maximum value is stored here.
	}
    }
    least = max;        //least variable stored with the max value.
    printf("After sorting: ");
    printf("%g ", min);
    //to print the array after sorting in ascending form.
    for (i = 0; i < (size-1); i++)
    {
	for (j = 0; j < size; j++)
	{
	    if ( *(arr+j) > min && *(arr + j) < least )   //condition to compare the elements.
	    {
		least = *(arr + j);   //updating the least which was the max initially.
	    }
	}
	printf("%g ", least);  //print the least value.
	min = least;   //these two steps swap the smaller value to the least variable. 
	least = max;    
    }
    printf("\n");
}

