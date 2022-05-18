/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 22/11/2021.
Description: Program to implement circular right and left shift.
Sample execution: ./circular_shift.out
Enter the number:-12
Enter number of bits:3
Possible operations.
1.Circular right shift.
2.Circular left shift.
Enter you choice:2
Before circular left shifting by 3 bits,
The binary form of number:11111111111111111111111111110100
After circular left shifting by 3 bits,
The binary form of number:11111111111111111111111110100111
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
int circular_right_shift(int num, int n)   //function to get the return value after the bits are circular right shifted. 
{  //
    return ((num >> n) & ~(((1 << n) - 1) << (31 - n + 1))) | (num << (31 - n + 1)); //this equation gives us the right     shifted value in decimal form but we are not printing it and using this value to print the binary equivalent.
}
int circular_left_shift(unsigned int num,int n)  //function to get the return value after circular left shifting. 
{          //here we used unsigned int so that even if the user i/p is negative value we will considered its positive       equivalent and then will be circular left shifted.
    return num << n | num >> (32 - n); //this equation gives the circular left shift value in decimal which is used to print the binary equivalent.
}
int binary_of_number(int num)   //function to print the number in its binary form.
{
    for (int i=31; i>=0; i--)
	num>>i&1 ? printf("1") : printf("0");  //if num>>i&1 return "1" then we print 1 or else we print "0" resulting in a binary form after 32 iterations.
}
int main()   //main function declaration.
{
    int num, n, option;   //variables with integer data type are declared here.
    char choice;          //variables with character data type are declared here.
    do        //do-while loop initiated to enable user to enter next i/p after 1st execution.
    {
	printf("Enter the number:");     //user asked to enter the number.
	scanf("%d", &num);               //%d used to read integer value given as input.
	printf("Enter number of bits:"); //user asked to enter the number of bits to be shifted. 
	scanf("%d", &n);                 //%d used to read integer value given as input. 
	printf("Possible operations.\n1.Circular right shift.\n2.Circular left shift.\n");  //menu displayed.
	printf("Enter you choice:");    //user asked to enter the option form the menu displayed above.
	scanf("%d", &option);           //it is an integer value hence %d used to read the input.
	getchar();      //as the input is a single character getchar used to fetch the extra character from stdin buffer.  
	switch (option) //based on the option selected the switch case for that particular i/p is executed.
	{
	    case 1:     //case 1 executes when the user wants to perfrom the circular right shift.
		printf("Before circular right shifting by %d,\n", n); //binary form of the user i/p number before shifting.
		printf("The binary form of number:");     
		binary_of_number (num);   //binary_of_number function called to print the binary form of number entered.
		printf("\n");            
		printf("After circular right shifting by %d,\n", n);
		int res1 = circular_right_shift(num,n); //function called and the return value is stored in res2 variable.
		printf("The binary form of number:");  //line displayed before the binary form is printed.
		binary_of_number (res1);  //function called to print binary of return value stored in "res2". 
		printf("\n");
		break;
	    case 2:    //case 2 is executed when the user wants to perfrom the circular left shift.
		printf("Before circular left shifting by %d bits,\n", n); //binary form of user i/p number.
		printf("The binary form of number:");  
		binary_of_number (num);  //binary_of_number function is called to get binary of the number before shifting.
		printf("\n");
		printf("After circular left shifting by %d bits,\n", n); 
		int res2 = circular_left_shift(num,n); //function called and the return value is stored in res2 variable.
		printf("The binary form of number:");
		binary_of_number (res2); //function called to print the binary of the number stored in "res2" variable.
		printf("\n");
		break;
	    default :  //default case executed when the user input is not 1 or 2.
		printf("ERROR:Please enter the option from the displayed menu.\n");
		break;
	}
	printf("Do you want to continue?(y/Y):");  //user asked if they want to continue by entering some other number.
	scanf("%c", &choice);   //the user i/p here is a character hence %c format specifier is used.
	getchar();   //getchar used to fetch the extra character from the stdin buffer.
    }while ( choice == 'y' || choice == 'Y');  //do-while loop executes if the user i/p is y or Y. else program terminates.
}
