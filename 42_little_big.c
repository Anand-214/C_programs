/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 28/11/2021.
Description:Program to check your processor endianess.
Sample Execution:./endianess.out
Enter the number:-1
Little Endian System
Do you want to continue?(y/Y):y
Enter the number:124
Little Endian System
Do you want to continue?(y/Y):n
 */
#include<stdio.h>
int endianess(int*);    //function prototype.
int main()              //main function declaration.
{                
    char choice;        //variables with character datatype are declared here.
    do                  //do-while loop initiated.
    {                   
	int res, num;   //variables with integer datatype are declared here.
	printf("Enter the number:");   //user asked to enter the number to check how it is stored in system.
	scanf("%d",&num);              //user i/p is an integer so %d format speicifier used.
	res = endianess (&num);        //function endianess called with &num as the actual parameter.
	if (res == 1)        //If the function returns 1 it means the processor endianess is little endian.
	    printf("Little Endian System\n"); //display output.
	else                //if the function returns 0 means the processor endianess is big endian.
	    printf("Big Endian System.\n");  //display output.
	printf("Do you want to continue?(y/Y):");  //user asked if they want to continue with new i/p number.
	scanf(" %c", &choice);   //user i/p is an character so use of %c as format specifier.
    }while(choice == 'y' || choice == 'Y');  //do-while condition is true if the user i/p is either y or Y.
}
int endianess(int *ptr)   //function definition with ptr as pointer storing address of an integer.
{
    char* ptr1 = (char*) ptr;  //new pointer declaration which is assigned to the ptr.
    *ptr1 = (char)*ptr & ((1<<8)-1);   //value of ptr1 is assigned to last 8 bits (1 byte) of value of ptr.
    if ( *ptr1 == (char)*ptr)    //comparing the value of ptr1 with that of ptr to check how the i/p number was stored.
	return 1;    //if condition executes means the function returns 1.
    else
	return 0;    //else condition executes means the function returns 0.
}
