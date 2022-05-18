#include<stdio.h>
char is_alpha ( char input )  //the function is declared to check if the i/p character is an alphabetic character.
{
    return ((input >=97  && input <= 122) || (input >= 65 && input <= 90)); //any i/p within this range is alphabet.
}
char is_alnum ( char input )  //the function is declared to check if the i/p character is an alpha-numeric character.
{                    //any i/p within the below specified range is either a digit or a alphabet i.e. alpha-numeric. 
    return ((input >= 48 && input <= 57) || (input >= 97  && input <= 122 ) || (input >= 65 && input <= 90));
}
char is_ascii ( char input )  //the function is declared to check if the i/p character is an ascii equivalent value.
{
    return (input >= 1 && input <= 127);   //any i/p within this range is an ascii character.
}
char is_blank ( char input)   //the function is declared to check if the i/p character is a blank space or not.
{             //ascii equivalent of 9 is tab and 32 is space. These both are considered as blank characters. 
    return (input == 9 || input == 32);   //if the i/p is any of the either two values then the character is blank.
}
int main()           //main function declaration.
{
    char choice, value;   //variables with character data type are declared here.
    int option;           //variables with integer data type are declared here. 
    do              //do-while loop initiated.
    {	            //If the user wish to continue with new character i/p then the statements below this line will execute.
	printf("Enter the character:");  //user asked to enter the character to check it belongs to which c-type library.
	scanf("%c", &value);      //the user i/p is a single character hence %c format specifier is used.
	getchar();              //used to fetch the extra 'enter' character from the stdin.
	printf("Select any option:\n1.isalpha\n2.isalnum\n3.isascii\n4.isblank\n"); //menu displayed to the user.
	printf("Enter your choice:");  //user is asked to select any one option at time from the menu.
	scanf("%d", &option);          //the user i/p is an integer so %d is used as format specifier. 
	getchar();              //used to fetch the extra 'enter' character from the stdin.      

	switch (option)  //switch case used to execute the option which the user is willing to check.
	{
	    case 1:   //case 1 executes when user wants to check if i/p is an aplhabetic character or not.
		if (is_alpha (value))  //is_alpha function is called here. If the function return 1 the condition is true.
		    printf("The character '%c' is an alpha character.\n", value); //line displayed as o/p.
		else  //if i/p isn't the alphabetic character else statement executes.
		    printf("The character '%c' is not an alpha character.\n", value); //line displayed as o/p.
		break;
	    case 2:  //case 2 executes when user wants to check if i/p is an alphanumeric character or not.
		if (is_alnum (value)) //condition is true if the function return 1 after it is called here.
		    printf("The character '%c' is an alnum character.\n", value); //output if condition true.
		else
		    printf("The character '%c' is not an alnum character.\n", value); //output line.
		break;
	    case 3: //case 3 executes when user wants to check if i/p is an ascii character or not.
		if ( is_ascii (value)) //condition true if the function called here returns 1.
		    printf("The character '%c' is an ascii character.\n", value); //output line when if condition executes.
		else
		    printf("The character '%c' is not ascii character.\n", value); //o/p line when else condition executes.
		break;
	    case 4:  //case 4 executes when the user wants to check if i/p is a blank character or not. 
		if ( is_blank (value)) //condition true if the function called here returns 1.
		    printf("The character '%c' is a blank character.\n", value); //o/p line when if condition executes.
		else
		    printf("The character '%c' is not a blank character.\n", value); //o/p line when else condition execute.
		break;
	}      //switch case is closed here.
	printf("Do you want to continue?(y/Y):"); //user asked if they want to continue by entering new character as i/p.
	scanf("%c", &choice);  //the user i/p is a character hence %c is used as a format specifier.
	getchar();    //getchar used to fetch extra character from the stdin.
    }while( choice == 'y' || choice == 'Y'); //the do while loop executes only when the user i/p is either 'y' or 'Y'.
} 
