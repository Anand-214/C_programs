/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 28/11/2021.
Description: To find factorial using recursive function. 
Sample Execution: ./factorial.c
Enter the number:7
The factorial is: 5040
Do you want to continue?(y/Y):y
Enter the number:5
The factorial is: 120
Do you want to continue?(y/Y):y
Enter the number:-1
Error:Invalid Input.
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
int main()
{ 
    static int num, res=1,flag = 1;  //Declaration of static variables with initial values.
    if ( flag )     //Condition will be true only for first time so that user isnt asked to enter number for each time  the main function is called.
    { 
	printf("Enter the number:");  //user asked to enter the number as input.
	scanf("%d", &num);    //the i/p is an integer thus %d is used as format sepcifier.
	flag = 0;  //we clear the flaf so that again when the main function is called the user isn't asked to enter i/p.
    }
    if ( num < 0 )   //condition to check if the i/p is positive or negative.
	printf("Error:Invalid Input.\n");  //negative integer is an invalid input
    else if ( num > 0 )  //condition true if number is positive.
    {
	res = res * num; //this operation is performed for each time when the main function is called resulting in the  multiplication if the entered number till the number is not decremented to 0.
	num--;   //after every operation the number is decremented.
	return main();  //main function is called again inside main function thus its a recursive function. 
    }
    else     //once the recursive condition is false this condition executes.
	printf("The factorial is: %d\n", res);  //The factorial is printed. 
    num = 0,res = 1,flag = 1;  //once the factorial for 1st i/p is printed before asking for next i/p we again manually reassign the initial values as the same they where during first initialization.This helps in executing the statements again if the user wished to continue with next number as i/p.
    char choice;   //variable wiht charcter datatype are declared here.
    printf("Do you want to continue?(y/Y):");  //user asked if they want to continue with some other i/p number.
    scanf(" %c",&choice);  //its a character hence %c format specifier used to read the input.
    if ( choice == 'y' || choice == 'Y')  //the main function is called again only when the user i/p is 'y' or 'Y'.
	return main();  //calling the main function again to executed the statement for new input.As till now the flag  is again set to 1 the user will again be asked to enter the number.
}
