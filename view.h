//view

void View(){
	
	system("cls");
	int id;
	int i;
	int prodID;
	int flag=0;
	char prodName[30];
	int quantity;
	char expDate[10];
	float prodPrice;
	char line[100],*sp;
	int ans;

	FILE *file;
	file=fopen("adding.csv","r");
	if (file == NULL)
        {
		printf("Error Opening File");
		exit(1);
		}
			printf("\n \n");
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
printf("Press any key to go back\n");
scanf("%d",ans);

}

