/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 13/12/2021.
Description: Program to print the reverse of the string using iterative and recursive method based on user input.
Sample execution: ./reverse_string.out
1.Iterative method.
2.Recursive method.
Enter your choice:1
Enter the string:Hello world
Reverse string :dlrow olleH
Do you want to continue?(y/Y):y
1.Iterative method.
2.Recursive method.
Enter your choice:2
Enter the string:Dennis Ritchie
Reverse string :eihctiR sinneD
Do you want to continue?(y/Y):n
 */

#include<stdio.h>
#include<stdio_ext.h>
char* reverse_recursive(char *str);     //function prototypes.
char reverse_iterative (char* str);
int main()
{
    char choice;          //variables declaration.
    int option;
    char str[300];        //string declaration.
    do
    {                     //do-while loop initiated.
	printf("1.Iterative method.\n2.Recursive method.\n");   //display menu and read choice.
	printf("Enter your choice:");         
	scanf("%d", &option);            
	__fpurge(stdin);                       //clear stdin buffer.
	switch (option)                        //switch case executed.
	{ 
	    case 1:
		printf("Enter the string:");    //user prompt and read string from user.
		scanf("%[^\n]s", str);
		__fpurge(stdin);
		printf("Reverse string :");     //output message.
		reverse_iterative(str);         //function call.
		printf("%s\n", str);             //output string displayed.
		break;
	    case 2:
		printf("Enter the string:");   
		scanf("%[^\n]s", str);   //read user input.
		__fpurge(stdin); 
		printf("Reverse string :");  
		char* rev = reverse_recursive(str);   //function called and the recieved string stored in char pointer.
		printf("%s", rev);

		printf("\n");
		break;
	    default :
		printf("Error: Select the option from the above displayed menu.\n");
		break;
	}
	printf("Do you want to continue?(y/Y):");  
	scanf("%c", &choice);   
	__fpurge(stdin);
    }while (choice == 'y' || choice == 'Y');   //do-while loop executes if condition is true.
    return 0;
}
char reverse_iterative (char* str)    //function definition with formal parameter.
{
    int i = 0, j, temp, count = 0;
    while ( str[i] != '\0')      //count the length of the string and stored in count variable.
    {
	count++;
	i++;
    }
    for (i = 0; i < (count / 2); i++)   //loop till half of the length.
    {
	temp = str[i];           //operation to reverse the string.
	str[i] = str[count-1-i];
	str[count-1-i] = temp;
    }
    return (char)*str;

}
char* reverse_recursive(char *str)   //function definition.
{
    static int i = 0;   //static so that the updated value is used for the next recursion executed.
    static char rev[100];
    if(*str)
    {
	reverse_recursive(str+1);    //recursive function call.
	rev[i++] = *str;
    }
    return rev;         //return the string to the main function.
}
