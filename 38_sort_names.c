/*
   Documentation
Name: Anand Arvind Kulkarni.
Date:26/12/2021
Description:Read N & N person names of maxlen 32. Sort and print the names.
Sample execution: ./Sort_names.out

Enter the 5 names of length max 32 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:
[0] -> Agra
[1] -> Bengaluru
[2] -> Chennai
[3] -> Delhi
[4] -> Kolkata

 */

#include <stdio.h>
#include <stdlib.h>

void sort(char (*array)[32], int rows); //sorting function
int my_strcmp(char*, char*);		//string compare function
void my_strcpy(char*, char*); //string copy function
int main()
{
    int rows, i;
    char ch;
    do
    {
	printf("Enter number of strings : ");
	scanf("%d", &rows); 					//reading total number of strings

	char (*array)[32] =  malloc(sizeof(rows) * 32);     //array declaration

	printf("Enter the %d names of length max 32 characters in each\n", rows);
	for(i = 0; i < rows; i++)		//reading strings one by one
	{
	    printf("[%d] -> ", i);
	    scanf("%s", *(array + i));
	}
	sort(array, rows); //function call
	printf("\nThe sorted names are:\n");     //Printing the names after sorting
	for(i = 0; i < rows; i++)
	{
	    printf("[%d] -> %s\n",i,*(array + i));
	}

	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &ch);
	free (array);

    }while ( ch == 'y' || ch == 'Y' );

    return 0;
}
void my_strcpy(char *str1, char *str2) //string copy function
{
    int i = 0;
    while (str2[i] != '\0') //loop to copy each character 
    {
	str1[i] = str2[i];
	i++;
    }
    str1[i] = '\0';
}

int my_strcmp(char *str1, char *str2)		//string compare function
{
    while( (*str1 != '\0' && *str2 != '\0' ) && *str1 == *str2)
    {
	str1++;
	str2++;
    }

    if(*str1 == *str2)		//comparing strings
	return 0;	
    else
	return *str1 - *str2;
}

void sort(char (*array)[32], int rows) //sorting function
{
    int i, j;
    char temp[32];

    for (i = 0; i < rows; i++)
    {
	for (j = i + 1; j < rows; j++)
	{
	    if (my_strcmp(array[i], array[j]) > 0)     //Comparing each string
	    {
		my_strcpy(temp, array[i]);    //Swapping the strings
		my_strcpy(array[i], array[j]);
		my_strcpy(array[j], temp);
	    }
	}
    }
}

