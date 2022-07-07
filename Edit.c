#include<stdio.h>
#include<stdlib.h>	
#include <string.h>
#include "ID.h"
#include "Description.h"
#include "ExpiryDate.h"
#include "Quantity.h"
#include "Price.h"


char line[100];
char *sp;	
int ItemNo;
char ans;
int choice;

int main() {
	int prodID;
	int flag=0;
	char prodName[30];
	int quantity;
	char expDate[10];
	float prodPrice;
	
	
	
	FILE*file;
	file = fopen("Inventory.csv","r");
	if (file == NULL){
		printf("Error opening file. \n");
		exit (1);
	}
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

			}
			printf("Input Item No. : ");
			scanf("%d", &ItemNo);
			if (ItemNo == prodID){
				printf("%d %s %d %s %.02f \n\n",prodID, prodName, quantity,expDate,prodPrice);
				printf("Update Item ? Y/N : ");
				scanf("%s",&ans);
				if (ans=='Y'||'y'){
					printf("\n Update:");
					printf("\n [1] ID ");
					printf("\n [2] Description ");
					printf("\n [3] Expiry Date ");
					printf("\n [4] Quantity ");
					printf("\n [5] Price ");
					printf("\n [6] Exit Edit ");
					printf("\nChoice--> ");
					scanf("%d", &choice);
					switch(choice){
			    	   	case 1 : 
		            	    ID();
			   		   	case 2:
				    		Description();
 			  	    	case 3:
 		   		    		ExpiryDate();
 	 			      	case 4: 
 		 	        	    Quantity();
  				  		case 5: 
   	        				Price();
						case 6:
			   				break;
						default:
     	  					printf("Wrong Input please try again.");
    	       				break;
      			}	
			}
			}
	}

