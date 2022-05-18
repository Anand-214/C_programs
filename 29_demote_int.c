/*Documentation:
Name: Anand Arvind Kulkarni
Date: 26/12/2021.
Description: Demote the type of given float number to integer.
Sample execution: ./29_demote.out
Enter a float value: 23.76
demoted int value: 23.000000
Do you want to continue?(y/Y):y
Enter a float value: -3.76
demoted int value: -3.000000
Do you want to continue?(y/Y):y
Enter a float value: 0.76
demoted int value: 0.000000
Do you want to continue?(y/Y):y
Enter a float value: 1.76
demoted int value: 1.000000
Do you want to continue?(y/Y):n
 */

union Demote          //defining a union.
{
    float F1;     //F1 is a variable of the union.
    struct Bits   //defining a structure.
    {
	unsigned int Mantissa :23;    //defining members of the structure.
	unsigned int Exp :8;
	unsigned char Sign :1;
    } bits_t;                         //structure variable.
} Num;                                //union variable.
#include <stdio.h>
int main()
{
    char choice;           //declaration of character variable.
    do                     //do-while loop initiated.
    {
	int val, mask;        //variable declaration.
	printf("Enter a float value: ");   //user prompt and read the float value which is accessed under union.
	scanf("%f", &Num.F1 );
	val = Num.bits_t.Exp - 127;   //checking the number of bits. 
	if ( val >= 0 )         //condition when number of bits are >= 0.
	{
	    if (Num.bits_t.Sign & 1 )     //for negative input.
	    {
		Num.F1 = -(Num.bits_t.Mantissa >> ( 23 - val) | ( 1 << val));
	    }
	    else                     //for positive input.
	    {
		Num.F1 = (Num.bits_t.Mantissa >> ( 23 - val) | ( 1 << val));
	    }
	}
	else                 //if the numbe rof bits are less than zero i.e exp - 127 <= 0.      
	{
	    Num.F1 = 0;     //assign the i/p as zero directly to demote it. 
	}
	printf("Demoted value is: %f\n", Num.F1);   //output.
	printf("Do you want to continue?(y/Y):");    //user prompt and read choice.
	scanf(" %c", &choice);
    }while ( choice == 'y' || choice == 'Y');      //do-wile loop executed if condition true.
    return 0;
}
