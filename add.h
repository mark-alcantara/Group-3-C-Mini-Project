//Add
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


#define MAXINPUT 100


void menu();
int checkIDifExist(int prodID);



int num,i, SN;
FILE *fp1, *fp2, *fp3;

struct date
{
int day;
int month;
int year;
};

struct prod //creating a structure to store the details
{
int SN;
int prodID;
char prodName[30];
int prodQuantity;
struct date exp;
float prodPrice;
} v[200], vs[200], temp[200]; //Creating an structure to use multiple data types





void adding()
{
	int ssubMenu, SN;
	char yesno;
	system("cls");
	int flag=0;
	int pid;
	int i =1;
	char *sp;
	size_t length = 0;
	char line [100]; // size of chars in a line
	//	drawBorder(5, 3, 100, 24);
	//	gotoxy(30, 5);
	printf("1.Enter Product Details\t\t2.Back");
	ssubMenu = getch();
	switch (ssubMenu)
	{
		
		case '1':
			system("cls");
			//	drawBorder(5, 1, 100, 60);
			//	gotoxy(0, 0);
			//	gotoxy(30, 3);
			//	printf("Enter the how many items you want to add: ");
			//	scanf("%d", &num);
			fp1 = fopen("adding.csv", "a"); //main data base for the prodetables bought by the keeper
			//	for (i = 1; i <= num; i++)			//this creates a loop of this block of code until the given condition matches
			//	{
			//	printf("\n\tP.N. %d", i);
			printf("----- Enter Product Details -----\n");
			//ID Validation start
			do 
			{	
				flag=0;												
				char input[MAXINPUT] = "";
				int length,j; 
				printf("Enter Product ID: ");
				scanf ("%s", input);
				length = strlen (input);
				for (j=0;j<length; j++)
					{
						if (!isdigit(input[j]))
							{
								continue;
							}
					}
				v[i].prodID=atoi(input);
				if (v[i].prodID>0 && v[i].prodID<100000)
					{
					
						
						if(checkIDifExist(v[i].prodID)==1)	{
						printf("Item Already Exist! Please try again\n");
						continue;
							}
							else{
								flag=1;
							}
					}
				else 
					{
						printf("Invalid ID, Product ID must be [1-99999]. Please try again\n");
					}
	
	
			}while(flag==0);
			//ID Validation end
			//Description Validation start
			
			
			
			do 
			{
				flag=1;												
				char input[MAXINPUT] = "";
				int length,j; 
				printf("Enter Product Description (max 30 characters) :    ");
				fflush(stdin);
				//	scanf(" %s", &v[i].prodName);
				memset(v[i].prodName,0,32);
				fgets(v[i].prodName,32,stdin);
				length = strlen (v[i].prodName);
				v[i].prodName[length-1]='\0';
			}while(flag==0);
			//Description Validation end
			//Quantity Validation start
			do 
			{
				flag=0;												
				
				int length,j; 
				char input[MAXINPUT] = "";
				printf("Enter Quantity :    ");
				
				//			scanf(" %d", &v[i].prodQuantity);
				//			if (v[i].prodQuantity>0 && v[i].prodQuantity<10000){
				//				flag=1;	
				//			}
				//			else {
				//				printf("Invalid Input. Please try again.");
				//			}
				fflush(stdin);
				scanf ("%s", input);
				length = strlen (input);
				for (j=0;j<length; j++)
				{
				if (!isdigit(input[j]))
				{
				continue;
				}
				}
				v[i].prodQuantity=atoi(input);
				if (v[i].prodQuantity>0 && v[i].prodQuantity<10000)
				{
				flag=1;	
				}
				else {
				printf("Invalid Input. Quantity must be [1-9999], Please try again\n");
				}
			}while(flag==0);
			//Quantity Validation start
			//Expiry date start
			do{
			flag=0;												
			char input[MAXINPUT] = "";
			int length,j; 
			printf("Input Expiration date (yyyy-mm-dd): \n");
			printf("\tYear [1900+]:");
			scanf ("%s", input);
			length = strlen (input);
			for (j=0;j<length; j++)
			{
			if (!isdigit(input[j]))
			{
			continue;
			}
			}
			v[i].exp.year=atoi(input);
			if (v[i].exp.year>1899 && v[i].exp.year<10000 )
			{
			flag=1;	
			}
			else {
			printf("Invalid Year, Year must be [1900 - 9999]. Please try again.\n");
			}
			}while(flag==0);
			
			do{	
			flag=0;												
			char input[MAXINPUT] = "";
			int length,j; 
			printf("\tMonth :");
			fflush(stdin);
			scanf ("%s", input);
			length = strlen (input);
			for (j=0;j<length; j++)
			{
			if (!isdigit(input[j]))
			{
			continue;
			}
			}
			v[i].exp.month=atoi(input);
			if (v[i].exp.month>0 && v[i].exp.month<13)
			{
			flag=1;	
			}
			else {
			printf("Invalid Month, Month must be [01 - 12]. Please try again.\n");
			}
			}while(flag==0);
			
			
			do{
			flag=0;												
			char input[MAXINPUT] = "";
			int length,j; 
			printf("\tDay :");
			fflush(stdin);
			scanf ("%s", input);
			length = strlen (input);
			for (j=0;j<length; j++)
			{
			if (!isdigit(input[j]))
			{
			continue;
			}
			}
			v[i].exp.day=atoi(input);
			if (v[i].exp.day>0 && v[i].exp.day<32)
			{
			flag=1;	
			}
			else {
			printf("Invalid Day, Day must be [01 - 31]. Please try again.\n");
			}
			}while(flag==0);
			//Expiry date Validation end
			//Price Validation start
			do{	
			flag=0;												
			char input[MAXINPUT] = "";
			int length,j; 
			printf("Enter Product Price (PHP):    ");
			fflush(stdin);
			scanf ("%s", input);
			length = strlen (input);
			for (j=0;j<length; j++)
			{
			if (!isdigit(input[j]))
			{
			continue;
			}
			}
			v[i].prodPrice=atof(input);
			if (v[i].prodPrice>0 && v[i].prodPrice<10000)
			{
			flag=1;	
			}
			else {
			printf("Invalid Input. Product Price must be [1-9999], Please try again\n");
			}
			}while(flag==0);
			printf("%d, %s, %d, %d-%d-%d, %0.2f\n",v[i].prodID, v[i].prodName, v[i].prodQuantity,v[i].exp.year,v[i].exp.month,v[i].exp.day,v[i].prodPrice);
			
		fprintf(fp1, "%d, %s, %d, %d-%d-%d, %0.2f\n",v[i].prodID, v[i].prodName, v[i].prodQuantity,v[i].exp.year,v[i].exp.month,v[i].exp.day,v[i].prodPrice); //this gets saved in the adding.csv
	
		
			//	}
			i++;
			printf("\nItem Added Successfully!\n");
			getch();
			fclose(fp1);
			
		printf("[1] Add New Item\n");
		printf("[2] Back to menu");
		fflush(stdin);
		yesno = getch();
	switch (yesno){
		
		case '1':
		
		system("cls");
		printf("go back to main");
		adding();
		break;
		
		case '2':
		
		system("cls");
		menu();
		break;
		
		default:
			exit(1);
	}
		
			//menu();

		case '2':
		
		system("cls");
		menu();
		break;
		
	
	
}
	
}






int checkIDifExist(int prodID){
	char line [100];
	char *sp;
	FILE* filep = fopen("adding.csv", "r");	
				while (fgets(line, 100, fp1) !=NULL)
				{
				sp = strtok(line, ",");
				v[i].prodID = atoi(sp);
				
				sp = strtok(NULL,",");
				strcpy(v[i].prodName, sp);
				
				sp = strtok(NULL, ",");
				v[i].prodQuantity = atoi(sp);
				
				sp = strtok(NULL,"/");
				v[i].exp.year= atoi(sp);
				sp = strtok(NULL,"/");
				v[i].exp.month= atoi(sp);
				sp = strtok(NULL,",");
				v[i].exp.day= atoi(sp);
				
				sp = strtok(NULL,"\0");
				v[i].prodPrice = atof(sp);
				
				if (prodID== v[i].prodID)
				{
				printf("found");
				return 1;
				
				}
					i++;
				}
			
				fclose(filep);
				return 0;
			
}

