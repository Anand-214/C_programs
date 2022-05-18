/*Documentation:
Name: Anand Arvind KUlkarni
Date: 12/12/2021
Description: Squeeze the character in S1 that matches any character in string S2.
Sample execution: ./squeeze.out
Enter string 1: Dennis Ritchie
Enter the string 2: Linux
After squeeze string 1:Des Rtche
 */

#include <stdio.h>
#define MAX 200             //defining macro with the max length of the string.
void squeeze(char*, char*);  //function prototype.
void main()  
{
    char str1[MAX], str2[MAX];   //declaration of two strings.
    int i, j;
    printf("\nEnter string 1: ");
    fgets(str1, MAX, stdin);      //fgets used to collect the user i/p.
    printf("\nEnter the string 2: ");
    fgets(str2, MAX, stdin);  
    squeeze (str1, str2);   //squeeze function called with actual arguments as the two input strings.
    printf("\nAfter squeeze string 1:");
    printf("%s\n", str1);
}
void squeeze(char *str1, char *str2)   //function definition with formal parameters.
{
    int i, j, k = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
	//Logic where any matched position characters will be skipped, thereby removing the charaters in string 1
	for (j = 0; (str1[i] != str2[j]) && ((str2[j]) != '\0'); j++);  
	if (str2[j] == '\0') 
	{
	    *(str1 + (k++)) = str1[i];
	}
    }
    str1[k] = '\0';   //this is the updated squeezed string.
}
