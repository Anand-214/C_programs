/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 13/12/2021.
Description: Program to replace each string of one or more blanks by a single blank.
Sample execution:
Enter the string with more spaces:
Pointers   are           sharp      	knives    !!!!
String with reduced spaces:
Pointers are sharp knives !!!!
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
#include<stdio_ext.h>
void extra_spaces (char str[]);           //function prototypes.
int my_strcpy ( char dest[], char src[]);
int main()
{
    char str[200], choice;    //string and variable declarations.
    do
    {
	printf("Enter the string with more spaces:\n");    //user prompt and read the user input.
	scanf("%[^\n]s", str);           
	__fpurge(stdin);                //clear the stdin buffer.
	extra_spaces(str);              //function call and passing the string to the function.
	printf("String with reduced spaces:\n");
	printf("%s\n", str);       //output string.
	printf("Do you want to continue?(y/Y):");   //user prompt and read the user input.
	scanf("%c", &choice);             
	__fpurge(stdin);                    
    }while ( choice == 'y' || choice == 'Y');   //do-while loop executed when condition true.
    return 0;
}
void extra_spaces (char str[])       
{
    int i = 0, count = 0;      // to count the string length.
    while ( str[i] != '\0')
    {
	count++;
	i++;
    }
    int strlength = count;   //string length stored in
    char squeezed[strlength + 1];   //if the original string has no extra spaces we need one extra place to store \0.
    int j = 0;

    for (int i = 0; i < strlength; i++)
    { 
	//conditions to check possibilities of various spaces which can be inserted in the string.	
	if ((str[i] == '\t' && str[i + 1] == '\t')  || ( str[i] == '\t' && str[i + 1] == ' '))   
	    str[i] = str[i + 1] = ' ';        //consecutive tabs as well as tabs and spaces are converted into spaces.
	if ((str[i] == '\t') || (str[i] == ' ' && str[i + 1] == '\t'))
	    str[i] = str[i + 1] = ' ';      //consecutive tabs as well as spaces with tabs are converted into spaces.
	if (str[i] == ' ' && str[i + 1] == ' ')
	    continue;
	else
	    squeezed [j++] = str[i];   //if no consecutive blanks then the string is stored in new string.  
    }
    squeezed[j] = '\0';    //to add \0 as the last character of the new string.
    my_strcpy(str, squeezed);           //we need to copy the squeezed string to the main string again so function called.
}
int my_strcpy (char dest[], char src[])    //definition of my_strcpy function with formal parameters.
{
    int i = 0;
    for ( i = 0; src[i] != '\0'; i++)
    {
	dest[i] = src[i];
    }
    dest[i] = '\0';    //to store \0 as last character of the updated string.
}
