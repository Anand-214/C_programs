/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 08/11/2021.
Description: Program to print Hello in 'X' format.
Sample execution:
Enter the number of lines: 5
Hello    Hello
 Hello  Hello
  HelloHello
 Hello  Hello
Hello    Hello
Do you want to continue?(y/Y):Y
Enter the number of lines: 32
ERROR:The number is out of range.
*/

#include<stdio.h>
int main()
{
    int row,col,k,num,range=1;  //variables with integer datatype are declared here.
    char choice;                //variables with character datatypes are declared here.
    for (k=1;k<=5;k++)          //for loop to calculate the range of the values within the desired limits.
    {
	range=range*2;          //Positive inputs are only valid hence we calculate the positive range.
    }                           //loop iterates 5 times to calculate 2^5.(32)
    do                    //do while loop initiated.If the user agrees to continue the lines within the loop execute again.
    {
	printf("Enter the number of lines:");   //User asked to enter the number.
	scanf("%d",&num);                    //The i/p is an integer so %d is used to read the number.
	if (num>0)                          //Program executes only when the i/p is a positive integer.
	{
	    if (num<range)                  //Program executes only when the +tive integer is withing the range limits.
	    {
		for (row=1;row<=num;row++)  //outer loop gives the rows.So the loop is iterated till the user i/p value.
		{
		    for (col=1;col<=num;col++) //inner loop gives columns so its iterated till the user i/p value.
		    {

			if ( row==col || ((row+col)==(num+1)) ) //condition allows the access of diagonal elements only. 
			{
			    printf (" Hello");   //The above diagonal elements are printed with word Hello.
			}
			else if ( (num%2) != 0 && (row==(num+1)/2) && (col==(row+1))) //if the user i/p is an odd value thenwe access the centre of the pattern of the pattern and the immediate next column in the same row. 
			{
			    printf ("Hello");  //The centre and the next column is printed with hello word.
			}    
			else
			{
			    printf(" ");  //All the remaining positions are printed with spaces.With the combination of     Hello word and the spaces desired pattern is produced.
		    }
		    }
		    printf("\n");  //After every row iteration completes we print the next iteration on new line.
		}
	    }
	    else
		printf("ERROR:Number out of range.\n");  // error if the number is less than 1 and greater than 31.
	}
	else
	    printf("ERROR: Please enter only positive values.\n");	//error if the the i/p is 0 or negative integer.
	printf("Do you want to continue?(y/Y):");  //User asked to continue with new i/p or not.
	scanf(" %c",&choice);      //The 2nd i/p by user is a character thus we use " %c" to access the character datatype.
    }while(choice=='y' || choice=='Y'); //The do while loop executes only when the i/p is either y or Y.
    return 0;
}

