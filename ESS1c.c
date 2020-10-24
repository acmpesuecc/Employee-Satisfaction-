#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ESS1.h"

void deleteNode(node **head_ref, int key) // Basic deletion process of a node from the employee linked list
{ 
    
    node* temp = *head_ref, *prev; 
  
     //Traversing through the list to find the node to be deleted
    if (temp != NULL && temp->complaint_number == key) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    } 
  
    
    while (temp != NULL && temp->complaint_number!= key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 

node* employee_Complaint(node* start_ptr)	// This function is used to register a complaint from the user
{
	printf("\n");
    printf("\t\t ================================================\n");
	printf("\t\t|   Employee Satisfaction Application |\n");
	printf("\t\t ================================================\n\n\n");
	
    printf("\nAdd Your Complaint Details\n");
	printf("________________________________\n\n");

	node *temp;
	temp = malloc(sizeof(node)); // Initializizng a new node for a new user's complaint, which takes in their name, date and complaint
	printf("Type Complaint no: ");
    scanf("%d",&temp->complaint_number);
	printf("Enter Your Name: ");
	scanf("%s",temp->customerName);
	printf("Enter Date in format dd/mm/yyyy: ");
	scanf("%s",temp->date);
	printf("Complaint Description:\n");
	printf("( 1000 words maximum !!) \n");
	scanf("%[^\n]%*c", temp->x);

	printf("===========================================================================\n");
    printf("Complaint added Successfully\n");
    printf("===========================================================================\n");
    

    	temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr; //Moves to next complaint node
	}
	start_ptr=temp;
	return start_ptr;
}


node* create_complaint(node* start_ptr)
{
	printf("\n");
    	printf("\t\t ================================================\n");
	printf("\t\t|   Employee Satisfaction Application |\n");
	printf("\t\t ================================================\n\n\n");
	printf("\nAdd Complaint Details of Customer\n");
	printf("_____________________________________ \n\n");

	node *temp;
	temp = malloc(sizeof(node));
	printf( "Type Complaint no: ");
    scanf("%d",&temp->complaint_number);
	printf( "Enter Customer Name: ");
	scanf("%[^\n]s\n",temp->customerName);
	printf("\nEnter Date in format dd/mm/yyyy: ");
	scanf("%s\n",temp->date);
	printf("\nComplaint Description:");
	printf("( 1000 words maximum !! ) \n");
	scanf("%[^\n]s",temp->x);

	printf("===========================================================================\n");
    	printf( "Complaint added Successfully\n");
    	printf("===========================================================================\n");
    	printf( "Go to Print Complaint to print the Complaint\n");
    	printf("===========================================================================\n");
	

    	temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
    return start_ptr;
}


void view_complaint(node* start_ptr) // Lists out the complaints in an ordered format
{
	int num;
	int found;			//variable to search
	node *temp;

	temp=start_ptr;
	found = 0;
	printf("\n");
    printf("\t\t ================================================\n");
	printf("\t\t|   Employee Satisfaction Application |\n");
	printf("\t\t ================================================\n\n\n");
	printf(" Enter the Complaint Number To Look into The Complaint Details\n");
	scanf("%d",&num);   // Choosing a specific complaint based on numbered priority
	printf("\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\t\tHere is the Complaint list\n");
	printf("---------------------------------------------------------------------------\n");


	if(temp == NULL) 
	{
		printf("\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n");
	}
	while(temp !=NULL && !found)
	{
		if (temp->complaint_number==num)
		{
			found = 1;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)  // Prints complaint details only if found
        {
		printf("Complaint Number : %d",temp->complaint_number);
		printf("\n");
		printf("Customer Name: %s",temp->customerName);
        printf("\n");
		printf("Complain Date : %s",temp->date);
        printf("\n");
		printf("_____________________________________________________________________________\n");
		printf("-------------------------\n");
		printf("|Complaint description: |\n");
		printf("-------------------------\n");
		printf("%s",temp->x);

		printf("\n");
		printf("_____________________________________________________________________________\n");

		}
	}
	if(!found)
	{
		printf("Sorry No complaints to show!\n\n");
	}
}



node* cancel_complaint(node* start_ptr) // Removes a certain complaint from the list of complaints, assuming it exists
{
	node *last = NULL;

	int num, count;
	printf("\n");
    	printf("\t\t ================================================\n");
	printf("\t\t|   Employee Satisfaction Application |\n");
	printf("\t\t ================================================\n\n\n");
    	printf("Enter the Complaint number you want to delete \n");
    	scanf("%d",&num);
    	node *q;
	node *temp;
	int found;

	if(start_ptr == NULL)
		printf("Can not cancel from an empty list.\n");
	else
	{
		if(start_ptr->complaint_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			deleteNode(&q,num);
			printf("The Complaint is Cancelled Successfully\n");
		}
		else
		{
			found = 0;
			temp = start_ptr;
			q = start_ptr->next;

		while((!found) && (q != NULL))  //Keeps moving until the right complaint is found
		{
  			if(q->complaint_number != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = 1;
		}

			if(found) //Connects the prev complaint to the next one and removes the chosen complaint
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				deleteNode(&q,num);
				printf("The Complaint is Cancelled Successfully\n");
			}
			else
				printf("Complaint to be Cancelled is not in the list.\n");
			}
		}
		return start_ptr;
}	//End function

node* update_complaint(node* start_ptr)// Used to update complaint details if any data or info is missing or is to be added
{
 int sid;
 int found;
 found = 0;
 node* temp;
 temp = start_ptr;
 printf("\n");
 printf("\t\t ================================================\n");
 printf("\t\t|   Employee Satisfaction Application |\n");
 printf("\t\t ================================================\n\n\n");
 printf("Enter Complaint Number To Update: ");
 scanf("%d",&sid);
 if(temp==NULL && sid==0)
 {
    printf("No Complaint To Update..!");
 }

 else
 {
 	while(temp !=NULL && !found) // loops to search for complaint
	{
		if (temp->complaint_number==sid)
		{
			found = 1;
		}
		else
		{
			temp = temp -> next;
		}
    if (found) //repitition of complaint entry info
    {
	printf( "Change  Complaint Number: ");  
    scanf("%d",&temp->complaint_number);
	printf( "Change Customer Name: ");
	scanf("%s",temp->customerName);
	printf("Change Date : ");
	scanf("%s",temp->date);
	printf("Complaint Description:\n");
	printf("( 1000 words maximum and without spaces!! ) \n");
	printf( "  ");
	scanf("%s", temp->x);
	
	temp = temp->next;


	}

 printf("COMPLAINT RECORD UPDATED....!\n\n");
 }
	// returns that complaint number is invalid if not found
 	if(temp != NULL && temp->complaint_number != sid) 
 	{
 	printf("Invalid Complaint Number...!\n\n");
    }

}
return start_ptr;
}	

float ESIC(float ei) // Calculates the employee satisfaction index
{
    struct ESI E;
    printf("Answer These Quick Three Questions TO help us understand your satisfaction with our services!\n");
    printf("Answer All These 3 Questions on a scale from 1-10 \n");
    printf("How satisfied are you with your current workplace? \n");
    scanf("%d",&E.q1);
    printf("How well does your current workplace meet your expectations? \n");
    scanf("%d",&E.q2);
    printf("How close is your current workplace to the ideal one? \n");
    scanf("%d",&E.q3);
	if(E.q1>10)
		E.q1=10;
	if(E.q2>10)
		E.q2=10;
	if(E.q3>10)
		E.q3=10;
	if(E.q1<1)
		E.q1=0;
	if(E.q2<1)
		E.q2=0;
	if(E.q3<1)
		E.q3=0;
    float m=((E.q1+E.q2+E.q3)/3) - 1;
    float esip=(m/9) * 100;
    ei=ei+esip;
    return ei;
}


node* admin_menu(node* start_ptr,float ei,int cou) // Opens up the administrator form where complaints can be taken care of
{
    char menu;
    	do
	    {
        	printf("\n");
        	printf("\t\t ===================================================\n");
		    printf("\t\t|   Employee Satisfaction Application    |\n");
		    printf("\t\t ===================================================\n\n\n");
		    printf("\t\t--------------------------------------------------\n");
		    printf("\t\t||\t1. Create a Complaint \t\t\t ||\n");
		    printf("\t\t||\t2. View Complaint\t\t\t ||\n");
		    printf("\t\t||\t3. Update Complaint Status \t\t ||\n");
		    printf("\t\t||\t4. Print the Employee Satisfaction Index \t\t\t ||\n");
		    printf("\t\t||\t5. Cancel a Complaint \t\t\t ||\n");
		    printf("\t\t||\t6. Logout\t\t\t\t ||\n");
		    printf("\t\t--------------------------------------------------\n");
		    printf("Enter choice: ");

		    scanf(" %c",&menu);

		    switch (menu)
		    {
			    case '1':         // Shows the esi rating
			    {
					printf("\n");
        			printf("\t\t ===================================================\n");
		    		printf("\t\t|   Employee Satisfaction Application    |\n");
		    		printf("\t\t ===================================================\n\n\n");
		    		printf("\t\t--------------------------------------------------\n");
					ei=ESIC(ei);
				    start_ptr=employee_Complaint(start_ptr);
					cou++;
				    break;
			    }


			    case '2': //Selecting this displays complaints
			    {
				    view_complaint(start_ptr);
					printf("%d",cou);
				    break;
			    }

			    case '3': //This functions updates the complaint list
			    {
				    start_ptr=update_complaint(start_ptr);
				    break;
			    }

			    case '4': //calculates the desirability of the company based on the esi rating given by the employees
			    {
                    float r=ei/cou;
					if(r<=1.0)
				    printf("Employee Satisfaction Index = %f%%",r*100);
					else if(cou==0)
					printf("Employee Satisfaction Index = %d%%",0);
					else
					{
						printf("Employee Satisfaction Index = %f%%",(r*100)-100);
					}
				    break;
			    }
			    case '5': // Cancels an unnecessary or worked upon complaint
			    {
				    start_ptr=cancel_complaint(start_ptr);
					cou--;
				    break;
			    }
        		case '6': //Logs the admin out of the program
			    {
				    printf("You are Logged Out...!\n\n\n\n");
				    exit(0);
				    break;
			    }
				default: //Displays error if any other case is shown
				{
					printf("Wrong option, choose again!");
					break;
				}

		}//end Switch
		
		}while(menu!='6'); //end the do loop
		printf("thank you");
		return start_ptr;
	}








