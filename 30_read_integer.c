/*Documentation:
Name: Anand Arvind Kulkanri.
Date: 29/11/2021.
Description: Function read_int to read an integer.
Sample Execution: ./read_int.c
Enter the number: 123
The entered number is : 123
Do you want to continue?(y/Y) : y
Enter the number: 21287jkh
The entered number is : 21287
Do you want to continue?(y/Y) : y
Enter the number: ak212
The entered number is : 0
 */

#include<stdio.h>
#include<stdio_ext.h>
void Read_int (int*);    //function prototype with parameter as a pionter.
int main() 
{
    char choice;        //character variable declaration.
    do                  //do-while loop initiated.
    {
	int num = 0;         //integer variable initialization.
	printf("Enter a number: ");
	Read_int (&num);    //function called with &num as actual parameter.
	printf("The number is : %d\n", num); //output message displayed with the integer value.
	printf("Do you want to continue?(y/Y) : ");   
	__fpurge(stdin);    //fpurge() clears the buffers of the given stream.   
	scanf("%c", &choice);   
    }while ( choice == 'y' || choice == 'Y');  //do-while loop executes if the i/p is y or Y only.
}
void Read_int (int* num)   //function definition with num as pointer have address of integer.
{
    int sign1, sign2, sub;   //integer variable declaration.
    sign1 = sign2 = 0;       
    char negative, positive, character;  //character variable declaration.  
    __fpurge(stdin);  
    while ((character = getchar()) != '\n')   //loop runs till it encounters EOF.
    {
	if (character == '-')    //condition to check if the first charcter is a '-' sign.
	{
	    negative = '-';     //if its negative sign then we assign it to variable negative.  
	    sign1++;	        //incrementing the count to compare further.
	}
	else if (character == '+')  //condition to check if the first charcter is a '+' sign.
	{                          
	    positive = '+';    //if its positive sign then we assign it to variable positive.
	    sign2++;           //incrementing the count to compare further.
	}
	else if (sign1 < 2  && sign2 < 2)  //comparing with 2 because we only consider a single '-' or '+' sign at start.
	{     
	    if (character >= 48 && character <= 57 && negative == '-')  //to check the character is digit with '-' sign. 
	    {
		sub = (int)character - '0'; //casting the character as integer to perform operation.Here the ascii values   are subtracted so that the result is equivalent integer value.
		*num = *num * 10 - sub;    //this opeartion gives the integer value.
	    }
	    else if (character >= 48 && character <= 57 && positive == '+') //to check the character is digit with '+'sign.
	    {
		sub = (int)character - '0';  //casting character as integer to perform operation.
		*num = *num * 10 + sub;   //operation to return only the integer values.
	    }
	    else if ( character >= 48 && character <= 57)  //to check if the character is a digit.
	    {
		sub = (int)character - '0';    //here after casting the two ascii values are subtracted to get equivalent    integer.
		*num = *num * 10 + sub;   //this gives the integer equivalent after opeation.
	    }
	    else
		break;
	}
	else
	    break;
    }
    negative = '+';  //the negative variable is assigned with '+'. 
}
