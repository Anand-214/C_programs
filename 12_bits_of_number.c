/*Documentation:
Name: Anand Arvind Kulkarni
Date: 13/11/2021.
Description: Program to print binary equivalent of the number and its compliment.
Sample execution: ./2s_comp.out
Enter the number: 12
+12-->00000000000000000000000000001100
-12-->11111111111111111111111111110100
Do you want to continue(y/Y):n
 */

#include<stdio.h>
int main()
{
    int i,num,comp;   //variables with integer datatype are declared here.
    char choice;      //variables with character datatype are declared here.
    do                //do-while loop initiated.
    {
	printf("Enter the number:");  //user asked to enter the number whose binary form is to be displayed.
	scanf("%d",&num);    //Read the integer input using %d format specifier.
	if ( num > 0)      //we want to print the sign of number based on input hence we check if its greater than 0 or not.
	    printf("+%d-->",num);     //printing the i/p number with '+'sign followed by which its binary equivalent will be   displayed. 
	else
	    printf("%d-->",num);  //if the number is negative its sign will already mentioned in input itself.
	for (i=31;i>=0;i--)           //for loop initiated to check each bit of the number.
	{   //below the number is right shifted for each iteration also bitwise and with 1 to check the bit is o or 1.
	    num>>i&1 ? printf("1") : printf("0"); //if the bit is 1 it prints 1 else prints 0.
	}
	printf("\n");        
	comp=(~num+1);     //we calculated 2's compliment of the user input.
	if ( comp < 0)     //if i/p is +tive the comp will be negative and the sign will be printed along with compliment.
	    printf("%d-->",comp); //The 2's compliment is printed followed by which its binary equivalent is printed.
	else
	    printf("+%d-->",comp);  //if the 2's compliment is positive we need to print the '+' sign as well.
	for (i=31;i>=0;i--)  //for loop initiated to check each bit of the negative number. 
	{  //below the number is right shifted for each iteration also bitwise and with 1 to check the bit is 0 or 1.
	    comp>>i&1 ? printf("1") : printf("0"); //f the o/p of right shift is 1 print "1" else print 0. 
	}
	printf("\n");       //New line 
	printf("Do you want to continue?(y/Y):");  //user asked if wants to continue with other i/p number.
	scanf(" %c",&choice);  // the user input is a character datatype hence use of %c as format specifier.
    }while(choice=='y' || choice=='Y'); //the do while loop condition is true if i/p is either y or Y.Else terminate.
    return 0;
}
