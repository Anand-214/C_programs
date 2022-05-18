/*Documentation:
Name: Anand Arvind Kulkarni
Date: 21/12/2021.
Description : To implement binary search of all basic data types.
Sample Execution: ./binary_search.out
Select the type of array:
1.Integer
2.Short
3.Float
4.Double
5.Char
Select you choice:1
Enter 4 elements of type int: 1 4 2 7
Sorted array: 1 2 4 7
Enter the key value: 7
Search element 7 is at position 3 of array.
Do you wish to continue?(y/Y):n
 */


#include<stdio.h>
#include<stdlib.h>

//Declare the function prototypes.
int my_atoi(char*);        
void i_sort(void *, int);                
void i_binary_search(void *, int, int);
void s_sort(void *, int);
void s_binary_search(void *, int, short);
void f_sort(void *, int);
void f_binary_search(void *, int, float);
void d_sort(void *, int);
void d_binary_search(void *, int, double);
void c_sort(void *, int);
void c_binary_search(void *, int, char);

int main(int argc, char* argv[])
{
    int i, size, select;   //Declare variables.
    char option;
    do                   //do-while loop initiated.
    {
	if (argc == 2)   //to check if the number is passed through command line or not.
	{
	    size = my_atoi (argv[1]);       ///assigning the value of argv[1] to size.
	    void* arr;

	    printf("Select the type of array:\n1.Integer\n2.Short\n3.Float\n4.Double\n5.Char\nSelect you choice:");   //Prompt & read the input.
	    scanf("%d", &select);

	    switch(select)   //switch case based on the select value.
	    {
		case 1:      //case 1 for integer.
		    {
			int key;
			//allocation of memory to the int array during runtime/
			arr = malloc(size * sizeof(int));
			printf("Enter %d elements of type int: ",size);   //Prompt & read the values of the array.
			for (i = 0; i < size; i++)
			{
			    scanf("%d", (int*)arr + i);
			}
			i_sort(arr, size);      //Calling the sorting funtion.

			printf("Sorted array: ");           //Display the sorted array.
			for (i = 0; i < size; i++)
			{
			    printf("%hd ", *((int*)arr + i));
			}

			printf("\nEnter the key value: ");   //Prompt & read the key value.
			scanf("%d", &key);

			i_binary_search(arr, size, key); //Binary search function call for binary search of integers.
			break;
		    }

		case 2:       //case 2 for short type values of array.
		    {
			int key2;
			//allocation of memory to the short array during runtime.
			arr = malloc(size * sizeof(short));
			printf("Enter %d elements of type short: ",size);   //Prompt & read the values of the array.
			for (i = 0; i < size; i++)
			{
			    scanf("%hd", (short*)arr + i);
			}

			s_sort(arr, size);         //Calling the sorting funtion.

			printf("Sorted array: ");     //Display the sorted array.
			for (i = 0; i < size; i++)
			{
			    printf("%d ", *((short*)arr + i));
			}

			printf("\nEnter the key value: ");  //Prompt & read the key value.
			scanf("%d", &key2);

			s_binary_search(arr, size, key2);   //binary search function for short values.
			break;
		    }
		case 3:      //case 3 for float type values.
		    {
			float key3;
			//allocation of memory to the float type array during runtime.
			arr = malloc(size * sizeof(float));
			printf("Enter %d elements of type float: ",size);   //Prompt & read the values of the array.
			for (i = 0; i < size; i++)     //Prompt + read the values of the array
			{
			    scanf("%f", (float*)arr + i);
			}

			f_sort(arr, size);     //Calling the sorting funtion.

			printf("Sorted array: ");              //Display the sorted array.
			for (i = 0; i < size; i++)
			{
			    printf("%g ", *((float*)arr + i));
			}

			//Prompt + read the key value
			printf("\nEnter the key value: ");
			scanf("%f", &key3);

			//Calling the binary search function
			f_binary_search(arr, size, key3);
			break;
		    }
		case 4:
		    {
			//Define the allocation of memory to the array during runtime
			arr = malloc(size * sizeof(double));
			double key4;
			printf("Enter %d elements of type double: ",size);   //Prompt & read the values of the array.
			for (i = 0; i < size; i++)
			{
			    scanf("%lf", (double*)arr + i);
			}

			//Calling the sorting funtion
			d_sort(arr, size);

			//Display the sorted array
			printf("Sorted array: ");
			for (i = 0; i < size; i++)
			{
			    printf("%g ", *((double*)arr + i));
			}

			//Prompt + read the key value
			printf("\nEnter the key value: ");
			scanf("%lf", &key4);

			//Calling the binary search function
			d_binary_search(arr, size, key4);
			break;
		    }
		case 5:      //case 1 for character.
		    {
			char key5;
			//allocation of memory to the int array during runtime/
			arr = malloc(size * sizeof(char));
			printf("Enter %d elements of type char: ",size);   //Prompt & read the values of the array.
			for (i = 0; i < size; i++)
			{
			    scanf(" %c", (char*)arr + i);
			}
			c_sort(arr, size);      //Calling the sorting funtion.

			printf("Sorted array: ");           //Display the sorted array.
			for (i = 0; i < size; i++)
			{
			    printf("%c ", *((char*)arr + i));
			}

			printf("\nEnter the key value: ");   //Prompt & read the key value.
			scanf(" %c", &key5);

			c_binary_search(arr, size, key5); //Binary search function call for binary search of integers.
			break;
		    }
		default:
		    printf("Invalid entry.Please select option from the displayed menu.\n");
		    return 0;
	    }
	    free (arr);
	    printf("Do you wish to continue?(y/Y):");
	    scanf("\n%c", &option);
	}
	else
	{
	    printf("ERROR:Enter 1 integer through command line.\ne.g: ./a.out 5\n");
	}

    }while (option == 'Y' || option == 'y');   //do-while loop executed if user wish to continue.
}
//Defining the sort function of integer values.
void i_sort(void *a, int lim)
{
    int temp, i, j;               

    for (i = 0; i < lim; i++)
    {
	for (j = 0; j < lim-1-i; j++) 
	{
	    if (*((int *)a + j) > *((int *)a + j + 1))      //function perfroms sorting of the elements of array.
	    {
		temp = *((int *)a + j);
		*((int *)a + j) = *((int *)a + j + 1);
		*((int *)a + j + 1) = temp;
	    }
	}
    }
}

//Defining the binary search function for integers.
void i_binary_search(void *a, int lim, int key)
{
    int begin = 0;
    int end = lim - 1;
    int mid;

    while (begin <= end)
    {	
	mid = (begin + end) / 2;

	if (key > *((int *)a + mid))
	{
	    begin = mid + 1;
	}
	else if (key < *((int *)a + mid))
	{
	    end = mid - 1;
	}
	else
	{
	    printf("Search element %d is at position %d of array.\n", key, mid);
	    return;
	}
    }
}
//Defining the sort function of short values.
void s_sort(void *a, int lim)
{
    int temp, i, j;

    for (i = 0; i < lim; i++)
    {
	for (j = 0; j < lim-1-i; j++)
	{
	    if (*((short *)a + j) > *((short *)a + j + 1))
	    {
		temp = *((short *)a + j);
		*((short *)a + j) = *((short *)a + j + 1);
		*((short *)a + j + 1) = temp;
	    }
	}
    }
}

//Defining the binary search function for short values.
void s_binary_search(void *a, int lim, short key2)
{
    int begin = 0;
    int end = lim - 1;
    int mid;

    while (begin <= end)
    {	
	mid = (begin + end) / 2;

	if (key2 > *((short *)a + mid))
	{
	    begin = mid + 1;
	}
	else if (key2 < *((short *)a + mid))
	{
	    end = mid - 1;
	}
	else
	{
	    printf("Search element %d is at position %d of array.\n", key2, mid);
	    return;
	}
    }
}
//Defining the sort function of float values.
void f_sort(void *a, int lim)
{
    int i, j;
    float temp;

    for (i = 0; i < lim; i++)
    {
	for (j = 0; j < lim-1-i; j++)
	{
	    if (*((float *)a + j) > *((float *)a + j + 1))
	    {
		temp = *((float *)a + j);
		*((float *)a + j) = *((float *)a + j + 1);
		*((float *)a + j + 1) = temp;
	    }
	}
    }
}

//Defining the binary search function  for float values.
void f_binary_search(void *a, int lim, float key3)
{
    int begin = 0;
    int end = lim - 1;
    int mid;

    while (begin <= end)
    {	
	mid = (begin + end) / 2;

	if (key3 > *((float *)a + mid))
	{
	    begin = mid + 1;
	}
	else if (key3 < *((float *)a + mid))
	{
	    end = mid - 1;
	}
	else
	{
	    printf("Search element %g is at position %d of array.\n", key3, mid);
	    return;
	}
    }
}
//Defining the sort function of double  values.
void d_sort(void *a, int lim)
{
    int temp, i, j;

    for (i = 0; i < lim; i++)
    {
	for (j = 0; j < lim-1-i; j++)
	{
	    if (*((double *)a + j) > *((double *)a + j + 1))
	    {
		temp = *((double *)a + j);
		*((double *)a + j) = *((double *)a + j + 1);
		*((double *)a + j + 1) = temp;
	    }
	}
    }
}

//Defining the binary search function for double values.
void d_binary_search(void *a, int lim, double key4)
{
    int begin = 0;
    int end = lim - 1;
    int mid;

    while (begin <= end)
    {	
	mid = (begin + end) / 2;

	if (key4 > *((double *)a + mid))
	{
	    begin = mid + 1;
	}
	else if (key4 < *((double *)a + mid))
	{
	    end = mid - 1;
	}
	else
	{
	    printf("Search element %g is at position %d of array.\n", key4, mid);
	    return;
	}
    }
}
void c_sort(void *a, int lim)
{
    int temp, i, j;               

    for (i = 0; i < lim; i++)
    {
	for (j = 0; j < lim-1-i; j++) 
	{
	    if (*((char *)a + j) > *((char *)a + j + 1))      //function perfroms sorting of the elements of array.
	    {
		temp = *((char *)a + j);
		*((char *)a + j) = *((char *)a + j + 1);
		*((char *)a + j + 1) = temp;
	    }
	}
    }
}
void c_binary_search(void *a, int lim, char key5)
{
    int begin = 0;
    int end = lim - 1;
    int mid;

    while (begin <= end)
    {	
	mid = (begin + end) / 2;

	if (key5 > *((char *)a + mid))
	{
	    begin = mid + 1;
	}
	else if (key5 < *((char *)a + mid))
	{
	    end = mid - 1;
	}
	else
	{
	    printf("Search element %c is at position %d of array.\n", key5, mid);
	    return;
	}
    }
}
int my_atoi(char *ptr) //converting character to integer.
{
    int res = res * 10 + ptr[0] - '0';  //Storing integer value in variable
    return res; //Returning value into integer
}
