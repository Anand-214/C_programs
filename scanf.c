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
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

int my_atoi(char *ptr); //Function defination for converting character into integer
void my_strcpy(char*, char*); // own string copy function
int my_scanf(char *, ...);        //defination of function to read integer,character,float,double and string
int main()
{
    char choice;
    int n;                        //declaration of variables
    char c;
    float f;
    char string[20];
    double d;
    printf("Enter the integer: ");  //user prompt and read the values using my_scanf function.
    my_scanf("%d", &n);     //function call.
    printf("you entered integer: %d\n" ,n);
    printf("Enter the char: ");  //user prompt and read the values using my_scanf function.
    my_scanf("%c", &c);     //function call.
    printf("You entered character: %c\n" ,c);    //output displayed from here.
    printf("Enter a float value: ");  //user prompt and read the values using my_scanf function.
    my_scanf("%f", &f);     //function call.
    printf("you entered float: %g\n" ,f);
    printf("Enter a Double value: ");  //user prompt and read the values using my_scanf function.
    my_scanf("%ld", &d);     //function call.
    printf("you entered double: %g\n" ,d);
    printf("Enter a String: ");  //user prompt and read the values using my_scanf function.
    my_scanf("%s", string);     //function call.
    printf("you entered string: %s\n" ,string);
    printf("Do you want to continue (Y/y) : ");   //user prompt and read choice to continue or not.
    my_scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y' )
	main();
    return 0;
}
int my_scanf(char *format, ...)        //function to read input from all primitive datatypes.
{
    va_list ap;                        //pointer to first argument
    int i = 0,j = 0,ret = 0;
    char val[100] = {0},temp[20],c = '0';
    char *out;
    while( c != '\n')
    {
	if(c = getc(stdin))
	{
	    val[i] = c;
	    i++;
	}
    }
    va_start(ap,format);          //move to first unknown argument.
    i = 0;
    while(format && format[i])
    {
	if(format[i] == '%')
	{
	    i++;
	    switch(format[i])
	    {
		case 'c':    //to read character
		    *(char *)va_arg(ap,char *) = val[j];
		    j++;
		    ret++;
		    break;
		case 'd':    //to read integer
		    *(int *)va_arg(ap,int *) = my_atoi(val[j]);
		    j += out - &val[j];
		    ret++;
		    break;
		case 'f':    //to read float
		    *(float *)va_arg(ap,float *) = my_atoi(val[j]);
		    j += out - &val[j];
		    ret++;
		    break;
		case 'l':     //to read double
		    *(double *)va_arg(ap,double *) = my_atoi(val[j]);
		    j += out - &val[j];
		    ret++;
		    break;
		case 's':     //to read string
		    out = (char *)va_arg(ap,char *);
		    my_strcpy(out,&val[j]);
		    j += strlen(&val[j]);
		    ret++;
		    break;
	    }
	}
	else
	{
	    val[j] = format[i];
	    j++;
	}
	i++;
    }
    va_end(ap);
    return ret;
}
void my_strcpy(char *str1, char *str2) //string copy function
{
    int i = 0;
    while (str2[i] != '\0') //loop to copy each character 
    {
	str1[i] = str2[i];
	i++;
    }
    str1[i] = '\0';
}
int my_atoi(char *ptr) //Function defination for converting character into integer
{
    //Variable initialization
    int res = 0, i = 0, sign = 1;
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
}
