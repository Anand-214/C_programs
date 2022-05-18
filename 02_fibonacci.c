/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 5/11/2021.
Description: Program to generate Fibonacci series.
Sample Execution: ./fibonacci.out
Enter the number:8
0 1 1 2 3 5 8
Do yot want to continue?(y/Y): y
Enter the number:15
0 1 1 2 3 5 8 13
Do yot want to continue?(y/Y): y
Enter the number:-21
0 1 -1 2 -3 5 -8 13 -21
Do yot want to continue?(y/Y): y
Enter the number:2000000
Error:The number is out of range.
Do yot want to continue?(y/Y):n
 */

#include<stdio.h>
int main()
{
    int j,range1=1,range2;   //Declaration of variables with integer data type.
    char choice;             //Declaration of variables with character data type.
    for (j=1;j<=20;j++)      //For loop to generate the valid input range from -2^20 to 2^20.
    {
	range1=(range1 * 2);   //Loop iterates 20 times to set positive range limit 2^20 and is stored in variable range1. 
	range2=(-1 * range1);  //Multipling the value in range1 with -1 provides the negative range limit as -2^20.
    }
    do     //Initiated the do while loop here.The body of do while loop will be executed again once the user choice is yes.  
    {
	int num,i,a=0,b=1,sum=0;      //Variables used inside the do while loop are declared here.
	printf("Enter the number: ");  //user prompt to enter the number till where the fibonacci series in to generate.
	scanf("%d", &num);             //scanf function to read the i/p number.
	if ( num <= range1 && num >= range2 )  //condition is true only when the i/p is within the calculated valid range.
	{
	    i=1;                      //initiated i=1 for the while loop. 
	    if (num >= 0)               //To generate fibo series for positive i/p values.
	    {
		while(a <= num)         //Condition to terminate the loop once the series is generated till the i/p value.
		{
		    printf("%d ", a); //"a" has been initiated as 0 and after every iteration the updated value is printed. 
		    sum=a + b;          //in the loop iteration the value of a and b will be added and stored in sum.
		    a=b;              //value of b is assigned to a after every iteration.
		    b=sum;            //value of sum is assigned to b after every iteration.
		    i++;              //increment i till the condition is true.
		}
		printf("\n");         //To print the further o/p's on a new line.
	    }
	    else if(num < 0)            //To generate fibo series for negative i/p values.
	    {
		printf("%d ", a);     //"a" has been initiated as 0 and after every iteration the updated value is printed. 
		while(sum <= (-num) && sum >= num) //To limit the series we check if the final value of series has not      exceeded the i/p value.As i/p is negative value -num considers positive value.
		{
		    printf("%d ",sum); //for negative series we print the value of the variable sum as o/p.
		    a=b;               //after every iteration the value of b is assigned to a.
		    b=sum;             //after every iteration the value of sum is assigned to b.
		    sum= a - b;           //the main operation to generate negative sereis is the subtraction of a&b.
		}
		printf("\n");         //To print the further o/p's on a new line.
	    }
	}
	else                         //when the i/p entered is beyond the valid range the else statement executes.
	{
	    printf("Error:The number is out of range.\n"); //error message displayed that the i/p is out of range.
	    printf("Please enter number within range -2^20 to 2^20.\n");  //user guided with the valid range for i/p.
	}
	printf("Do you want to continue?(y/Y):");    //after one series execution user asked to continue with new i/p.
	scanf(" %c", &choice);            //the choice of user which is a charcter datatype is read using scanf " %c".
    }while (choice == 'y' || choice == 'Y'); //the while condition is true only when the i/p is Y or y. thus if the i/p is  other than these then the program terminates.
    return 0;
}
