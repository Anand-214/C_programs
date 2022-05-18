/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 17/11/2021.
Description: Program to implement the bitwise functions.
Sample Execution: ./bitwise_funct.out
Select bit operation from below list.
1.Get_nbits.
2.Replace_nbits.
3.Get_nbits_from_pos.
4.Replace_nbits_from_pos.
5.Toggle_bits_from_pos.
6.Print_bits.
Enter your choice:1
Enter the number:10
Enter the n bits:2
Get 'n' bits from number o/p:2
 */

#include<stdio.h>
int get_n_bits (int num, int bits)   //function declaration to get the 'n' bits.
{ 
    return num & (1 << bits)-1;     //when the get_n_bits function is called it will return the value evaluated in this     expression. 
}
int replace_n_bits (int num, int bits, int value) //function declaration to replace the 'n' bits.
{
    return num & ~((1<<bits)-1) | value & ((1<<bits)-1); //when replace_n_bits function is called it will return the value  evaluated in this expression.  
}
int get_nbits_from_pos (int num, int pos, int bits)  //function declaration to get 'n' bits from position value.
{
    return ((num & ((1 << (pos+1)) -1)) >> (pos - bits + 1)); //will return this expression's value when get_n_bits_from_posfunction is called.    
}
int replace_nbits_from_pos ( int num, int pos, int bits, int value) //function declaration to replace 'n' bits of number    from position value/.
{
    return num & ~(((1<<bits)-1) << (pos - bits +1)) | ( value & (( 1 << bits) - 1 )) << (pos - bits +1); //returns this    expression's value when the replace_nbits_from_pos function is called.
}
int toggle_nbits_from_pos ( int num, int pos, int bits)  //function declared to toggle 'n' bits from the position.
{
    return num ^ (((1 << (bits)) - 1) << ( pos - bits +1 ));  //the value of this expression is returned when toggle        function is called.
}
int print_bits (int num, int bits)   //function declared to print the required bits of the function.
{
    if ( bits > 31 )        //if the number of bits i/p is more than 31 then we print only 32 bits.
	bits = 32;          //therefore we considered any value greater than 31 as 32 directly.
    for ( int i = (bits-1); i >= 0; i--)  //to get the bits equal to the i/p we start the loop from (bits-1) till 0.
    {
	num >> i & 1 ? printf("1") : printf("0");  //the number right shifted 'i' times and the LSB is checked.If LSB is '1'print "1" if the LSB is '0' print '0'.
    }
}
int main()     //main function declaration.
{
    int num,pos,value,bits,option; //variables with integer datatype are declared.
    char choice;                   //variables with character datatype are declared.
    do         //do-while initiated.If the user wish to continue then the program below this executes again.
    {
	printf("Select bit operation from below list.\n1.Get_nbits.\n2.Replace_nbits.\n3.Get_nbits_from_position.\n4.Replace_nbits_from_position.\n5.Toggle_bits_from_position.\n6.Print_bits.\n"); //This is the menu displayed to the user.
	printf("Enter your choice:");   //User asked to enter the choice to execute the respective operation.
	scanf("%d",&option);            //user input is integer value so %d format specifier used to read the i/p.
	if ( option > 0 && option < 7)  //to check the user i/p is from the displayed menu or not.
	{ 
	    printf("Enter the number:");    //user asked to enter the number on which the opertion is to be done.
	    scanf("%d",&num);               //all the i/p given by user below are integer so each is read using '%d'
	    printf("Enter the n bits:");    //user asked to enter the number of bits he wants to get/manuplate. 
	    scanf("%d",&bits);              //number and bits are common for all operations thus printed in comman here.
	    switch (option)                 //case for the particular selected option executes.
	    {
		case 1:      
		    printf("Get 'n' bits from number o/p:%d\n",get_n_bits(num,bits));  
		    break;       //here above the get_n_bits function is called.
		case 2:
		    printf("Enter the value:");  //we need value as i/p to replace the bits from the value.
		    scanf("%d",&value);  //user i/p is read.
		    printf("Replace 'n' bits o/p:%d\n", replace_n_bits(num,bits,value));
		    break;       //here above the replace_n_bits function is called and executed.
		case 3:
		    printf("Enter the position:"); //we need the position from the user from where the bits are replaced.
		    scanf("%d",&pos); 
		    if ( pos > bits )    //condition to check if the position value is greater than the no. of bits.
			printf("Get 'n' bits from position o/p:%d\n", get_nbits_from_pos(num,pos,bits)); //if the condition is  true the respective function is called.
		    else
			printf("Error: The position value should be greater than 'n' bits value."); //if pos < no. of bits.
		    break;
		case 4:
		    printf("Enter the position:");  //User asked to enter the position of the bits. 
		    scanf("%d",&pos);
		    printf("Enter the value:");   //we need new i/p value from which the bits are to be replaced.
		    scanf("%d",&value);
		    if ( pos > bits)    //condition to check if position value is greater than no. of bits entered.
			printf("Replace 'n' bits from position o/p:%d\n", replace_nbits_from_pos(num,pos,bits,value));//the respective function is called to get the replaced bits from position.
		    else
			printf("Error: The position value should be greater than 'n' bits value.");  //error message.
		    break;
		case 5:
		    printf("Enter the position:");//User asked to enter the position from where the bits need to be toggled.
		    scanf("%d",&pos);
		    if ( pos > bits)           //to check if the position value is greater than the bits value.
			printf("Toggle bits from position o/p:%d\n", toggle_nbits_from_pos(num,pos,bits));  //function to   toggle the bits which is declared above is called here.
		    else
			printf("Error: The position value should be greater than 'n' bits value.");  //error message.
		    break; 
		case 6:
		    printf("Print bits o/p:--> "); 
		    print_bits (num, bits); //above declared function is called to prints the desired number of binary digit
		    printf("\n");
		    break;
	    }
	}
	else      //else case executes if the user input option is not from the displayed menu.
	{
	    printf("Error:Enter the option only from the menu displayed."); //error message.
	}
	printf("\n");
	printf("Do you want to continue?(y/Y):"); //user asked if they want to continue with new option from the menu.
	scanf(" %c",&choice);   //user i/p is a character hence it is read using " %c"
    }while (choice =='y' || choice == 'Y');  //the while condition is true only when the i/p is 'y' oy 'Y'.
    return 0;
}
