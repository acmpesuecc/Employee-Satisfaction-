#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct ESI
{
    int q1;
    int q2;
    int q3;
    //

}ESI;

struct node //construct node
{
	int complaint_number;
	char customerName[20];
	char date[20];
	char x[MAX];
    struct ESI e;
	struct node *prev;
	struct node *next;
	struct node *link;

};				

typedef struct node node;

node* employee_Complaint(node* start_ptr);
node* admin_menu(node* start_ptr,float ei,int cou);
node* create_complaint(node* start_ptr);
node* cancel_complaint(node* start_ptr);
node* update_complaint(node* start_ptr);
void print_complaint();
void view_complaint(node* start_ptr);
void exit();
	
float ESIC(float ei);	




