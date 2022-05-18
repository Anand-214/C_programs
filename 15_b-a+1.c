/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/11/2021.
Description: Program to put the (b-a+1) lbs's of n into i[b:a]
Sample Execution: ./b-a+1.out 
Enter the value of 'n':	15
Enter the value of 'I':	198
Enter the value of 'a':	4
Enter the value of 'b':	6
The binary form of 'n':	00000000000000000000000000001111
The binary form of 'I':	00000000000000000000000011000110
The updated form of 'I': 246
The binary form of updated 'I': 00000000000000000000000011110110
Do you want to continue?(y/Y):n 
 */

#include<stdio.h>
int replace_bits (int num, int bits, int b, int value);   //implicit declaration of the function.
int binary_for_loop ( int number, int i);    //implicit declaration of the function.
int main()     //main function.
{
    int number, value, updated, a, b, i;   //variables with integer data type are declared here.
    char choice;                           //variables with character data type are declared here.
    do           //do-while loop initiated.If user continues after first execution, statements after this will be executed.
    {
	printf("Enter the value of 'n':\t");  //user asked to enter the number.
	scanf("%d", &number);                 //the i/p is an integer type so %d to read it.
	printf("Enter the value of 'I':\t");  //user asked to enter the number which will be updated after execution.
	scanf("%d", &value);                  //it is also a integer type so %d format specifier to read it.
	printf("Enter the value of 'a':\t");  //user input which is used to calculate the number of bits.
	scanf("%d", &a);                      //i/p read using %d format speicifer.
	if ( 0 < a && a <= 31)               //checking if 'a' is within the desired limits or not.(0<a<=31)
	{
	    printf("Enter the value of 'b':\t"); //if 'a' is within limits user is asked to enter value of 'b'.
	    scanf("%d", &b);                    //read 'b' value using %d.
	    if (  a < b && b <= 31 )          //checking if 'b' is within the desired limits or not.(a<b<=31)
	    {                          
		printf("The binary form of 'n':\t"); //binary form of 'n' is printed.
		binary_for_loop(number,i);  //Calling the function binary_for_loop to print binary form of input 'n'.
		printf("\n");            
		printf("The binary form of 'I':\t"); //binary form of 'I' is printed.
		binary_for_loop(value,i);   //Calling the function binary_for_loop to print binary form of input 'I'.
		printf("\n");
		updated = replace_bits( number, (b-a+1), b, value);       //calling function which returns the value of the desired replacement of the bits.The formal argument in function as 'bits' is calculated by using actual argument (b-a+1). 	
		printf("The updated form of 'I': %d\n", updated);  //printing the updated form of 'I' in decimal form.
		printf("The binary form of updated 'I': ");  //to print the updated value in binary form.
		binary_for_loop(updated,i);       //function called to excute the loop and print the binary form.
		printf("\n");                     //new line.
	    }
	    else    //condition executes if 'b' is not within the desired limits.
	    {
		printf("ERROR: please enter value of 'b' such that a < b <= 31.\n");  //error message. 
	    }
	}
	else       //condition executes if 'a' is not within the desired limits.
	{
	    printf("ERROR: please enter value of 'a' such that 0 < a <= 31.\n");    //error message.
	}
	printf("Do you want to continue?(y/Y):");  //user asked if they want to continue with new i/p values.
	scanf(" %c", &choice);    //user i/p is character hence using %c format specifier to read it.
    }while (choice == 'y' || choice == 'Y');  //do-while loop executes if the i/p is either 'y' or 'Y' else end program.
    return 0;
}
int replace_bits ( int num, int bits, int b, int value)  //function declaration for the replacement of the bits as desired.
{       //the return value results in the replacement of the bits of the number.
    return value & ~(((1<<(bits))-1) << (b - (bits) + 1)) | (num & (( 1<< (bits)) -1 )) << (b - (bits) + 1);
}  
int binary_for_loop ( int number, int i)   //function declaration to print the binary form of the required number.
{    
    for (i=31; i>=0 ; i--)     //the for loop iterates 32 times resulting the binary form by printing the 1's and 0's. 
	number >> i & 1 ? printf("1") : printf("0");  //if "number >> i &1" is true print 1 else print 0.
}
