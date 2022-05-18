/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 25/11/2021.
Description: Program to swap two variables using pass by reference.
Sample Execution: ./swap.out
Enter a number num1:10
Enter a number num2:20
After swapping,
num1 =20, num2 = 10
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
//function prototype with both arguments as pointer to a variable whose data type are integer.
void swap_function ( int*, int*);
int main()                        //main function.
{
    int num1, num2;              //variables with integer data type are declared here.
    char choice;                //variable with character data type is declared here.
    do                  //do-while loop initiated.
    {
	printf("Enter a number num1:"); //user asked to enter the first number.
	scanf("%d", &num1);             //read first number.
	printf("Enter a number num2:"); //user asked to enter the second number.
	scanf("%d", &num2);             //read second number. 
	swap_function(&num1, &num2);    //swap_function is called using call by reference.Passing address to the pointers.
	printf("After swapping,\n");    //display message.
	printf("num1 = %d, num2 = %d\n",num1, num2); //the swapped values received from the function are printed.
	printf("Do you want to continue?(y/Y):"); //user asked if they want to continue with other numbers as i/p.
	scanf(" %c", &choice);    //user i/p is a character so %c used to read the i/p.
    }while(choice == 'y' | choice == 'Y'); //do-while loop executes is i/p is either 'y' or 'Y'.
}

void swap_function (int* num1, int* num2) //function declaration with the names of variables in arguments as pointer to     variable with integer data-type. pointer used to store the address of the variables.
{
    *num1 = *num1 ^ *num2;  //Refer point 1. (dereferencing)
    *num2 = *num1 ^ *num2;  //refer point 2. (dereferencing)
    *num1 = *num1 ^ *num2;  //refer point 3. (dereferencing)
}
//1.The value of variable at address of num1 is updated by ex-or operation between values at address of num1 and num2  respectively.This result is further used to swap the two numbers.
//2.The value of variable at address of num2 is changed by ex-or operation of the updated value at address of num1 and value at address of num2.This value is the 1st number entered by the user.After swapping it is stored in address of num2. 
//3.The value at address of num1 is again updated by ex-or operation of the value at address of num1 and the updated   value at address of num2.
