/*Documentation:
Name: /Anand Arvind Kulkarni.
Date: 8/11/2021.
Description: Program to check if number is even or odd using bitwise operators.
Sample execution: ./even_odd.out
Enter the value of 'N':4
4 is positive even number.
Do you want to continue?(y/Y):Y
Enter the value of 'N':-99
-99 is negative odd number.
Do you want to continue?(y/Y):n
*/

#include<stdio.h>
int main()
{
    int num,range1,range2;    //variables with integer data type used in the program are declared here.
    char choice;              //variables with character data type used in the program are declared here.
    do                        //do while loop initiated.
    {
	printf("Enter the value of 'N':");  //user asked to enter the number.
	scanf("%d",&num);             //the number entered by the user is read using scanf function.
	range1=(1 << 20);             // 1<<20 gives the number 2^20 which is the positive limit of the range. user needs to enter number less than this range.
	range2=(-1*range1);           // -1*(2^20) is -2^20 which is the negative range limit.User needs to enter number     greater than this.
	if ( num > range2 && num < range1)  //Condition to check if the number is within the desired range or not.
	{ 
	    if (num & 1)               //if the o/p of (num&1) is 1 it means the last bit is 1.So The number is odd number.
	    {
		if ( num >> 31)        //if num >> 31 ==1 it means the MSB is 1 stating that the number is negative.
		{
		    printf("%d is negative odd number.\n",num);   // o/p if number is negative odd.
		}
		else                   //if the number is not negative it means its positive.
		{
		    printf("%d is positive odd number.\n",num); // o/p if number is positive off.
		}
	    }                      
	    else if ( (num &1) == 0)   //if result of (num&1) is 0 it means the last bit of number is zero.This tells the   number is even.
	    {
		if ((num >> 31) ==0)   // After (num>>31) if the number is zero it means the number is positive as MSB is   zero.
		{
		    printf("%d is positive even number.\n",num);  // o/p if the number is positive even.
		}
		else 
		{
		    printf("%d is negative even number.\n",num);   // o/p if the number is negative even number.
		}
	    }
	}
	else
	{
	    printf("Error: %d is out of range.\n",num);   //if the number is out of range.
	}
	printf("Do you want to continue?(y/Y):");   //User asked to continue or not.
	scanf(" %c",&choice);                 //The user input is read using scanf and " %c" to allow only single character consideration excluding the enter pressed.
    }while( choice=='y' || choice=='Y');        //If the user enters 'y/Y' as input then the loop executes and asks user to enter the number again else program terminates.
    return 0;
}


