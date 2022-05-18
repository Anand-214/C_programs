#include<stdio.h>
void IEEE_real (void*, int);
int main()
{
    char choice;
    do
    {
	int option;
	float num1;
	double num2;
	printf("1.Float\n2.Double\nEnter your choice:");
	scanf("%d", &option);
	switch (option)
	{
	    case 1:
		printf("Enter the float value:");
		scanf("%f", &num1);
		printf("Sign		Exponent		Mantissa\n");
		printf("---------------------------------------------------------------\n");
		IEEE_real (&num1, 1);
		break;
	    case 2:
		printf("Enter the double value:");
		scanf("%lf", &num2);
		printf("Sign		Exponent		Mantissa\n");
		printf("--------------------------------------------------------------------------------------------\n");
		IEEE_real (&num2, 2);
		break;
	    default:
		printf("Please select the option from menu displayed above.\n");
		break;
	}
	printf("\n");
	printf("Do You want to continue?(y/Y):");
	scanf(" %c", &choice);
    }while( choice == 'y' || choice == 'Y');
}
void IEEE_real (void* num, int key)
{
    int i;
    if ( key == 1)
    {
	int* num1 = (int*)num;
	if ( i = 31)
	    *num1 >> i & 1 ? printf("1") : printf("0");
	    printf("		");
	for ( i = 30; i >= 23; i--)
	{  
	    *num1 >> i & 1 ? printf("1") : printf("0");
	}
	printf("		");
	for ( i = 22; i >= 0; i--)
	{
	    *num1 >> i & 1 ? printf("1") : printf("0");
	}
	printf("		");
    }
    else
    {
	long int* num1 = (long int*)num;
	if ( i = 63)
	    *num1 >> i & 1 ? printf("1") : printf("0");
	    printf("		");
	for ( i = 62; i >=52 ; i--)
	{  
	    *num1 >> i & 1 ? printf("1") : printf("0");
	}
	printf("		");
	for ( i = 51; i >= 0; i--)
	{
	    *num1 >> i & 1 ? printf("1") : printf("0");
	}
	printf("		");
    }

}
