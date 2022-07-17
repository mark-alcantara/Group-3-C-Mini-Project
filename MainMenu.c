///Main
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "add.h"
#include "Update.h"
#include "Search.h"
#include "View.h"

#define MAXINPUT 100
void menu();
void adding();
void updatedata();
void searchdata();
void View();
int checkIDifExist(int id);
int checkIDline(int n);


int main()
{
menu();
}

void menu()
{
	int subMenu;
	do{
	system("cls"); //Menu of the program
	char subMenu;
	printf("\n \n");
			printf("****************************** INVENTORY MANAGEMENT SYSTEM ******************************\n\n");
			printf("----------------------------------------------------------------------------------------- \n");
				printf("[1]Add Inventory Item \n[2]Update Inventory Item\n[3]Search Inventory Item\n[4]View Inventory Item\n[5]Back\n");
			printf("----------------------------------------------------------------------------------------- \n");

	subMenu = getch();
	switch (subMenu)
	{
		case '1':
		adding();
		break;
		
		case '2':
		updatedata();
		break;
		
		case '3':
		searchdata();
		break;
		
		case '4':
		View();
		break;
		
		case '5':
		menu();
		break;
		
		default:

			printf("Invalid Input. Please try again.");
			sleep(1);
			menu();
		}
	}while(subMenu!=5);

}