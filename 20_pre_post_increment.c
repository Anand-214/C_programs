/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 28/11/2021.
Description: Function to perform pre and post increment.
Sample execution: ./pre_post.c
Enter the value of 'N':5
Enter the operation.
1.Pre-increment.
2.Post-increment.
Enter the choice:2
Return = 5,Num = 6.
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
int pre_increment (int*);     //Pre increment function prototype.
int post_increment (int*);    //Post increment function prototype.
int main()          //Main function declaration.
{
    char choice;    //Variables with character data type are declared.
    do              //Do-while loop initiated.
    {
	int num,option;    //Variables with integer data type are declared.
	printf("Enter the value of 'N':");  //User asked to enter the number.
	scanf("%d",&num);                    //The i/p is integer hence read using %d format specifier.
	printf("Enter the operation.\n1.Pre-increment.\n2.Post-increment.\n"); //Menu displayed to select the operation.
	printf("Enter the choice:");   //User asked to enter the choice from the displayed menu.
	scanf("%d",&option);           //The user input is an integer value hence read using %d format specifier.
	switch (option)                //Switch case initiated to execute the operation selected.
	{
	    case 1:        //Is user wish to perfrom pre-increment then case 1 is executed.
		{
		    int res = pre_increment(&num);  //Pre-increment function called with &num as the actual parameter.
		    printf("Return = %d,Num = %d.\n",res,num);  //Print the result.
		}
		break;
	    case 2:        //If user wish to perfrom pre-increment then case 2 is executed.
		{        
		    int res = post_increment(&num); //Post-increment function called with &num as the actual parameter.
		    printf("Return = %d,Num = %d.\n",res,num);  //Print the result.
		}
		break;
	    default:
		printf("ERROR: Invalid input.\n");   //Default statement if non of the option is selected.
	}
	printf("Do you want to continue?(y/Y):");   //User asked if they want to continue with next i/p number. 
	scanf(" %c",&choice);          //The i/p is character hence read usinf %c format specifier.
    }while( choice == 'y' | choice == 'Y');  //The do-while condition is true only if the i/p is 'y' or 'Y'.
}
int pre_increment (int* num)  //Pre-increment function definition with formal parameter as num pointer containing address   of an integer.
{
    int mask = 1;           //Initially mask value assigned as 1.
    while ( *num & mask )   //We run the loop till value of num & mask is not zero.
    {
	*num = *num ^ mask; //Using de referencing we ex-or the value of num with mask and the result is stored in *num.
	mask = mask << 1;   //Mask value updated with mask<<1 for next iteration.
    }
    *num  = *num ^ mask;    //The number is updated with value of num ex=or with new mask value.
    return *num;       //Function returns the updated num value which is incremented by 1.
}
int post_increment (int* num) //Post-increment function definition with formal parameter as num pointer containing address  of an integer.
{
    int incremented = *num;   //we are directly assigning the i/p to the variable incremented.
    int mask = 1;     //Initially we assign the mask = 1;
    while ( *num & mask )  //We run the loop till value of num & mask is not zero.
    {
	*num = *num ^ mask;  //Using de referencing we ex-or the value of num with mask and the result is stored in *num.
	mask = mask << 1;    //Mask value updated with mask<<1 for next iteration.
    }
    *num  = *num ^ mask;     //The number is updated with value of num ex-=or with new mask value.
    return incremented;  //function returns the original as well as the incremented value.
}
