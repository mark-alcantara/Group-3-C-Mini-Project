//update
int checkIDline(int n);


void updatedata()
{
	char line [100];
	int flag = 0;
	system("cls");
	char *sp;

	int i = 1, j;
	FILE *updateitRead, * updateit;



		system("cls");
	
		updateitRead = fopen("Inventory_ST_NoBOM.csv", "r");
		if (updateitRead == NULL)
			{
				printf("Error Opening File");
				exit(1);
			}
		
		while (fgets(line, 100, updateitRead) !=NULL)
			{
				sp = strtok(line, ("\",\"")  );
				temp[i].prodID = atoi(sp);
				
				sp = strtok(NULL,("\",\"") );
				strcpy(temp[i].prodName, sp);
				
				sp = strtok(NULL, ("\",\"") );
				temp[i].prodQuantity = atoi(sp);
				
				sp = strtok(NULL,("-"));
				temp[i].exp.year= atoi(sp);
				sp = strtok(NULL,("-"));
				temp[i].exp.month= atoi(sp);
				sp = strtok(NULL,("\",\""));
				temp[i].exp.day= atoi(sp);
				
				sp = strtok(NULL,("\",\"") );
				temp[i].prodPrice = atof(sp);
				i++;
			}

		printf("\nEnter the ID you want to update\n");
		int upd=0;
		int linenum=0;
		
		
		float newprodPrice;
		char newName[30];
		int newID,newqty,newyear,newmonth,newday;
		scanf("%d", &upd);

		linenum = checkIDline(upd);

		
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
								
								printf("\nEnter New Product ID : \n");
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
								printf("\n\nDescription[Accepts up to 30 Characters] : ");
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
								
								printf("\nEnter New Product Quantity :\n");
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
								
									printf("\nEnter New Product Expiration Date \n");
										printf("\nYear :");
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
								if (newyear>1899 & newyear<10000 )
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
							
										printf("\nMonth : ");
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
								if (newmonth>0 && newmonth<13)
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
							
										
										printf("\nDay :");
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
								if (newday>0 && newday<32)
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
							
										
										printf("\nEnter New Product Price :");
										scanf("%s", &input);
								length = strlen (input);
								for (j=0;j<length; j++)
									{
										if (!isdigit(input[j]))
											{
											continue;
											}
									}
									
								
									
								newprodPrice=atoi(input);
								if (newprodPrice>0 && newprodPrice<10000)
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
								updateit = fopen("Inventory_ST_NoBOM.csv", "w");	 
								fprintf(updateit, "\"%d\",\"%s\",\"%d\",\"%d-%d-%d\",\"%0.2f\"\n", temp[j].prodID,temp[j].prodName, temp[j].prodQuantity, temp[j].exp.year,temp[j].exp.month,temp[j].exp.day,temp[j].prodPrice);
								flag = 1;
							}
		if (j == linenum)
		{
		printf("Updated!\n");
		fclose(updateitRead);
		fclose(updateit);	
		}
		else if (j != linenum)
		{

			updateit = fopen("Inventory_ST_NoBOM.csv", "w");			
		for (j=1; j<i; j++)
			{

			fprintf(updateit, "\"%d\",\"%s\",\"%d\",\"%d-%d-%d\",\"%0.2f\"\n", temp[j].prodID, temp[j].prodName, temp[j].prodQuantity,temp[j].exp.year,temp[j].exp.month,temp[j].exp.day,temp[j].prodPrice);
			}
			fclose(updateitRead);
			fclose(updateit);
			printf("Nothing to update\n");
			getch();
		}
		fflush(stdin);
		int ans;
		printf("Update again ?\n [1] Yes [2] Main menu");
		ans = getch();
		if (ans == '1')
		{
			updatedata();
		}
		else if (ans == '2')
		{
			menu();
		}

		
	
}
	


int checkIDline(int n){
	char line [100];
	char *sp;
	int i=0;
	int linenum=0;
	FILE* filep = fopen("Inventory_ST_NoBOM.csv", "r");	
				while (fgets(line, 100, filep) !=NULL)
		{
			linenum+=1;
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
	
			
			if (n==v[i].prodID)
				{
							printf("Matched ");
							printf("1 result\n",linenum);
							fclose(filep);
							return linenum;
						
						}
						
						
				}

				fclose(filep);
			
}