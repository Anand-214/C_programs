/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 21/12/2021.
Description: WAP to print bits of float & double.
Sample Execution: ./31_print_bits.out
1.Float
2.Double
Enter your choice:1
Enter the float value:2.3
Sign		Exponent		Mantissa
---------------------------------------------------------------
0		10000000		00100110011001100110011
Do You want to continue?(y/Y):y
1.Float
2.Double
Enter your choice:2
Enter the double value:-5.5
Sign		Exponent		Mantissa
--------------------------------------------------------------------------------------------
1		10000000001		0110000000000000000000000000000000000000000000000000
Do You want to continue?(y/Y):n
 */

#include<stdio.h>
void IEEE_real (void*, int);
int main()
{
    char choice; 
    do              //do-while loop initiated.
    {
	int option;  ///variable declaration.
	float num1;
	double num2;
	printf("1.Float\n2.Double\nEnter your choice:");  //user prompt and read the choice.
	scanf("%d", &option);     
	switch (option)          //switch case based on the option selected.
	{
	    case 1:       //case 1 for float value.
		printf("Enter the float value:");    //user prompt & read float value.
		scanf("%f", &num1);
		printf("Sign\t\tExponent\t\tMantissa\n");   //Display heading.
		printf("---------------------------------------------------------------\n");   //border.
		IEEE_real (&num1, 1);   //function call & key is 1 when i/p is float.
		break;
	    case 2:     //case 2 for double value.
		printf("Enter the double value:");   //user prompt & read read double value.   
		scanf("%lf", &num2);
		printf("Sign\t\tExponent\t\tMantissa\n");     //Display heading.
		printf("--------------------------------------------------------------------------------------------\n");
		IEEE_real (&num2, 2);  //function call & key is 2 when i/p is double.
		break;
	    default:
		printf("ERROR: Please select the option from menu displayed above.\n");   //error message.
		break;
	}
	printf("\n");
	printf("Do You want to continue?(y/Y):");   //user prompt to continue & read input.
	scanf(" %c", &choice);
    }while( choice == 'y' || choice == 'Y');   //do-while loop execute only when i/p is y / Y.
}
void IEEE_real (void* num, int key)     //function definition.
{
    int i;
    if ( key == 1)        //key==1 means the i/p is float.
    {
	int* num1 = (int*)num;   //type castting as bitwise possible for integral values only.
	if ( i = 31)       //to get 1 sign bit.(MSB)
	    *num1 >> i & 1 ? printf("1") : printf("0"); //check the bit is 0 or 1 and display accordingly.
	printf("\t\t");  
	for ( i = 30; i >= 23; i--)   //to get 8 exponent bits.
	{  
	    *num1 >> i & 1 ? printf("1") : printf("0"); 
	}
	printf("\t\t");
	for ( i = 22; i >= 0; i--)   //to get 23 mantissa bits.
	{
	    *num1 >> i & 1 ? printf("1") : printf("0"); 
	}
	printf("\t\t");
    }
    else    //else executes when key == 2 (i.e) i/p is double value.
    {
	long int* num1 = (long int*)num;   //type casting as bitwise not possible for double values.
	if ( i = 63)     //to get 1 sign bit.  (MSB)
	    *num1 >> i & 1 ? printf("1") : printf("0");   //check the bit is 0 or 1 and display accordingly.
	printf("\t\t");
	for ( i = 62; i >=52 ; i--)   //to get 11 exponent bits.
	{  
	    *num1 >> i & 1 ? printf("1") : printf("0");
	}
	printf("\t\t");
	for ( i = 51; i >= 0; i--)     //to get 52 mantiss bits.
	{
	    *num1 >> i & 1 ? printf("1") : printf("0"); 
	}
	printf("\t\t");   
    }
}
