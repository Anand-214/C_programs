/*Documentation:
Name: Anand Arvind Kulkarni
Date: 19/12/2021
Description: Implement calc_mean for all data types.
Sample Execution:
./a.out 5
1.Integer
2.Short
3.Float
4.Double
Enter the choice: 1
Enter 5 elements of type int:
a[0]: 2
a[1]: 4
a[2]: 6
a[3]: 9
a[4]: 3
The mean value: 4
Do you want to continue: y
 */

#include<stdio.h>
#include<stdlib.h>
int my_atoi(char*); //Function defination for character to integer converter
double calc_mean( void*, int, int); //Function defination for calculating mean
int main( int argc, char *argv[] ) //Command line argument
{
    if ( argc != 2)
	printf("ERROR:Please pass the number of elements through command line argument.");
    else
    {
	char choice;
	do
	{
	    int option;        //variable declaration.
	    int size = my_atoi( argv[1] ); //Function call.
	    void *ptr;

	    printf("1.Integer\n2.Short\n3.Float\n4.Double\nEnter the choice: ");
	    scanf("%d", &option);
	    switch ( option )    //switch case.
	    {
		//Case 1 for integer type array
		case 1: ptr = malloc( size * sizeof(int )); //Allocating dynamic memory
			printf("Enter %d elements of type int:\n",size);
			for( int i = 0; i < size; i++ )//Iterate over argument
			{
			    printf("a[%d]: ", i);
			    scanf("%d", ((int *)ptr + i));
			}
			float mean= calc_mean( ptr, size, 1 ); //Function call
			printf("The mean value: %g\n", mean);
			break;

			//Case two for short type array        
		case 2: ptr = malloc(size * sizeof( short ));
			printf("Enter %d elements of type short:\n", size);
			for( int i = 0; i < size; i++ )    //itterate over argument.
			{
			    printf("a[%d]: ", i);
			    scanf("%hd", ((short *)ptr + i));
			}
			short mean1 = calc_mean( ptr, size, 2 ); //Function call
			printf("The mean value: %hd\n", mean1);
			break;

			//Case three for float type array
		case 3: ptr = malloc( size * sizeof( float)); //Allocating dynamic memory
			printf("Enter %d elements of type float:\n", size);
			for( int i = 0; i < size; i++ )  //Iterate over argument
			{
			    printf("a[%d]: ", i);
			    scanf("%f", ((float *)ptr + i));
			}
			float mean2 = calc_mean( ptr, size, 3 ); //Function call
			printf("The mean value: %g\n", mean2);
			break;

			//Case four for double type array        
		case 4: ptr = malloc(size * sizeof( double)); //Allocating dynamic memory
			printf("Enter %d elements of type double:\n", size);
			for( int i = 0; i < size; i++ ) //Iterate over argument
			{
			    printf("a[%d]: ", i);
			    scanf("%lf", ((double *)ptr + i));
			}
			double mean3 = calc_mean( ptr, size, 4 ); //Function call
			printf("The mean value: %lf\n", mean3);
			break;
	    }
	    free( ptr ); //to free the memory allocated dynamically for void array.
	    printf("Do you want to continue: ");   //user prompt.
	    scanf(" %c", &choice);
	}while( choice == 'Y' || choice == 'y' );
    }
}
double calc_mean( void *arr, int size, int type ) //Function defination for mean operation.
{
    if( type == 1 ) //Condition for integer type.
    {
	int sum = 0;
	int mean;
	for( int i=0; i < size; i++ )   //loop to iterate over argument.
	{
	    sum = sum + *((int *)arr + i); //Calculating sum of integers
	}
	return mean = sum / size; //returning mean value in integer
    }
    else if( type == 2 ) //Condition for short type values.
    {
	short sum = 0;
	short mean;
	for( int i=0; i < size; i++ )  //loop to calculate mean.
	{
	    sum = sum + *((short *)arr + i); //Calculating sum of short values
	}
	return mean = ((short) sum / size); //Returning mean value in short
    }
    else if( type == 3 ) //Condition for float type values.
    {
	float sum = 0;
	float mean;
	for( int i=0; i < size; i++ )  
	{
	    sum = sum + *((float *)arr + i); //Calculating sum of float values.
	}
	return mean = ( (float) sum / size); //returning mean value in float
    }
    else if( type == 4 ) //Condition for double values.
    {
	double sum = 0;
	double mean;
	for( int i=0; i < size; i++ )   //loop to calculate mean of double values.
	{
	    sum = sum + *((double *)arr + i); //calculating sum of double values.
	}
	return mean = ((double) sum / size); //Returning mean value in double
    }
}


//The argument received through command line is in form of string so need to convert it to integer. 
int my_atoi(char *ptr) //converting character to integer.
{
    int res = res * 10 + ptr[0] - '0';  //Storing integer value in variable
    return res; //Returning value into integer
}

