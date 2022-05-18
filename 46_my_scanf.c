/*
Name:Anand Arvind Kulkarni
Date:25/12/2021
Description: WAP to implement my_scanf() function.
Sample execution: ./my_scanf.out
Enter the integer: 3
you entered integer: 3
Enter the char: r
You entered character: r
Enter a float value: 1.2
you entered float: 1.2
Enter a Double value: 23
you entered double: 23
Enter a String: Hello
you entered string Hello

Do you want to continue (Y/y) : n
 */

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

int my_atoi(char *ptr); //Function prototypes.
void my_scanf(const char*format,...); 

int main()
{
    char choice;     //declaring the variables
    do
    {
	int num;
	printf("enter a number: ");
	my_scanf(" %d", &num);  //Calling function for integer
	printf("you entered %d\n", num);

	char ch;
	printf("enter a character: ");
	my_scanf(" %c", &ch); //Calling function for character
	printf("you entered %c\n", ch);
	while((ch = getchar()) != '\n');

	float f;
	printf("enter a float value: ");
	my_scanf("%f", &f);  //Calling function for float
	printf("you enterd %g\n", f);

	double d;
	printf("entered a double number: ");
	my_scanf("%lf", &d); //Calling function for double
	printf("you entered %g\n", d);

	char str[200];
	printf("enter a string: ");
	my_scanf(" %s", str); //Calling function for string
	printf("you entered %s\n", str);

	printf("do you want to continue(y/Y): ");   //User prompt and read input.
	my_scanf(" %c", &choice);
	getchar();
    }while( choice == 'y' || choice == 'Y' );
    return 0;
}
int my_atoi(char *ptr) //Function defination for converting character into integer
{
    int res = 0, i = 0, sign = 1;     //Variable initialization
    if( ptr[0] == '-' )  //Checking whether first character is negative or not
    {
	sign = -1;
	i++;
    }
    if( ptr[0] == '+' ) //Checking whether the character is positive or not
    {
	sign = 1;
	i++;
    }

    if ( ptr[i] >= '0' && ptr[i] <= '9' )  //Checking whether the enter character is in range '0' to '9'
    {
	for( ; ptr[i] != '\0'; i++)    //Iterate over argument
	{
	    if ( ptr[i] >= '0' && ptr[i] <= '9' )
		res = res * 10 + ptr[i] - '0';  //Storing integer value in variable
	}
	return *ptr = res * sign;

    }
    else
	return 0;
}
void my_scanf(const char*format,...) //Function defination for scanning user input.
{
    va_list ap;
    const char *arg = format;
    va_start(ap, format);
    int *n;
    char *ch, str1[100], *str;
    float *fp;
    double *dp;

    while(*arg) //Loop will iterate till NULL
    {

	if(*arg == '%') //Checking the passed character is '%' or not
	{
	    arg++;
	    if( *arg == 'c' ) //Checking the passed character is 'c' or not
	    {
		ch = va_arg(ap,char*); //wherever ap is pointing from there fetch first char argument address
		*ch = getchar();
		break;
	    }
	    else if( *arg == 'd' ) //Checking the passed character is 'd' or not
	    {
		fgets(str1, 10, stdin);
		n = va_arg(ap, int*);//wherever ap is pointing from there fetch first int argument address
		*n = my_atoi(str1);
		break;
	    }
	    else if( *arg == 's' ) //Checkcking the passed character is 's' or not
	    {
		str = (char*)(va_arg(ap, char*));//wherever ap is pointing from there fetch first char argument address
		int count = 0;
		for( char ch = getchar() ; ch != 10 ; ch = getchar() )    //Iterate over argument.
		{
		    str[count] = ch; //Storing character in pointer array
		    count++;
		}
		str[count] = '\0'; //Storing null at last element
		break;
	    }
	    else if( *arg == 'f' ) //Checking the passed character is 'f' or not
	    {
		fgets(str1, 10, stdin);
		fp = va_arg(ap, float*); //storing argument in floating type
		*fp = atof(str1);
		break;
	    }
	    else if( *arg == 'l' ) //Checking wheather passed character is 'l' or not
	    {
		fgets(str1, 10, stdin);
		dp = va_arg(ap, double*); //Storing argument in double type
		*dp = atof(str1);
		break;
	    }

	}
	arg++;
    }

    va_end(ap); //End of argument
}
