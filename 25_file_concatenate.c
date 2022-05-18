/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 25/12/2021.
Description: WAP to concatenate two files.
Sample Execution:
./a.out 
Hello
Hello
^C

~/C/room took 5s 
❯ ./a.out file.txt 
content of file 1
content of file 1
content of file 1

~/C/room 
❯ ./a.out file.txt 2file.txt 3file.txt
Data of file.txt copied to 3file.txt successfully.
Data of 2file.txt copied to 3file.txt successfully.
 */


#include<stdio.h>
char ch;     //global variable declaration.
int no_arg_cat();    //function prototypes
int my_cat(FILE* fp1, FILE* fp2);
int display_content (FILE* fpo);

int main(int argc, char* argv[])
{
    switch (argc)            //particular case executes based on the count of argc.
    {
	case 1:       //if argc == 1.    
	    {
		no_arg_cat();     //function call.
	    }
	    break;
	case 2:       //if argc == 2.
	    {
		FILE* fp1 = fopen (argv[1], "r");   //file pointer to open argv[1] file in read mode.
		if ( fp1 != NULL)           //check if file exists or not.
		{
		    display_content (fp1);   //function call to display content on terminal.
		    fclose(fp1);             //once displayed close the file.
		}
		else
		    printf("%s : No such file or directory.\n", argv[1]);  //error if file doesnt exist.
	    }
	    break;
	case 3:       //if argc == 3.
	    {
		FILE* fp1 = fopen (argv[1], "r");   //open the file present in argv[1] in read mode.
		if ( fp1 != NULL)
		{
		    display_content (fp1);         //function call to display content on terminal.
		    fclose(fp1);
		}
		else
		    printf("%s : No such file or directory.\n", argv[1]);   
		FILE* fp2 = fopen (argv[2], "r");   //open file present at argv[2] in read mode.
		if ( fp2 != NULL)                  //check file exists or not.
		{
		    display_content (fp2);        //function call to display content on terminal.
		    fclose(fp2);         //close file.
		}
		else
		    printf("%s : No such file or directory.\n", argv[2]);
	    }
	    break;
	case 4:       //if argc == 4.
	    {
		FILE* fp1 = fopen (argv[1], "r");   //open file at argv[1] in read mode.
		if ( fp1 != NULL)
		{
		    FILE* fp2 = fopen (argv[3], "a+");    //open file at argv[3] in append mode.
		    my_cat(fp1, fp2);         //function call with both parameters as parameters.
		    printf("Data of %s copied to %s successfully.\n",argv[1],argv[3]);  //confirmation message. 
		    fclose(fp1);     //clode respective files.
		    fclose(fp2);
		}
		else
		    printf("%s: No such file or directory.\n", argv[1]);
		FILE* fp3 = fopen (argv[2],"r");    //open file at argv[2] in read mode.
		if ( fp3 != NULL)
		{
		    FILE* fp4 = fopen (argv[3],"a+");   //open file at argv[3] in append mode.
		    my_cat(fp3, fp4);     //function call with both the file poiters as paramters.
		    fclose(fp3);
		    fclose(fp4);
		    printf("Data of %s copied to %s successfully.\n", argv[2], argv[3]); //confirmation message.
		}
		else
		    printf("%s: No such file or directory.\n", argv[2]);   //if argv[2] desnt exists.
	    }
	    break;
    }
}
int no_arg_cat()   //function to display the content entered on screen as it is.
{
    while ((ch = getc(stdin)) != '\0')
	putc(ch, stdout);
}
int my_cat(FILE* fp1, FILE* fp2)  //function to append the content of fp1 into fp2. 
{
    while ((ch = getc (fp1)) != EOF)
	putc (ch, fp2);
}
int display_content (FILE* fpo)   //function to display the content of file on terminal.
{
    while ((ch = getc(fpo)) != EOF)
	putc (ch, stdout);
}
