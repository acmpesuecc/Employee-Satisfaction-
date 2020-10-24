#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include"ESS1.h"

int main()	// Main function
{
	////system("COLOR 79");		//Color to change background
	char option;
	float ei=0.0;
	static int cou=0;
	node* start_ptr=NULL;
	do
	{
	printf("\n");
    	printf("\t\t ================================================\n");
	printf("\t\t|\tEmployee Satisfaction Application\t|\n");
	printf("\t\t ================================================\n\n\n");

	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|\t1. Employee \t\t\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|\t2. Administrator \t\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|\t3. EXIT \t\t\t\t|\n");
	printf("\t\t-------------------------------------------------\n\n");

    	printf("\t\tInput number Associated with Your User Type:\n");
		printf("\t\t\t\t\t");
	scanf("%c",&option);
	switch(option)
	{
		case '1':
		{
			printf("\n");
        	printf("\t\t ===================================================\n");
		    printf("\t\t|\tEmployee Satisfaction Application\t|\n");
		    printf("\t\t ===================================================\n\n\n");
		    printf("\t\t--------------------------------------------------\n");
			ei=ESIC(ei);
			start_ptr=employee_Complaint(start_ptr);
			cou++;
			break;
		}
		case '2':
		{
			start_ptr=admin_menu(start_ptr,ei,cou);
			break;
		}
		case '3':
		{
			exit(0);	//function exit
			//goto a;
			break;
		}
		default:
		{
			printf(" \n \nInvalid entry, try again");
			printf("\n \n \n");
			break;
		}
	}
	
	}while(option!='3');//end do
		printf("thank you");
		//system ("PAUSE");

}//end  main function

