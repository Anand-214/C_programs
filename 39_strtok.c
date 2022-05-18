/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/12/2021.
Description: Implementation of strtok function.
Sample Execution: ./strtok.out
Enter the 1st string: Banglore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter the 2nd string (delimiter): ;:/-.
Banglore
Chennai
Kolkata
Delhi
Mumbai
Do you want to continue?(y/Y):n
 */

#include <stdio.h>
#include<stdio_ext.h>
char *my_strtok(char *, char *);   //function prototype.
int main()
{
    char option;    //variable declaration.
    do              //do-while loop initiated.
    {
	char str1[100], str2[80];     //array declaration.  
	printf("Enter the 1st string: ");           //user prompt and the input is read.
	scanf("%[^\n]s", str1);
	__fpurge(stdin);
	printf("Enter the 2nd string (delimiter): ");
	scanf("%[^\n]s", str2);
	__fpurge(stdin);
	char *res = my_strtok(str1, str2);          //function call and return value stored in character pointer. 

	while (res != NULL)                         //loop to print the output.
	{
	    printf("%s\n", res);
	    res = my_strtok(NULL, str2);               //function called to get the string after the delimiter.
	}
	printf("Do you want to continue?(y/Y):");   //user prompt.
	scanf("%c", &option);        
	__fpurge(stdin);                             //to clear the stdin buffer.
    } while (option == 'Y' || option == 'y');    //do-while loop executes when condition is true.
}

char *my_strtok(char *str1, char *str2)   //function definition.Here the function returns address so return type is pointer.
{
    int j = 0;                                  //variable declaration.
    static int i;
    static char *temp; 
    int length = i;       //stored i in temp to use the valueof i after it is further changed.
    if (str1 != NULL)         //condition to check the string.
    {
	temp = str1;
    }
    while (temp[i] != '\0')  //loop till the first string doesnt encounter \0.
    {
	j = 0;
	while (str2[j] != '\0')   //loop till  the delimeter string doesnt encounter \0. 
	{
	    if (str2[j] == temp[i])     //condition to Check delimiter string.
	    {
		temp[i] = '\0';
		i++;
		if (temp[length] != '\0')    //condition to check temp value. 
		{
		    return (&temp[length]);
		}
		else          //condition if temp value encounters \0.
		{
		    length = i;   //update length as i for iteration when temp = \0.
		    i--;
		    break;
		}
	    }
	    j++;                  //for next iteration of while loop incrementing i & j value.
	}
	i++;                     
    }
    if (temp[length] == '\0')     //condition when temp value is \0.  i.e end of string.
    {
	i = 0;
	return NULL;        
    }
    else
    {
	return (&temp[length]);    //return address of temp.
    }
}
