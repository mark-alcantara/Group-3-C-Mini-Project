//Search

struct product {
int prodID;
char prodName[30];
int quantity;
char expDate[10];
float prodPrice;
};



void searchdata(){
char ans;
struct product prod;
int id;
int i;
int flag=0;
char line [100]; // size of chars in a line
char *sp;  //pointer for string

	FILE *file;
	file=fopen("adding.csv","r");
	
	if (file == NULL)
        {
		printf("Error Opening File");
		exit(1);
		}	
		
	printf("Enter ID to search: ");
	scanf("%d", &id);
	
	if ( id>0 &&  id<99999)
	{		
		while (fgets(line, 100, file) !=NULL)
		{
			sp = strtok(line, ",");
			prod.prodID = atoi(sp);
			 	
			sp = strtok(NULL,",");
			strcpy(prod.prodName, sp);
			 	
			sp = strtok(NULL, ",");
			prod.quantity = atoi(sp);
			 	
			sp = strtok(NULL,",");
			strcpy(prod.expDate, sp);
			 	
			sp = strtok(NULL,",");
			prod.prodPrice = atof(sp);
			
			if (id==prod.prodID)
				{
					flag=2;
					printf("Item found.");
					printf("                             ***** INVENTORY *****\n");
					printf("------------------------------------------------------------------------------- \n");
					printf("    ID     |          Description            |  Quantity  |  Expiration Date |  Price \n");
					printf("    %-8d %-33s %-13d %-15s    %.02f \n",prod.prodID, prod.prodName, prod.quantity,prod.expDate,prod.prodPrice);	
					printf("------------------------------------------------------------------------------- \n");
					printf("Search Again? (y/n) : ");
					scanf("%s", &ans);	
						if (ans=='Y'|| ans=='y')
							{
								fclose(file);
								searchdata();
							}
						else if (ans=='N'|| ans=='n')
							{
							fclose(file);
					//	main();
							}
						else{
							printf("Invalid input. Please try again\n");
							}
				}
		}
	
		if (flag==0)
		{
		printf ("Item not Found\n");
		printf("Search Again? (y/n) : ");
		scanf("%s", &ans);	
			if (ans=='Y'|| ans=='y')
			{
				fclose(file);
				searchdata();
			}
			else if (ans=='N'|| ans=='n')
			{
				fclose(file);
			//	 main();
			}
			else
			{
				printf("Invalid input. Please try again\n");
			}			
		}								 	
	}

	
	else 
	{
		printf("INVALID INPUT\n");	
		printf("Search Again? (y/n) : ");
		scanf("%s", &ans);	
		if (ans=='Y'|| ans=='y')
		{
			fclose(file);
			searchdata();
		}
		else if (ans=='N'|| ans=='n')
		{
			fclose(file);
		}
		else
		{
			printf("Invalid input. Please try again\n");
		}
	}		
fclose(file);		
}
