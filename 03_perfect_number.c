/*Documentation.
Name:- Anand Arvind Kulkarni.
Dtae:- 31/10/2021
Description:- Program to check is the number is a perfect number or not.
Sample execution:- ./perfect_number.c
i/p(1):- 
Enter the number: 6
o/p(1):- 
Yes, 6 is a perfect number.
Do you want to continue?(y/Y):- y
Enter the number: 12
No,12 is not a perfect number.
Do you want to continue?(y/Y):- y
Enter the number: -10
Error:Please enter only positive integers.
Do you want to continue?(y/Y):- y
Enter the number: 200000
2000000 is out of range. PLease enter number within the range.
 */

#include<stdio.h>
int main()
{
    int j,num,i,sum=0,range1=1;   //integer variables used in the program are declared here few of them with initial values.
    char choice;                      //character variable declaration.
    for (j=1;j<20;j++)                //loop to generate a valid range limit here.After the loop completes range1 will have 2^20 assigned value.
    {
	range1=(range1*2);        
    }
    do        //do while loop initiated so that if the user wishes to continue he is asked to enter the   i/p number again.
    {
	printf("Enter the number:");      //user is prompt with this statement to enter the value.
	scanf("%d", &num);                //read number using scanf.
	for ( i=1 ; i<num ; i++ )         //we use for loop which iterates from 1 to one less than the number.(i<num) is used because we do not consider the number itself to check its perfect or not.
	{
	    if ( num % i == 0)           //if the current i value is a perfect divisior of the number then the remainder is true and also the condition is true to further enter the if statement.
		sum = ( sum + i );       //all the divisiors are added and the final result is stored in "sum".
	}
	if ( num <= range1)         //condition to check if the entered i/p is in a valid range or not.
	{
	    if ( num >0 )          //the program executes only when the i/p is a positive integer hence we used a condition here to validate.
	    {
		if ( sum == num )  //if the final value of "sum" is equal to the actual i/p number it means the number is a perfect number.So we validate this condition here.
		{	
		    printf("Yes,%d is a perfect number.\n", num);  //displayed o/p if the number is a perfect number.
		}
		else
		{
		    printf("No,%d is not a perfect number.\n", num);  //displayed o/p if the number isn't perfect number.
		}
	    }
	    else
	    {
		printf("Error:Invalid input.Enter only positive numbers.\n");   //Error message is the number entered is     negative.
	    }
	}
	else
	{
	    printf("%d out of range.\nPlease enter a valid number between 1 to 2^20\n",num );   //Error message if the       number is not in a valid range.
	}
	sum=(sum&&0);             //here we clear the sum value as we && it with 0 so that the previous sum value is not     considered again and sum=0 is considered.
	printf("Do you want to continue?(y/Y):" );    //user is asked if wants to continue with some other number as i/p.
	scanf(" %c", &choice);   //character is read by %c followe by a space so that only the single character is          considered as i/p.
    }
    while( choice=='y' || choice=='Y');    //if the user enters y/Y then only the do while condition is true and again the  program executes asking for new i/p entry.
    return 0;
}
