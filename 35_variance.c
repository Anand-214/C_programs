/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 12/12/2021
Description: Variance calculation with static & dynamic arrays.
Sample Execution: ./variance.out
Enter the number of elements:10
1.Static allocation.
2.Dynamic allocation.
Enter you choice:2
Enter 10 elements:9 12 15 18 20 22 23 24 26 31
Sum of elements: 200
mean: 20
Sum of D^2 :400
variance: 40
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
#include<stdlib.h>
float variance (int, int*);   //function prototype.
int main()
{
    char choice;       
    do                   //do-while loop innitiated.
    { 
	int size, option;     // variable declaration.
	float var;
	printf("Enter the number of elements:");   //display message.
	scanf("%d", &size);    //user input.
	printf("1.Static allocation.\n2.Dynamic allocation.\nEnter you choice:");  //display menu.
	scanf("%d", &option);  //user input.
	switch (option)       //switch case initiated.
	{
	    case 1: 
		{     //user input is static memory allocation.
		    int arr[size];    //array declaration.
		    printf("Enter %d elements:", size);   //user asked to input all sizebers.
		    float var = variance(size, arr);       //function call and return value stored in variable.
		    printf("variance: %g\n", var);       //o/p printed.
		}
		break;
	    case 2:
		{    //user input is dynamic memory allocation.
		    int* arr = malloc (sizeof(int) * size);   //malloc function is access memory from heap segment.
		    printf("Enter %d elements:", size);  
		    float var = variance(size, arr);       //function call and return value stored in variable.
		    printf("variance: %g\n", var);       //output.
		}
		break;
	    default:
		printf("ERROR:Please select valid option from the menu.");  //error if no valid option entered.
		break;
	}
	printf("Do you want to continue?(y/Y):");   
	scanf(" %c", &choice);    
    }while (choice == 'y' || choice == 'Y');  //do-while loop executes if user i/p is y or Y only.
    return 0;
}
float variance(int size, int* arr)     //function declaration.Here we recieve the base address of array so using pointer.
{
    int i, j, sum = 0, sum1 = 0;
    float mean, var;
    for ( i = 0; i < size; i++)   //loop till the size of array.
    {
	scanf("%d", &arr[i]);  //getting each number from the user.
	sum = sum + arr[i];         //each entered element is added to sum to get the final addition.
    }
    printf("Sum of elements: %d\n", sum);   
    mean = sum / size;           //calculating mean.
    printf("mean: %g\n", mean);  
    for (i = 0; i< size; i++)     //loop till size of array.
    {
	arr[i] = arr[i] - mean;    //here the updated value of arr[i] is the D.
	arr[i] = arr[i] * arr[i];  //to find square of each element D.
	sum1 = sum1 + arr[i];           //sum1 generated the total of D^2 which when divided by size gives variance.
    }
    printf("Sum of D^2 :%d\n", sum1);   //D^2.
    var = (float)sum1 / size;    //to calculate variance.
    return var;   //return value.
}
