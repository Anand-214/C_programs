/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 23/11/2021.
Description: Program to print prime numbers using sieve of Eratosthenes method.
Sample execution: ./06_prime.c
Enter the value of 'n':20
Prime numbers upto 20 are: 2 3 5 7 11 13 17 19
Do you want to continue?(y/Y):y
Enter the value of 'n':-20
ERROR:Invalid input.valid i/p is 1 < number < 2^20
Do you want to continue?(y/Y):y
Enter the value of 'n':2000000
ERROR:Number out of range.Valid range is 1 < number < 2^20.
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
int main()
{
    int num, n, i, j, sqrt, range = 1;  //variables with integer data type are declared here.
    char choice;                        //variables with character data type are declared here.
    for (i = 0; i < 20; i++)      //loop to calculate the valid range of the i/p number.
    {
	range = range * 2;  //initial value of range=1,when multiplied 20 times with 2 gives 2^20 as the max allowd i/p.
    }
    do         //do-while loop initiated.If the user wish to continue the statements within the body of loop execute again.
    {
	int temp = 0;      //temperory variable with initial value 0 is declared here.
	printf("Enter the value of 'n':");   //user asked to enter the number to print prime numbers upto that number.
	scanf("%d", &num);                   //user input is an integer so %d format speicifier is used.
	if (num > 1)                       //condition true if the i/p is positive integer.
	{
	    if (num < range)               //condition is true if the number is within the valid range.
	    {
		//Finding the square root of the number.
		sqrt = num / 2;            //to reduce the iterations we assigned sqrt = num/2.
		while (sqrt != temp)     //the condition is true until sqrt is not equal to temp value.
		{
		    temp = sqrt;           //after every iteration temp is assigned as value of sqrt. 
		    sqrt = (num / temp + temp) / 2;  //after this expression is solved for the last time we get sqrt ==   temp and that value of sqrt is the square root of the number.
		}
		int arr[num];             //array is declared with the i/p number as the size of the array.
		for (i = 0; i < num; i++) //loop to create array of total elements = i/p number. 
		{
		    arr[i] = 1;            //the name of array is arr[i] and each element is assigned value 1.
		}
		for (i = 2; i <= sqrt; i++) //outer loop run till the sqrt of the i/p number.This reduce the iterations.
		{
		    if (arr[i] == 1)    //condition true only for the elements which are 1.
		    {
			for (j = i * i; j < num; j = j + i)   //inner loop access all the multiples of "j" which are      composite number upto i/p number and make them as 0.For the next iteration they are not considered and only non-zero numbers are considered.
			    arr[j] = 0;   //striking the accessed elements by making them 0.   
		    }
		}
		printf("Prime numbers upto %d are: ", num); //printing the  prime numbers.
		for (i = 2; i < num; i++)   //loop runs from 2 till the number entered.
		{
		    if (arr[i] == 1)   //condition true only for the elements which are still 1.
			printf("%d ", i);  //we are not printing the actual prime number but the index value of the array   whose  elements are 1.At the end only those index values are 1 which are prime.
		}
		printf("\n");
	    }
	    else    //else condition executes if the number is 0,negative or out of the desired range value.
	    {
		printf("ERROR:Number out of range.Valid range is 1 < 'n' < 2^20.\n"); //error message if the i/p is above the valid range.
	    }
	}
	else
	{
	    printf("ERROR:Invalid input.valid i/p is 1 < 'n' < 2^20.\n");  //error message if the i/p is negative number.
	}
	printf("Do you want to continue?(y/Y):");  //user asked if they want to continue with other i/p number.
	scanf(" %c", &choice);    //the user i/p is a character so %c format specifier is used.
    }while(choice == 'y' || choice == 'Y'); //do-while loop executes when the i/p is either y or Y else terminate program.
    return 0;
}
