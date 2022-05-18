/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/12/2021.
Description: Program to generate consecutive NRPS of legnth n using k distinct characters.
Sample Execution: ./nrps.out
Enter number of characters C: 4
Enter the length of string N: 7
Enter 4 distinct characters: abcd
possible NRPS is: abcdbcd
Do you want to continue(y/Y): n
 */

#include<stdio.h>
int nrps_function (int, int, char*);         //function prototype.
int main()
{
    char choice;            //variable declaration.
    do                      //do-while loop initiated.
    {
	int k, N;          //Variable and array declaration.
	char str[100];      

	printf("Enter number of characters C: ");    //user prompt and read the input in the form of integers.
	scanf("%d", &k);
	printf("Enter the length of string N: ");
	scanf("%d", &N);
	printf("Enter %d distinct characters: ", k);  

	for( int i = 0; i < k; i++ )   //Iterate over argument to scan the entered characters.
	{
	    scanf("\n%c", &str[i]);
	}
	nrps_function (k, N, str);    //function call with arguments as the number of characters, length and the array.
	//Ask user to continue
	printf("Do you want to continue(y/Y): ");       //user prompt.
	scanf("\n%c", &choice );
    }while( choice == 'y' || choice == 'Y' );       //do-while loop execute if condition true.
} 
int nrps_function (int k, int N, char* str)   //function definition with formal arguments.
{
    int res;                 
    int flag = 0;    //variable initialization
    int count = 0;
    for( int i = 0; i < k; i++ )
    {
	for( int j = i + 1; j < k; j++ )
	{
	    if( *( str + i ) == *( str + j ) )  //Condition to check repetation of character.
	    {
		count++;
	    }

	}
    }
    if( count == 0 )  //condition true if count is 0.
    {
	printf("possible NRPS is: ");
	for( int i = 0; i < N; i++ )   //Iterate over argument
	{
	    if( i % k == 0 && i != 0 )  //Check wheather the modulus of position by size is equal to 0 or not.
	    {
		flag++;
	    }
	    res = ( i + flag ) % k;  //Storing the next character position.
	    printf("%c", *( str + res ));
	}
    }
    else
    {
	printf("Error: Enter distinct character");      //error if the characters are not distinct.
    }
    printf("\n");
}
