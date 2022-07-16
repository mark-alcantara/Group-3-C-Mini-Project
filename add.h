#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#define MAXINPUT 100
void menu();
int checkIDifExist(int prodID);

 int num,i, SN;
FILE *fp1, *fp2, *fp3;

struct date
{
int year;
int month;
int day;
};

struct prod //creating a structure to store the details
{
int prodID;
char prodName[30];
int prodQuantity;
struct date exp;
float prodPrice;
} v[200], vs[200], temp[200]; //Creating an structure to use multiple data types


void adding()
{
	int ssubMenu, SN;
	int ans;
	int pid;
	int i =1;
	char *sp;
	int flag=0;
	size_t length = 0;
	char line [100]; // size of chars in a line
	system("cls");	
	
	printf("\n[1]Enter Product Details\t\t[2]Back");
	ssubMenu = getch();
	switch (ssubMenu)
	{	
		case '1':
			system("cls");
			fp1 = fopen("Inventory_ST_NoBOM.csv", "a");
			printf("----- Enter Product Details -----\n\n");
			//ID Validation start
			do 
			{	
				flag=0;	
				int length,j;
				int foundChar = 0;											
				char input[MAXINPUT] = "";
				
				printf("Product ID: ");
				scanf ("%s", input);
				
				length = strlen (input);
				for (j=0;j<length; j++)
					{
						if (!isdigit(input[j]))
							{
								foundChar = 1;
								printf("Input contains Invalid Character. Please try again.\n");
								break;
							}
					}
									
				if(foundChar == 1) {
						continue;}
				v[i].prodID=atoi(input);
				if (v[i].prodID>0 && v[i].prodID<100000)
					{
						if(checkIDifExist(v[i].prodID)==1)	
							{
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
				int j=0;
				flag = 0;
				length = 0;		
				char userInput[MAXINPUT]="";
				fflush(stdin);
				
				printf("Product Description: ");
				fgets(userInput, MAXINPUT, stdin);
				length = strlen(userInput);
				userInput[length-1]='\0';
				
	 			if( length < 1 || length > 31) {
	 				flag=1;
					printf("Exceed description limit(Max 30 chars including spaces). Please try again\n"); //strlength
					continue;			
					}
				if( sscanf(userInput," %s", &v[i].prodName) != 1){
					flag=1;
				continue;}	
					
				strcpy(v[i].prodName,userInput );
				for (j=0;j<length; j++)
					{	
						if 	(v[i].prodName[j]==','){
								flag = 1;
								printf("Input contains Invalid Character. Please do not include a comma(,).\n");
								break;}	
							}			
			}while(flag==1);
			//Description Validation end
			
			//Quantity Validation start
			do 
			{
				flag=0;												
				int length,j; 
				int foundChar = 0;
				char input[MAXINPUT] = "";
				fflush(stdin);
				
				printf("Enter Quantity :    ");
				scanf ("%s", input);
				length = strlen (input);
			
				for (j=0;j<length; j++)
					{
						if (!isdigit(input[j]))
							{
								foundChar = 1;
								printf("Input contains Invalid character. Please try again.\n");
								break;
							}
					}
									
				if(foundChar == 1) {
						continue;
					}
				v[i].prodQuantity=atoi(input);
				if (v[i].prodQuantity>0 && v[i].prodQuantity<10000)
					{
					flag=1;	
					}
				else {
					printf("Invalid Input. Quantity must be [1-9999], Please try again.\n");
					}
			}while(flag==0);
			//Quantity Validation start
			
			//Expiry date start
			do{
				flag=0;	
				int length,j;
				int foundChar = 0; 											
				char input[MAXINPUT] = "";
				
				printf("Input Expiration date (yyyy-mm-dd): \n");
				printf("\tYear [1900+]:");
				scanf ("%s", input);
				length = strlen (input);
					for (j=0;j<length; j++)
						{
							if (!isdigit(input[j]))
								{
									foundChar = 1;
									printf("Input contains Invalid Character. Please try again.\n");
									break;
								}
						}
										
					if(foundChar == 1) {
							continue;
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
				int length,j; 
				int foundChar = 0;											
				char input[MAXINPUT] = "";
				fflush(stdin);
				
				printf("\tMonth :");
				scanf ("%s", input);
				
				length = strlen (input);
				for (j=0;j<length; j++)
					{
						if (!isdigit(input[j]))
							{
								foundChar = 1;
								printf("Input contains Invalid Character. Please try again.\n");
								break;
							}
					}
										
				if(foundChar == 1) {
						continue;
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
				int length,j; 
				int foundChar = 0; 											
				char input[MAXINPUT] = "";
				fflush(stdin);
				
				printf("\tDay :");
				scanf ("%s", input);
				length = strlen (input);
					for (j=0;j<length; j++)
						{
							if (!isdigit(input[j]))
								{
									foundChar = 1;
									printf("Input contains Invalid Character. Please try again.\n");
									break;
								}
						}
										
					if(foundChar == 1) {
						continue;
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
				int length,j; 
				int foundChar = 0;											
				char input[MAXINPUT] = "";
				fflush(stdin);
				
				printf("Enter Product Price (PHP):    ");
				scanf ("%s", input);
				length = strlen (input);
					for (j=0;j<length; j++)
						{
							if (!isdigit(input[j]))
								{	
								if 	(input[j] != '.'){
									foundChar = 1;
									printf("Input contains Invalid Character. Please try again.\n");
									break;
									}	
								}
						}				
					if(foundChar == 1) {
						continue;
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
		
		fprintf(fp1 ,"\"%d\",\"%s\",\"%d\",\"%d-%d-%d\",\"%0.2f\"\n", v[i].prodID, v[i].prodName, v[i].prodQuantity,v[i].exp.year,v[i].exp.month,v[i].exp.day,v[i].prodPrice); //this gets saved in the Inventory_ST_NoBOM.csv

			i++;
			printf("\nItem Added Successfully!\n");
			getch();
			fclose(fp1);
			
		printf("[1] Add New Item\n");
		printf("[2] Back to menu");
		fflush(stdin);
		ans = getch();
		
		switch (ans)
		{	
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
		
	case '2':
		system("cls");
		menu();
		break;	
	}		
}






int checkIDifExist(int prodID){
	char line [100];
	char *sp;
	

	FILE* filep = fopen("Inventory_ST_NoBOM.csv", "r");	
		while (fgets(line, 100, filep) !=NULL)
		{
			sp = strtok(line, ("\",\""));
			v[i].prodID = atoi(sp);
			 	
			sp = strtok(NULL,("\",\""));
			strcpy(v[i].prodName, sp);
			 	
			sp = strtok(NULL, ("\",\""));
			v[i].prodQuantity = atoi(sp);
			 	
			sp = strtok(NULL,("-"));
			v[i].exp.year= atoi(sp);
			sp = strtok(NULL,("-"));
			v[i].exp.month= atoi(sp);
			sp = strtok(NULL,("\",\""));
			v[i].exp.day= atoi(sp);
			 	
			sp = strtok(NULL,("\",\""));
			v[i].prodPrice = atof(sp);
	
			
			if (prodID==v[i].prodID)
				{
				return 1;
				
				}
				
				}
			
				fclose(filep);
				return 0;
			
}
