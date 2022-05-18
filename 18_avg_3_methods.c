/*Documentation:
Name: Anand Arvind Kulkarni
Date: 23/12/2021
Desription: Program for calculating average by taking input from user in 3 different ways.
Sample Execution: ./18_avg.c
./a.out 1 2 34 5
Enter the choice:
1.Environmental variable
2.Command line input
3.Scanning from keyboard
Enter you choice:3
Enter total number of integers:3
Enter 3 elements:13 31 42
The average is: 28.6667
Do you want to continue?(y/Y):y
Enter the choice:
1.Environmental variable
2.Command line input
3.Scanning from keyboard
Enter you choice:2
Average: 10.5
Do you want to continue?(y/Y):n
 */


#include<stdio.h>
#include<stdlib.h>

//Declare the environmental function
float environ_avg();
int my_atoi(const char *str);
char *my_strtok(char* , char*);   //function definition.Here the function returns address so return type is pointer.

int main(int argc, char *argv[], char *env[])    
{
    char choice;
    do                       
    {
	//Declare the variables
	int i, j, size, option, total;
	int sum = 0;
	int count = 0;
	float avg;

	//Prompt + read the choice
	printf("Enter the choice:\n1.Environmental variable\n2.Command line input\n3.Scanning from keyboard\nEnter you choice:");
	scanf("%d", &option);

	switch(option)
	{
	    case 1://For the avg of the environmental variable.
		{
		    int count = 0;
		    char* arr = getenv("arr");    //function to access the environmental variable arr.
		    char ptr[2] = " ";            
		    char* token;
		    token = my_strtok(arr, ptr);   //function call to tokenize the string.
		    while (token != NULL)        
		    {
			count++;
			int num = my_atoi(token);  
			sum += num;
			token = my_strtok(arr,ptr);
		    }
		    avg = (float) sum / count;              //average operation.
		    printf("The average is: %g\n" ,avg); 
		    break;
		}
	    case 2://Calculating average when inputs are given via command line
		if (argc > 1)	//If the argument count is greater than 1 
		{
		    for (i = 1; i < argc; i++)
		    {
			if (my_atoi(argv[i]))
			{
			    sum += my_atoi(argv[i]); //Converting the ASCII value in the arguments to integer and adding the values
			}
			else
			{
			    printf("Enter only numbers in command line\n");
			    return 0;
			}
		    }
		    avg = (float)sum / (argc - 1);
		    //Displaying the result
		    printf("Average: %g\n", avg);
		}
		else
		{
		    printf("No input given in command line\n");
		    return 0;
		}
		break;
	    case 3: //scanning numbers from keyboard.
		{
		    //sum = 0;
		    printf("Enter total number of integers:");
		    scanf("%d", &total);
		    int num[total];
		    printf("Enter %d elements:", total);
		    for (i=0; i<total; i++)
		    {
			scanf("%d", &num[i]);
			sum = sum + num[i];
		    }
		    avg = (float)sum / total;
		    printf("The average is: %g\n", avg);
		    break;
		}
	    default:
		printf("Error: Please select option from the displayed menu.\n");
		break;
	}
	printf("Do you want to continue?(y/Y):");
	scanf(" %c", &choice);
    }while (choice == 'y' || choice == 'Y');
}
char *my_strtok(char *str1, char *str2)   //function definition.Here the function returns address so return type is pointer.
{
    int j = 0;                                  //variable declaration.
    static int i;
    static char *temp; 
    int length = i;       //stored i in temp to use the valueof i after it is further changed.
    if (str1 != NULL)         //condition to check the string.
    {
	temp = str1;
    }
    while (temp[i] != '\0')  //loop till the first string doesnt encounter \0.
    {
	j = 0;
	while (str2[j] != '\0')   //loop till  the delimeter string doesnt encounter \0. 
	{
	    if (str2[j] == temp[i])     //condition to Check delimiter string.
	    {
		temp[i] = '\0';
		i++;
		if (temp[length] != '\0')    //condition to check temp value. 
		{
		    return (&temp[length]);
		}
		else          //condition if temp value encounters \0.
		{
		    length = i;   //update length as i for iteration when temp = \0.
		    i--;
		    break;
		}
	    }
	    j++;                  //for next iteration of while loop incrementing i & j value.
	}
	i++;                     
    }
    if (temp[length] == '\0')     //condition when temp value is \0.  i.e end of string.
    {
	i = 0;
	return NULL;        
    }
    else
    {
	return (&temp[length]);    //return address of temp.
    }
}
int my_atoi(const char *str)     //atoi function definition.
{
    int var = 0, var1 = 0, plus = 0;    //Variable Declaration.
    int i = 0, j = 0;
    while ( str[i] != '\0')      //loop till the complete string is iterated.
    {            //condition to check the characters if they are sign or within the digits 0 t0 9. 
	if ( ((str[i] == '+') || (str[i] == '-')) || (str[i] >= '0' && str[i] <= '9') )
	{
	    if( j == 2)
	    {
		return 0;
	    }
	    else
	    {
		var = str[i] - '0';     // operation to convert the character to integer is subtracting  by 0.
		if( str[i] == '-')      //if the iterating element is negative sign.
		{
		    plus = 1;           
		    j++;
		}
		else if ( str[i] == '+')   //if iterating element is positive sign.
		{
		    plus = 0;
		    j++;
		}
		else if( var >= 0 && var <= 9)   //operation if the iterating element of string is a digit.
		{
		    var1 = var1 * 10;     //after multipling with 10 check the condition for the updated value.
		    if ( plus == 1 || var1 < 0 )  
		    {
			var1 = var1 - var;     //updating the value.
		    }
		    else
		    {
			var1 = var1 + var;    //updating the value.
		    }
		}
	    }
	}
	else
	{
	    return var1;   //return value.
	}
	i++;    //for next iteration.
    }
    return var1;
}
