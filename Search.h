//Search

struct product {
int prodID;
char prodName[30];
int quantity;
char expDate[10];
float prodPrice;
};

void searchAgain();

void searchdata(){
struct product prod;
int id;
int i;
char ans;
int flag=0;
int length,j,foundChar;
char input[MAXINPUT] = "";
char line [100]; // size of chars in a line
char *sp;  //pointer for string

	FILE *file;
	file=fopen("Inventory_ST_NoBOM.csv","r");
	
	if (file == NULL)
        {
		printf("Error Opening File");
		exit(1);
		}	

do{
	foundChar=0;
	printf("Enter ID to search: ");
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
	}while(foundChar==1);
	
	id=atoi(input);
	if ( id>0 &&  id<100000)
	{		
		while (fgets(line, 100, file) !=NULL)
		{
			sp = strtok(line, ("\",\""));
			prod.prodID = atoi(sp);
			 	
			sp = strtok(NULL,("\",\""));
			strcpy(prod.prodName, sp);
			 	
			sp = strtok(NULL, ("\",\""));
			prod.quantity = atoi(sp);
			 	
			sp = strtok(NULL,("\",\""));
			strcpy(prod.expDate, sp);
			 	
			sp = strtok(NULL,("\",\""));
			prod.prodPrice = atof(sp);
			
			if (id==prod.prodID)
				{
					flag=2;
					printf("Item found.\n");
					printf("                             ***** INVENTORY *****\n");
					printf("---------------------------------------------------------------------------------------- \n");
					printf("    ID     |          Description            |  Quantity  |  Expiration Date |  Price \n");
					printf("    %-8d %-33s %-13d %-15s    %.02f \n",prod.prodID, prod.prodName, prod.quantity,prod.expDate,prod.prodPrice);	
					printf("---------------------------------------------------------------------------------------- \n");
					int flag=0;
						do{
			printf("Search Again? (y/n) : ");
			scanf("%s", &ans);	
				if (ans=='Y'|| ans=='y')
					{
						searchdata();
							}
				else if (ans=='N'|| ans=='n')
					{
						menu();
							}
				else{
					flag=1;
					printf("Invalid input. Please try again\n");
						}
						
		}while(flag==1);
				}
		}	
		if (flag==0)
		{
			printf ("Item not Found\n");
			do{
				printf("Search Again? (y/n) : ");
				scanf("%s", &ans);	
					if (ans=='Y'|| ans=='y')
						{
							searchdata();
								}
					else if (ans=='N'|| ans=='n')
						{
							menu();
								}
					else{
						flag=1;
						printf("Invalid input. Please try again\n");
							}
							
			}while(flag==1);
		}								 	
	}
	else if ( id<0 || id>100000)
	{
		printf("INVALID INPUT\n");	
			do{
			printf("Search Again? (y/n) : ");
			scanf("%s", &ans);	
				if (ans=='Y'|| ans=='y')
					{
						searchdata();
							}
				else if (ans=='N'|| ans=='n')
					{
						menu();
							}
				else{
					flag=1;
					printf("Invalid input. Please try again\n");
						}
						
		}while(flag==1);
	}
	
fclose(file);		
}

