#include <stdio.h>
#include <stdlib.h>
#define MAX 32

void my_sort(char (*)[], int);            //Function prototypes.
void my_strcpy(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);

int main()
{
    int rows, i, input;          //Declaring the variables 
    char option;
    do
    {
	printf("Enter number of strings : ");   //Enter the number of strings and store it in the variable
	input = scanf("%d", &rows);
	if (input != 1)                         //Validating the entered value
	{
	    printf("Invalid input\n");
	    return 0;
	}
	char array[rows][MAX];                    //Declaring array of strings

	printf("Enter %d strings\n", rows);         //Enter the strings one by one
	for(i = 0; i < rows; i++)
	{
	    printf("[%d]", i);
	    scanf("%s", array[i]);
	}
	my_sort(array, rows);                      //Calling my_sort function

	printf("\nAfter Sorting:\n");            //Printing the names after my_sort
	for(i = 0; i < rows; i++)
	{
	    printf("%s\n", array[i]);
	}
	printf("Do you wish to continue?(y/Y): ");
	scanf(" %c", &option);

    }while (option == 'Y' || option == 'y');
    return 0;
}

void my_sort(char (*array)[50], int rows)             //Defining my_sort function
{
    int i, j;
    char temp[50];
    for (i = 0; i < rows; i++)
    {
	for (j = i + 1; j < rows; j++)
	{
	    if (my_strcmp(array[i], array[j]) > 0)    //Comapring each string
	    {
		my_strcpy(temp,array[i]);             //Swapping the strings
		my_strcpy(array[i], array[j]);
		my_strcpy(array[j], temp);
	    }
	}
    }
}
void my_strcpy(char *str1, char *str2)   //Defining my_strcpy function 
{
    char temp[50] = {'\0'};
    int index = 0;

    while (str2[index] != '\0')           //Copying character by character
    {
	str1[index] = str2[index];
	index++;
    }
    str1[index] = '\0';
}
int my_strcmp(char *str1, char *str2)  //Defining my_strcmp function
{
    while( (*str1 != '\0' && *str2 != '\0' ) && *str1 == *str2)
    {
	str1++;
	str2++;
    }

    if(*str1 == *str2)
    {
	return 0; // strings are identical
    }

    else
    {
	return *str1 - *str2;
    }
}


