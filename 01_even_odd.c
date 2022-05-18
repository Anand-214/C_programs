/*Documentation:
Name:- Anand Arvind Kulkarni.
Date:- 31/10/2021
Description:- Program to check if number is odd or even.
Sample execution:- ./even_odd.c
i/p(1):-
Enter the number to check it is odd or even: -4
o/p(1):- 
-4 is negative even.
Do you want to continue?(y/Y): Y
Enter the number to check it is odd or even: 9
9 is positive odd.
Do you want to continue?(y/Y): Y
Enter the number to check it is odd or even: 2000000
Error:2000000 is out of range.
Do you want to continue?(y/Y): Y
Enter the number to check it is odd or even: 0
0 is neither negative or positive.
 */
#include<stdio.h> 
int main()    
{
    int i,num,result,range2,range1=1;   //integer variables to be used in various stages of program are declared here.
    char choice;                        //character variable declaration.
    for (i=0;i<20;i++)              //loop to generate the valid range of input from -2^20 to 2^20.
    {
	range1=(range1 * 2);     //this loop iterates 20 times and the final value of range1 is the +tive range limit. 
	range2=(-1 * range1);    //the positive limit obtained is multiplied with -1 to get the negative limit.
    }         //thus the above loop generates the values from -2^20 to 2^20 and further we validate i/p based on this.
    do        // do while loop initiated to start new execution after the user wish to continue.
    {
	printf("Enter the number to check if it is even or odd: "); //statement to prompt user for i/p.
	scanf("%d", &num);                                          //integer i/p from user.
	result=(num % 2);       
	//if result is 0 means the number is even else the number is odd.
	//if the number is greater than 0 means it's a positive number & if less than 0 means it's a negative number.
	if ( num <= range1 && num >= range2 )      //condition to allow execution only for i/p between the valid range.
	{                 
	    if (num > 0 && result == 0)          //condition for positive even number.
	    {
		printf("%d is positive even number.\n", num);
	    }
	    else if ( num < 0 && result == 0)    //condition for negative even number.
	    {
		printf("%d is negative even number.\n", num);
	    }
	    else if ( num < 0 && result != 0)   //condition for negative odd number.
	    {
		printf("%d is negative odd number.\n", num);
	    }
	    else if ( num > 0 && result != 0)   //condition for positive odd number.
	    {	
		printf("%d is positive odd number.\n", num);
	    }
	    else if ( num == 0 )                //condition if the number entered is zero.
	    {        
		printf("%d is neither negative nor positive number.\n", num);
	    }
	}
	else
	{
	    printf("ERROR:%d is out of range.\nPlease enter number between -2^20 to 2^20 only\n", num);         //error if   the i/p is out of valid range.
	}
	printf("Do you want to continue(y/Y): ");   //user is asked if he/she wantes to continue with a new number as i/p.
	scanf(" %c", &choice);      //read the character i/p i.e y or Y from user to continue. if any other i/p received    then the program is terminated.space before %c so that only single character i/p is considered.
    }
    while ( choice == 'y' || choice == 'Y');   //the condition is true and again the program is executed from line 28       (do-while loop) for new i/p only when the user continues by entering y/Y.
    return 0;
}
