/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 05/11/2021.
Description: Program to generate AP,GP and HP series.
Sample execution:
Enter the first number 'A':2
Enter the common difference/Ratio 'R':3
Enter the number of terms:'N':5
AP= 2 5 8 11 14
GP= 2 6 18 54 162
HP= 0.5 0.2 0.125 0.0909091 0.00714285
Do you want to continue?(y/Y):Y
Enter the first number 'A':-2
Enter the common difference/Ratio 'R':3
Enter the number of terms:'N':5
Error:Invalid Input(s).Please enter only positive values.
Enter the first number 'A':2000
Enter the common difference/Ratio 'R':3
Enter the number of terms:'N':5
Error:Inputs out of range.

 */
#include<stdio.h>
int main()
{
    int i,j,a,r,n;     //variables used in program with integer data type are declared.
    char choice;       //variables used in program with character data type are declared.
    do
    {
	printf("Enter the first number 'A':");  //user asked to enter first number of the series.
	scanf("%d",&a);                         //scanf function used to read the first number and further is stored in 'a'
	printf("Enter the common difference/Ratio 'R':");  //user asked to enter the ratio/common difference.
	scanf("%d",&r);                         //the ratio/common difference is read using scanf function and stored in 'r'
	printf("Enter the number of terms 'N':");  //user asked to enter the total numbers he want to print in series.
	scanf("%d",&n);                        //input of the total numbers is read and stored in 'n' variable.
	int AP=a,GP=a,range=1;      //AP,GP are the variables assigned with the value of 'a' and range1 variable for the    value of the range which is the limitation to the user inputs.(1 to 2^10) 
	float HP;     //The variable HP refered as harmonic progression is declared with float as the datatype.
	for(j=0;j<10;j++)    //loop to calculate the valid range for the user input. 
	{               
	    range=(range*2); //range=1 initially and multiplied in loop 10 times with 2.Here the value of range1 finally is 1024 and any inputs beyond this range will be treated as an i/p error. 
	}
	if (a>0 && r>0 && n>0)   //we allow only +tive integers as i/p thus this is a condition to check if all the three   i/p are greater than 0 or not.
	{
	    if (a<range && r<range && n<range)  //to check if all the 3 i/p's are inside the valid range or not.   
	    {
		//for arithmetic progression:
		printf("A.P=");     
		printf("%d ",a);   //The first digit for an AP is i/p 'a' thus it is printed. 
		for (i=1;i<n;i++)  //loop is executed till value of i<n as we need 'n' numbers in the series generated.
		{
		    AP=AP+r;      //for every iteration the value of AP is updated with the addition of AP and r.
		    printf("%d ",AP);  //the value of updated AP is printed after every iteration resulting an AP series. 
		}
		printf("\n");  //print the Geometric progression on a new line.
		//for geometric progression:
		GP=a;          //similar to AP the initial value of GP is assigned as 'a' which is the first term.
		printf("G.P=");
		printf("%d ",a);  //for GP he first term is the value of 'a' and it is printed directly.
		for (i=1;i<n;i++) //we need total numbeers in series a 'n' thus loop is executed till i<n.
		{
		    GP=GP*r;    //for every iteration the value of GP is updated with multiplication of GP and r.
		    printf("%d ",GP); //the update value of GP is printed after every iteration resulting a GP series.
		}
		printf("\n");   //print the harmonic progression on a new line.
		//for harmonic progression:
		AP=a;   //for HP we need to calculate the AP as well thus the first number (a) is stored in variable AP.
		printf("H.P=");  
		for(i=1;i<=n;i++)  //loop executed till the i<=n so that we get the exact numbers in the series.
		{
		    HP=(float)1/AP;   //(float) to carry out explicit conversion of data types from int to float as the     output of this operation are real numbers.The value of HP after every iteration is the reciprocal of value of AP.
		    printf("%g ",HP);  //Value of HP after every iteration is printed resulting in a HP series.
		    AP=(AP+r);  //The value of AP is updated by addition of AP with r.This value is refered in the above    operation where we find the HP by reciprocal of AP.
		}
		printf("\n");  //To print the further o/p on a new line.
	    }
	    else      //If the i/p is out of expected range then else condition is executed.
	    {
		printf("Error:Inputs out of range.\n");  //User informed that i/p is out of range.
	    }
	}
	else  //If any of the 3 i/p's is not a positive integer then this else condition is executed.
	{
	    printf("Error:Invalid Input(s).Please enter only positive values.\n"); //error message for user.
	}
	printf("Do you want to continue?(y/Y):"); //after every execution user is asked if they want to continue or not.
	scanf(" %c",&choice);   ///we have a space followed by %c as we want i/p (y/Y) to be considered only as a single    character without considering the enter pressed.It is a character datatype and hence is read using %c.
    }while(choice=='y' || choice=='Y');  //the do while loop is executed only when the i/p is either y or Y.
    return 0;
}
