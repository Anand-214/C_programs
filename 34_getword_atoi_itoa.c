/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 13/12/2021.
Description: To implement getword, atoi, itoa functions.
Sample Execution: ./34_atoi_getword_itoa
1. getword
2. atoi
3. itoa
Enter your choice : 1
Enter a word: Hello
You entered Hello and length is 5

Do you want to continue (y/Y) : y
(Menu to be displayed)
Enter your choice : 1
Enter a word: Hello World
You entered Hello

Do you want to continue (y/Y) : y
(Menu to be displayed)
Enter your choice : 2
Enter a numeric string: 12345
String to integer is 12345

Do you want to continue (y/Y) : n
 */


#include<stdio.h>
#include<string.h>
int my_getword(char*);      //function prototypes.
int my_atoi(char*);        
char *my_itoa(int);
void reverse(char *p, int n);

int main()                 //main function declaration.
{
    char choice;      //character variable declaration.
    do                //do-while loop nitiated.
    {
	int option;        
	printf("choose a case\n 1. getword\n 2. atoi\n 3. itoa\n");   //display menu and read the input.
	printf("Enter your choice:");       
	scanf("%d", &option);        
	switch(option)      //switch case initiated.
	{
	    case 1:
		{
		    char str[200];              //array declaration.
		    printf("Enter a word:");   //user prompt.
		    getchar();
		    scanf("%[^\n]", str);        
		    int var = my_getword(str);    //function call and the value is stored in var.
		    printf("First word is %s & the length is: %d\n",str,var);   //output
		}
		break;
	    case 2:
		{
		    char str[200];                      //array declaration          
		    printf("Enter a numeric string:");  //user prompt.
		    scanf("%s", str);
		    int var = my_atoi(str);              //function call and return stored in var.
		    printf("String to integer is: %d\n",var); //print output.
		    printf("\n");
		}
		break;
	    case 3:
		{
		    int flag,num,i;                     //variable declaration.
		    printf("Enter a number: ");         //user prompt.
		    flag = scanf("%d", &num);            //the user input is stored in flag at the begining.
		    if ( flag != 1)                     //condition to check if flag 
		    {
			printf("Enter the number:");    //if condition true then user prompt.
			return 0;
		    }
		    char* ch = my_itoa(num);         //function call and return stored in character pointer.
		    printf("Integer to string is: %s\n", ch);   //output.
		    printf("\n");
		    break;
		}
	    default:
		printf("ERROR: Invalid choice.\n");
		printf("\n");
	}
	printf("Do you want to continue (y/Y):");       //user asked if they want to continue.
	scanf(" %c", &choice); 
    }while(choice == 'y'|| choice == 'Y');
    return 0;    
}
int my_getword(char *str)     //get word function definition.
{
    int count=0;          //variable declaration.
    int i=0;
    while ( str[i] != '\0')    //operation to count the length of first word.
    {
	if ( str[i] == ' ')    //to get the string upto first space.
	{
	    str[i] = '\0';    //once space encountered, end the string.
	    return count;     
	}
	count++;
	i++;
    }
    return count;  
}
int my_atoi(char *str)     //atoi function definition.
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
char *my_itoa(int num)     //itoa function definition.
{
    static char a[10];    //static array declaration.
    int i = 0;
    while (num)        //loop till num is not zero.
    {
	a[i] = (num % 10) + '0';   //operation to convert the integer to character is adding with 0.
	i++;
	num = num / 10;            //update the number according to the upper opearion.
    }
    int len = strlen(a);    //use of predefined function to calculate the length of string.
    reverse(a, len);     //reverse function called with updated 'a' and length as parameters.
    return a;
}    //above operation gives us the number in reverse form so to again reverse it a separate function is called.
void reverse(char *p, int n)   //void function definition.
{
    char *q = p + (n - 1);    //declaration.
    char temp;
    while (p <= q)      //once we reach till mid value the complete number is reversed.
    {
	temp = *p;      //operation.
	*p++ = *q;
	*q-- = temp;  
    }
}
