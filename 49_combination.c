/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/12/2021.
Description: Print all the possible combinations of given string.
Sample Execution: ./combinations
Enter a string: abc
abc
acb
bca
bac
cab
cba
Do you want to continue (Y/y) : y
Enter a string: abb
Error: please enter distinct characters.
Do you want to continue(Y/y) : n
 */

#include<stdlib.h>
#include<stdio.h>
void comb(char*, int, int);   //function prototype
void swap(char*, char*);
int main()
{
    char ch;                 //string and variable declaration.
    do                       //do-while loop initiated.
    {
	char str[50];       
	int l = 0, count=0, length = 0;
	printf("Enter a string: " );   //user prompt and read the input string.
	scanf("%s",str);
	while ( str[l] != '\0')        //loop to count the length of the string.
	{
	    length++;
	    l++;
	}
	int n = length;                //length stroed in a variable.
	for(int j = 0;j < n;j++)
	{
	    count=0;
	    for(int k = 0;k < n;k++)
	    {
		if(str[j] == str[k])          //condition if the adjacent characters are same.
		{
		    count++;             
		    if(count == 2)
			break;
		}
	    }
	    if(count == 2)                //if the adjacent characters are same then terminate program and pass error.       
		break;
	} 
	if(count == 2)    
	{
	    printf("Error: Please enter distinct characters\n");  //error displayed.
	}
	else
	{         //if adjacent characters are different then call function.
	    printf("All the possible combinations are:\n");
	    comb(str, 0, n-1);        //function call with actual parameters.
	}
	printf("Do you want to continue : ");     //user prompt and read the input.
	scanf(" %c",&ch);
    }while(ch == 'y' || ch == 'Y');   //if condition true do-while loop executed.
}
void swap(char *x,char *y)   //function to swap the characters received through arguments.
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
void comb(char *str,int start,int end)   //function definition with formal parameters.
{
    if(start == end)      //combination is printed once value of start equals end.
    {
	printf("%s\n",str);    //output.
    }
    else
    {
	for(int i=start;i <= end;i++)
	{
	    swap((str + start),(str + i));     //swap function called to swap the values of parameters.
	    comb(str,start + 1,end);           //recursive function call with updated value of start.
	    swap((str + start),(str + i));     //backtracking
	}
    }
}

