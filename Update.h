//update
int checkIDline(int n);


void updatedata()
{
	char line [100];
	int flag;

	system("CLS");
	char *sp;

	int i = 1, j;
	FILE *updateitRead;
	FILE * updateit;
	
	
	printf("1. Update Item  2. Back\n");
	int choice;
	choice = getch();
	if (choice == '1')
	{
		system("CLS");

		updateitRead = fopen("adding.csv", "r");
		if (updateitRead == NULL)
			{
				printf("Error Opening File");
				exit(1);
			}
		
		while (fgets(line, 100, updateitRead) !=NULL)
			{
				sp = strtok(line, ",");
				temp[i].prodID = atoi(sp);
				
				sp = strtok(NULL,",");
				strcpy(temp[i].prodName, sp);
				
				sp = strtok(NULL, ",");
				temp[i].prodQuantity = atoi(sp);
				
				sp = strtok(NULL,"/");
				temp[i].exp.year= atoi(sp);
				sp = strtok(NULL,"/");
				temp[i].exp.month= atoi(sp);
				sp = strtok(NULL,",");
				temp[i].exp.day= atoi(sp);
				
				sp = strtok(NULL,"\0");
				temp[i].prodPrice = atof(sp);
				i++;
			}
			printf("\n \n \n");
			printf("                             **** INVENTORY ****\n");
			printf("----------------------------------------------------------------------------------------- \n");
			printf("    ID     |          Description            |  Quantity  |  Expiration Date |  Price \n");
			printf("----------------------------------------------------------------------------------------- \n");
			for (j = 1; j < i; j++)
				{

					printf("%d. %-8d %-33s %-13d %-1d/%d/%d\t\t%.2f\n", j, temp[j].prodID,temp[j].prodName, temp[j].prodQuantity, temp[j].exp.year,temp[j].exp.month,temp[j].exp.day,temp[j].prodPrice);
				}
		

		printf("\n\t\t\t\t\t\t\t\t  Enter the ID you want to update\n");
		int upd=0;
		int linenum=0;
		
		
		float newprodPrice;
			char newName[30];
		int newID,newqty,newyear,newmonth,newday;
		scanf("%d", &upd);

		linenum = checkIDline(upd);
		updateit = fopen("adding.csv", "w");
		
		
		for (j=1; j <i; j++)
			{
				if(j==linenum)
					{	
								
						do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
								
								printf("\n\t\t\t\t\t\t\t\t\tEnter new ID :\n");
								scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newID=atoi(input);
								if (newID>0 && newID<100000)
									{	
										if(checkIDifExist(newID)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
						
						
						
						
									do 
							{
								flag=1;												
								char input[MAXINPUT] = "";
								int length,j; 
								printf("\n\n\tDescription[Accepts up to 30 Characters]   :    ");
								fflush(stdin);
								memset(newName,0,32);
								fgets(newName,32,stdin);
								length = strlen (newName);
								newName[length-1]='\0';
							}while(flag==0);
									
									
										
										
														
										
													
										do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
								
								printf("\n\t\t\t\t\t\t\t\t\tEnter new Quantity :\n");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newqty=atoi(input);
								if (newqty>0 && newqty<100000)
									{	
										if(checkIDifExist(newqty)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
										
										
										
											do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
								
									printf("\n\t\t\t\t\t\t\t\t\tEnter new expiration Date \n");
										printf("\n\t\t\t\t\t\tYear :");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newyear=atoi(input);
								if (newyear>0 && newyear<100000)
									{	
										if(checkIDifExist(newyear)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
										
												
										
													
											do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
							
										printf("\n\t\t\t\t\t\t Month:");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newmonth=atoi(input);
								if (newmonth>0 && newmonth<100000)
									{	
										if(checkIDifExist(newmonth)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
										
				
															
											do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
							
										
										printf("\n\t\t\t\t\t\t Price :");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newday=atoi(input);
								if (newday>0 && newday<100000)
									{	
										if(checkIDifExist(newday)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
				
										
							
										
											do 
							{	
								flag=0;												
								char input[6] = "";
								int length,j; 
								int foundChar = 0;
							
										
										printf("\n\t\t\t\t\t\tPrice :");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
												foundChar = 1;
												printf("Invalid Input. Please try again.");
												break;
											}
									}
									
									if(foundChar == 1) {
										continue;
									}
									
								newprodPrice=atoi(input);
								if (newprodPrice>0 && newprodPrice<100000)
									{	
										if(checkIDifExist(newprodPrice)==1)	{
										printf("Item Already Exist");
										continue;
											}
											else{
												flag=1;
											}
									}
								else 
									{
										printf("Invalid Input. Please try again.");
									}	
							}while(flag==0);
				
										temp[j].prodID = newID;
										strcpy(temp[j].prodName,newName);
										temp[j].prodQuantity = newqty;
										temp[j].exp.day=newday;
										temp[j].exp.month=newmonth;
										temp[j].exp.year=newyear;
										temp[j].prodPrice = newprodPrice;
									} 
								fprintf(updateit, "%d, %s, %d, %d/%d/%d, %.2f\n", temp[j].prodID,temp[j].prodName, temp[j].prodQuantity, temp[j].exp.year,temp[j].exp.month,temp[j].exp.day,temp[j].prodPrice);
							}

		printf("Updated!");
	
		fclose(updateitRead);
		fclose(updateit);
		getch();
		menu();
	}
	else if(choice == '2'){
		menu();
		getch();
	}
}


int checkIDline(int n){
	char line [100];
	char *sp;
	int i=0;
	int linenum=0;
	FILE* filep = fopen("adding.csv", "r");	
				while (fgets(line, 100, filep) !=NULL)
				{
						linenum+=1;
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
			
			
					if (n == v[i].prodID)
						{
							printf("found");
							printf("Line entry: %d",linenum);
							return linenum;
						
						}
						
				}
			
				fclose(filep);
				return linenum;
			
}

