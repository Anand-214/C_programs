/*Documentation:
Name: Anand Arvind Kulkarni
Date: 30/11/2021
Description: Program to implement the solution for tower of hanoi.
Sample Execution: ./TOH.out
Enter the no. of disks:3
Enter the no. of disks:3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Do you want to continue?(y/Y):n
 */

#include<stdio.h>

void TOH ( char source, char middle, char dest, int num)   //function definition with the formal paramaters.
{
    if (num == 1)   //condition to check one disk is present.   
    {
	printf("Move disk %d from %c to %c\n", num, source, dest);  //print when num=1.
    }
    else if ( num > 0)    //if no. of disks are greater than 1.
    { 
	TOH (source, dest, middle, num-1);     //recursive function call.
	printf("Move disk %d from %c to %c\n",num, source, dest);  
	TOH (middle, source, dest, num-1);  //recursive function call.
    }
}
int main()
{
    char choice;
    do          //do-while loop initiated.
    {
	int num;    //variable declaration.
	printf("Enter the no. of disks:"); //user input.
	scanf("%d", &num);   //reading the user i/p.
	if (num > 0)         //to execute function only when user i/p is +tive integer.
	{
	    TOH ('A', 'B', 'C', num);  //function call with actual parameters mentioned.
	}
	else
	    printf("Error: Enter integers value greater than 0.\n"); //error if invalid input.
	printf("Do you want to continue?(y/Y):");
	scanf(" %c", &choice); //reading user i/p to check weither to continue or not.
    }while (choice == 'y' || choice == 'Y'); 
}
