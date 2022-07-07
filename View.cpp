#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Main.cpp"

void View(){
int id;
int i;
int prodID;
int flag=0;
char prodName[30];
int quantity;
char expDate[10];
float prodPrice;

char line [100]; // size of chars in a line
char *sp;  //pointer for string

	FILE *file;
	file=fopen("Inventory.csv","r");
	if (file == NULL)
        {
		printf("Error Opening File");
		exit(1);
		}
			printf("                             **** INVENTORY ****\n");
			printf("----------------------------------------------------------------------------------------- \n");
			printf("    ID     |          Description            |  Quantity  |  Expiration Date |  Price \n");
			printf("----------------------------------------------------------------------------------------- \n");
		 while (fgets(line, 100, file) !=NULL){
		 	
		 	sp = strtok(line, ",");
		 	prodID = atoi(sp);
		 	
		 	sp = strtok(NULL,",");
		 	strcpy(prodName, sp);
		 	
		 	sp = strtok(NULL, ",");
		 	quantity = atoi(sp);
		 	
		 	sp = strtok(NULL,",");
		 	strcpy(expDate, sp);
		 	
		 	sp = strtok(NULL,",");
		 	prodPrice = atof(sp);



			printf("    %-8d %-33s %-13d %-15s    %.02f \n",prodID, prodName, quantity,expDate,prodPrice);	
			
		}

	printf("----------------------------------------------------------------------------------------- \n");

fclose(file);		
}


