/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 08/11/2021.
Description: Program to display which day of the year based on the first day entered.
Sample execution: ./calendar.out
Enter the value of 'N':9
1.Sunday
2.Monday
3.Tuesday
4.Wednesday
5.Thursday
6.Friday
7.Saturday
Enter the option to set the first day:2
The 9th Day of the year is Tuesday.
Do you want to continue?(y/Y):Y
Enter the value of 'N':366
Error:Invalid i/p,'N' value should be >0 and <=365.
Do you want to continue?(y/Y):n
*/

#include<stdio.h>
int main()
{
    int num,option,opr,day;  //variables with integer datatype are declared here.
    char choice;             //variables with character datatype are declared here.
    do                       //do-while loop initiated.
    {
	printf("Enter the value of 'N':");  //user asked to enter the number of nth day to be displayed.
	scanf("%d",&num);                   //scanf used to read the user input.
	if( num>0 && num<=365)          //Condition to check if the number is between 1 and 365 or not.
	{
	printf("1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\n"); //Display menu.
	printf("Enter the option to set the first day:");      //User asked to select option from the displayed menu.
	scanf("%d",&option);                 //scanf used to read the input from the display menu.
	if ( option >=1 && option <= 7)     //condition to check if the input id from the given menu ot not.
	{
	    opr=(num + option)-1;    //we consider the count from the day itself so subtracted the addition with -1.
	    day=(opr % 7);       //The total number of days are 7 hence we modded the o/p with 7 to get the expected day.
	    
	    switch (day)       //switch case to display the o/p based on the result of the above operation.
	    {
		case 1:        //This case is executed if the remainder is 1. 
		    printf("The %dth day is Sunday.\n",num);  //The o/p day will be sunday for this case.
		    break;   
		case 2:        //This case is executed if the remainder is 2.
		    printf("The %dth day is Monday.\n",num);  //The o/p day will be monday for this case.
		    break;
		case 3:        //This case is executed if the remainder is 3.
		    printf("The %dth day is Tuesday.\n",num);  //The o/p day will be tuesday for this case.
		    break;
		case 4:        //This case is executed if the remainder is 4.
		    printf("The %dth day is Wednesday.\n",num); //The o/p day will be wednesday for this case.
		    break;
		case 5:        //This case is executed if the remainder is 5.
		    printf("The %dth day is Thursday.\n",num);  //The o/p day will be thursday for this case.
		    break;
		case 6:        //This case is executed if the remainder is 6.
		    printf("The %dth day is Friday.\n",num);   //The o/p day will be Friday for this case.
		    break;
		case 0:        //This case is executed if the remainder is 0.
		    printf("The %dth day is Saturday.\n",num);  //The o/p day will be saturday for this case.
		    break;
	    }
	}
	else
	{
	    printf("ERROR:Invalid Input.The first day Should be >0 and <=7.\n"); //error if the option entered from the     display menu is less than 1 or greater than 7.Because we have 7 days in a week.
	}
	}
	else
	{
	    printf("ERROR:Invalid Input.'N' value should be >0 and <=365.\n");  //error message if the value entered id less than 1 and greter than 365. Because we have 365 days in a year.
	}
	printf("Do You want to continue?(y/Y):");  //User asked if want to continue by entring new value.
	scanf(" %c",&choice);                     //The user input is a character so " %c".The space is used becaus we      consider only the single character and not the enter key pressed after character.
	}while (choice=='Y' || choice=='y');   //the do-while loop is executed when the i/p is y/Y only.This will again     start the execution.
	return 0;
    }


