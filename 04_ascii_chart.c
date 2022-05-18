/*Documentation:
Name:- Anand Arvind Kulkarni.
Date:- 31/10/2021.
Description:- Program to display the ASCII characters in a table.
Sample execution:- ./04_ascii
             Octal	Decimal	  Hexa	    Ascii
            --------    ------   -------    ------
              000          0      01       Non Printable.
              001          1      01       Non Printable.
               ||          ||     ||          ||
               ||          ||     ||          ||
              176         126     7E           ~
	      177         127     7F       Non-Printable.
 */            

#include<stdio.h>
int main()
{
    int i;             //i is declared as a integer variable to iterate using a for loop.
    printf("Octal	Dec	Hex	Character\n");         // the heading row which gives information of the formats displayed in chart.
    printf("-----	---	---	----------\n");        // line separating the heading from the actual table starting from decimal value 1 upto 127. 
    for (i=0;i<=127;i++)                                       //for loop which will iterate from i=1 to i=127.
    {
	if (i>=0 && i<=32 || i==127)                           //from deciaml 1 to decimal 32 the characters in the ascii chart are non-printable.Thus a separate condition for them. 
	printf("%o	%d	%x	Non-printable.\n",i,i,i);  //for all those non-printable charcters the octal,decimal,hexa column will be the same just the ascii column will display non-printable.
	else
	printf("%o	%d	%x	%c\n",i,i,i,i);  // %o for the octal value, %d for the decimal value, &x for the hexadecimal value and %c for the character values.
    }
    return 0;
}


