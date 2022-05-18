/*Documentation:
Name: Anand Arvind Kulkarni
Date: 23/12/2021
Description: Program to implement own printf function
Sample execution: ./my_printf
Enter a number, char, string: 20  c  Hello
Output: 20 c Hello
Do you want to continue (y/Y) : n
 */

#include<stdio.h>
#include<stdarg.h>
char my_itoa(char*, int);
void my_printf(const char*, ...);
int main()
{
    char choice;
    do
    {
	int num;        //variable declaration.
	char ch;
	char str[50];

	printf("Enter a Number: ");   //user prompt and read the integer.
	scanf("%d", &num);
	printf("Enter a Character: ");   //user prompt and read the character.
	scanf(" %c", &ch);
	printf("Enter a String: ");   //user prompt and read the string.
	scanf("%s", str);
	printf("\n");
	my_printf("Output:\nNumber: %dCharacter:%c\nString:%s", num, ch, str); //Function call to print the given input.
	printf("Do you want to continue?(y/Y): "); //user prompt and read the choice. 
	scanf(" %c", &choice);
    }while( choice == 'y' || choice  == 'Y' );   //do-while loop executes only when the condition true.
}

void my_printf( const char *arg, ...) //Function defination to print the inputs
{
    char str1;
    va_list ap;
    va_start(ap, arg);
    while( *arg )
    {   
	if ( *arg == '%' ) //Check wheather passed character is '%'.
	{
	    arg++;
	    if ( *arg == 'd' ) //Check wheather passed character is 'd'.
	    {
		char str1[100];
		int ret = va_arg( ap, int ); //Read value according to datatype.
		ret = my_itoa(str1, ret);
		puts(str1);
		arg++;
	    }
	    else if( *arg == 'c' ) //condition to check passed character.
	    {
		int var = va_arg( ap, int ); //Read value according to datatype.
		putc(var,stdout);
		arg++;
	    }
	    else if ( *arg == 's' ) //Condition to check the passed character.
	    {
		char *ptr = va_arg( ap, char* ); //Read value depend upon datatype
		puts (ptr);
		arg++;
	    }
	}
	else
	{
	    putchar( *arg ); //Printing character
	    arg++;
	}
    }   
    va_end(ap); //argument pointer ended.

}
//itoa function
char my_itoa(char *arr, int num) //Function declaration for convert character to integer
{
    //Variable declaration
    int i, var, var1;
    //Iterate over argument
    for ( i = 0; num > 0; i++)
    {   
	var = num % 10; //Storing reminder of number in variable
	num = num/10; //number divide by 10
	var1 = var + 48; //convert integer value to character
	arr[i] = var1; //Stored character in array
    }   
    int b, temp; //Variable declaration
    b = i - 1;
    for ( int j = 0; j <= (b/2); j++)     //Iterate over argument
    {   
	temp = arr[j];                    //Swapping operation.
	arr[j] = arr[b];
	arr[b] = temp;
	b--;
    }   
    return 0;
}
