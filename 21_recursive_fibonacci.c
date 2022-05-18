/*Documentation:
Name:Anand Arvind Kulkarni.
Date:26/11/2021.
Description:Program to print fibonacci series using recursive function.
Sample description:./fibo_recursive.c
Enter the value of 'N':10
Fibonacci series: 0 1 1 2 3 5 8
Do you want to continue(y/Y):y
Enter the value of 'N':-10
Fibonacci series: 0 1 -1 2 -3 5 -8
Do you want to continue(y/Y):n
 */

#include<stdio.h>
void fibonacci (int, int, int, int, int);   //function prototype.
int main()                                  //main function.
{
    int num;        //variable with integere datatype are declared here.
    char choice;    //variable with character datatype are declared here.
    do              //do-while loop initiated.
    {          
	printf("Enter the value of 'N':");  //user asked to enter the number.
	scanf("%d", &num);                  //read the i/p using %d format specifier as it is integer input.
	fibonacci(num, 0, 1, 0, 1);        //function called here with the actual parameters inside bracket.
	printf("\n"); 
	printf("Do you want to continue(y/Y):");  //user asked if they want to continue with new i/p number.
	scanf(" %c", &choice);         //the i/p is a character hence reading it using %c format specifier.
    }while( choice == 'y' | choice == 'Y');  //the do-while condition is true only when the i/p is either y or Y.
}
void fibonacci ( int num, int a, int b, int result, int flag) //function defination with the formal parameters.
{
    if ( num == 0 )            //condition to check if the i/p is 0.
	printf("Fibonacci series: %d", a);  //if the i/p is zero we print the value of 'a' which is 0 directly.
    //Fibonacci series is generated if the i/p is positive integer.   
    else if ( num > 0 )     //condition to check if the number is greater than zero i.e. positive integer.
    {
	if ( flag == 1 )   //if the value of flag is 1 then only the further statements are executed.
	{
	    printf("Fibonacci series: ");  //message before printing the series.
	    printf("%d %d ", a, b);  //the starting numbers are 0 and 1 always so they are printed directly.
	    result = a + b;    //sum operation.
	    printf("%d ", result);  //printing the result here the third term is generated.
	    flag = 0;     //we manually set the flag to 0. This flag is set to 1 again as we pass flag in parameters.
	}
	a = b;     //we assign the value of b using it in next operation.
	b = result;   //we assign the value of result to b using it in next operation.
	result = a + b;  //result opeartion.
	if (result < num)  //condition to continue the series only till the i/p number.
	{
	    printf("%d ", result);   //printing the result.
	    fibonacci(num, a, b, result, flag);  //recursive function.Here the function is called again so that till the       conditions are true it keeps on executing resulting in a fibonacci series at the end. 
	}}
    //Here the fibonacci series is generated if the i/p is a negative integer.    
    else if ( num < 0 )   //to check if the number if less than zero i.e. negative number.
    {
	if ( flag == 1 )  //if the value of flag is 1 then only the further statements are executed.
	{
	    printf("Fibonacci series: "); //message before printing the series.
	    printf("%d %d ", a, b);       //the starting numbers are 0 and 1 always so they are printed directly.
	    result = a - b;                  //subtraction of first term and second term as it is negative series.
	    printf("%d ", result);     //the result is printed as the third term and then the series continues.   
	    flag = 0;     //we manually clear the flag as it is set again when we pass the value in parameter.
	}
	a = b;          //value of b is assigned to a.
	b = result;     //value of subtraction result is assigned to b.
	result = a - b; //as its a negative series we perform subtraction of first and secod term.
	if (result >= num && result <= -num)  //condition to limit the series till the value of i/p number.
	{
	    printf("%d ", result);         //each time the operation completes the next generated number is printed which atthe end results in complete series till the value is 1 less than num or num but doesnt exceed the num value.
	    fibonacci(num, a, b, result, flag); //recursive function till the condition is true the function is called again
	}}}
