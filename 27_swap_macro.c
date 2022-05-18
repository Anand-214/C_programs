/*Documentation
Name: Anand Arvind Kulkarni
Date: 20/12/2021.
Description: Define macro(t,x,y) to swap to arguments of type t.
Sample Execution:  ./Swap_macro.out
1.Integer.
2.Character.
3.Short.
4.Float.
5.Double.
6.String.
Select you choice:1

Enter the num1:10
Enter the num2:20
After swapping:
num1:20
num2:10
Do you want to continue?(y/Y):n
 */

#include<stdio.h>             //header files.
#include<stdlib.h>
#define MAX 100               //defining a macro function.
#define SWAP_DATA(type, x, y) \
{ \
    type temp;\
    temp = x; \
    x = y; \
    y = temp; \
}
int main()
{
    char choice;         //variable declaration.
    do          //do-while loop initiated.
    {
	int option;       
	printf("1.Integer.\n2.Character.\n3.Short.\n4.Float.\n5.Double.\n6.String.\nSelect you choice:");  //menu display.
	scanf("%d", &option);    //read user input for switch case.
	printf("\n");
	switch (option)          //switch case.
	{
	    case 1:     //case 1 for integer variable swapping.
		{
		    int num1, num2;   //variable declaration.
		    printf("Enter the num1:");   //user prompt and read both inputs.
		    scanf("%d", &num1);
		    printf("Enter the num2:");
		    scanf("%d", &num2);
		    SWAP_DATA(int, num1, num2);  //macro called here to perfrom swap operation where type replaced by int.
		    printf("After swapping:\nnum1:%d\nnum2:%d\n", num1, num2);  //output.
		    break;
		}
	    case 2:
		{      //case 2 for character swapping.
		    char char1, char2;   //variable declaration.
		    printf("Enter the char1:");   //user prompt and read both the characters.
		    scanf(" %c", &char1);
		    printf("Enter the char2:");
		    scanf(" %c", &char2);
		    SWAP_DATA(char, char1, char2);   //macro called with type as character and perfrom swapping.
		    printf("After swapping:\nchar1:%c\nchar2:%c\n", char1, char2);   //output
		    break;
		}
	    case 3:
		{      //case 3 for short values swapping.
		    short sh1, sh2;    //variable declaration.
		    printf("Enter the short num1:");    //user prompt and read both short values
		    scanf("%hd", &sh1);
		    printf("Enter the short num2:");
		    scanf("%hd", &sh2);
		    SWAP_DATA(short, sh1, sh2);       //macro called with type as short and perfrom swapping.
		    printf("After swapping:\nnum1:%hd\nnum2:%hd\n", sh1, sh2);   //output.
		    break;
		}
	    case 4:
		{     //case 4 for float values swapping
		    float flt1, flt2;  
		    printf("Enter the float num1:");  //user prompt and read both float values
		    scanf("%f", &flt1);
		    printf("Enter the float num2:");
		    scanf("%f", &flt2);
		    SWAP_DATA(float, flt1, flt2);    //macro called with float as the type.
		    printf("After swapping:\nnum1:%g\nnum2:%g\n", flt1, flt2);   //output.
		    break;
		}
	    case 5:
		{     //case 5 for double values swapping.
		    double num1, num2;   
		    printf("Enter the double num1:");  //user input and read both double values.
		    scanf("%lf", &num1);
		    printf("Enter the double num2:");
		    scanf("%lf", &num2);
		    SWAP_DATA(double, num1, num2);     //macro called with type as double and perfrom swapping.
		    printf("After swapping:\nnum1:%lg\nnum2:%lg\n", num1, num2);  //output.
		    break;
		}
	    case 6:
		{     //case 6 for string swapping.
		    char* str1 = malloc( MAX * sizeof(char));   //dynamic memory allocation for both strings 
		    char* str2 = malloc( MAX * sizeof(char));   //here the MAX is macro defined with value 100.
		    printf("Enter the string1:");         //user prompt and read both strings.
		    scanf("%s", str1);
		    printf("Enter the string2:");
		    scanf("%s", str2);
		    SWAP_DATA(char*, str1, str2);    //macro called with type as char* so that the address can be treated.
		    printf("After swapping:\nstr1:%s\nstr2:%s\n", str1, str2);  //output.
		    free(str1);   //free both the dynamic memory allocated string.
		    free(str2);
		    break;
		}
	    default:    //default if no option entered from the display menu.
		printf("ERROR:Please enter the option from the displayed menu.\n");   //error.
	}
	printf("Do you want to continue?(y/Y):");   //user prompt to ask if continue or not.
	scanf(" %c", &choice);
	printf("\n");
    }while (choice == 'y' || choice == 'Y');  //do-while loop executed only when i/p is y or Y else exit.
}
