/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 29/11/2021.
Decsription : Program to count no. of characters,words and lines.
Sample execution : ./wc_command.c
Enter the string to check:
Hello	 World
Dennis Ritchie
Linux
Character count : 34
Word count : 5
Line count : 3
Do you want to continue?(y/Y):n
 */
#include<stdio_ext.h>
#include<stdio.h>
int main()  
{
    char choice;    //variable with character datatype declared here.
    do              //do-while loop initiated.
    {
	__fpurge(stdin);   //flush the character.
	char input, pre_input; //variable with character datatype ared declared.
	int character, line, word;  //variables with integer datatype are declared.
	character = line = word = 0;    //all the integer variables are assigned with initial value 0.
	puts("Enter the string to check:");   //used input.
	while ((input = getchar()) != EOF)   //the condition is true till user press ctrl+D.
	{
	    character++;          //every character pressed adds on the character count so character incremented.
	    if (input == '\n')    //to check if user pressed enter key to give i/p on next line.
		line++;           //line count incremented.
	    if (input == '\t' || input == 32 || input == '\n') //condition to check if i/p is tab,space or anew line.
	    {
		if (pre_input != input)  //condition to avoid incrementing the count for consecutive enter keys pressed.
		{
		    word++;   //if all the conditionn above are true it means its a new word so the word count incremented.
		}
	    }
	    pre_input = input;   //we assign the previous i/p value to the input to check it for next iteration.
	}
	printf("Character count : %d\n",character);  //print character count.
	printf("Word count : %d\n",word);            //print word count.
	printf("Line count : %d\n",line);            //print line count.
	printf("\n");
	printf("Do you want to continue?(y/Y):"); //user asked if they want to continue with new i/p.
	clearerr(stdin);        //to delete the character from stdin buffer.
	scanf(" %c", &choice);          //%c is the format specifier as the i/p is character.
    }while (choice == 'y' || choice == 'Y');  //do-while loop executes if the i/p is either y or Y only.
}
