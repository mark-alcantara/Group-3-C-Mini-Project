typedef struct date {
	
	int day;
	int month;
	int year;
}date;


typedef struct item {
	int prodID;
	char prodName[30];
	int prodQuantity;
	date expiration;
	float prodPrice;	
}item;

void add() 
{
	char userInput[50];
	size_t length = 0;
	int i = 0;
	int flag = 0;
	item prod;
	char *sp; //pointer for string
	int id; 
	char line [100]; // size of chars in a line
	FILE *filep;
	filep=fopen ("Inventory.csv", "a");

	if(filep==NULL)		{	
		printf("Error Opening File.");
		exit (1);	}	
	printf("----Enter Product Detail----\n\n");
do{	    	////start ID  INPUT	
		length = 0;
		flag = 0;
				
		printf("Enter Product ID: ");
	    fgets(userInput, 50, stdin);
	    length = strlen(userInput);
			
		if( length < 1 || length > 6) 	{
			printf("Product ID must not exceed 99999. Please try again.\n"); //strlength
			continue;				}
		length--;	
		for(i = 0; i < length; ++i)	{
			if(userInput[i] < '0' || userInput[i] > '9'){
				flag = 1;
				break;	
			}
		}	
		if(flag){
			printf("Invalid Input. Please try again. \n");//character
			continue;}	
		if( sscanf(userInput, "%d", &id) != 1){
			printf("No ID Entered. Please try again. \n");//cant scanf
			continue;}	
		if(prod.prodID < 1 || prod.prodID > 100000) {
			printf("Invalid ID, Product ID must be [1-99999]. Please try again \n"); //range of ID added 7/11/2022
			continue;}
		printf("ID OK:%d\n",id);	
		
		FILE *file;
		file=fopen("Inventory.csv","r");
	
		if (file == NULL)
     	   {
			printf("Error Opening File");
			exit(1);
			}
		while (fgets(line, 100, file) !=NULL)
			{
			sp = strtok(line, ",");
			prod.prodID = atoi(sp);
			if (id==prod.prodID)
				{
					flag=2;
					printf("Item Already Exist! Please try again\n");		
				}
			}
			fclose(file);	
	}	while(((flag)||( sscanf(userInput, "%d", &prod.prodID) != 1))||( length < 1 || length > 6)||(prod.prodID<1||prod.prodID>10000));
		////end ID  INPUT
	do{		
		length = 0;
		flag = 0;
		prod.prodName[30]=0;		
	
		printf("Product Description (max 30 characters): \n");
		fgets(userInput, 50, stdin);
		length = strlen(userInput);
	 
 		if( length < 1 || length > 31) {
			printf("Exceed description limit(Max 30 chars including spaces). Please try again\n"); //strlength
			continue;			
					}
		if( sscanf(userInput, "%s", &prod.prodName) != 1){
			printf("No Description Entered. Please try again. \n");//cant scanf
			continue;}	
	}while(( length < 1 || length > 31)||( sscanf(userInput, "%s", &prod.prodName) != 1));
	//Desciption Input
	
	do{   /////Start Quantity Input
		length = 0;
		flag = 0;
		prod.prodQuantity=0;
		
		printf("Quantity: \n");
		fgets(userInput, 50, stdin);
		length = strlen(userInput);
			
		length--;	
		for(i = 0; i < length; ++i){
			if(userInput[i] < '0' || userInput[i] > '9')	{
				flag = 1;
				break;		}		
			}
		if(flag){
			printf("Invalid Input. Please enter Quantity numbers. \n");//character
			continue;	}	
		if(sscanf(userInput, "%d", &prod.prodQuantity) != 1){
			printf("No Quantity Entered. Please try again. \n");//cant scanf
			continue;}		
		if(prod.prodQuantity < 1 || prod.prodQuantity > 10000) {
			printf("Invalid Range, Quantity must be [1-9999]. Please try again. \n"); //range
			continue;}
		
		printf("QUantity OK:%d\n",prod.prodQuantity);									
	} while((flag)||( prod.prodQuantity < 1 || prod.prodQuantity > 10000)||( sscanf(userInput, "%d", &prod.prodQuantity) != 1));
	
//end Quantity Input


		
printf("Expiration date of Product: (yyyy-mm-dd) \n\n");
///start date	
	do{		//day start
		length = 0;
		flag = 0;
		prod.expiration.day=0;

		
		printf("Enter day: ");
		fgets(userInput, 50, stdin);
		length = strlen(userInput);
			
		length--;	
		for(i = 0; i < length; ++i){
		if(userInput[i] < '0' || userInput[i] > '9')
		{
			flag = 1;
			break;		}		
		}
		if(flag){
			printf("Invalid Input. Please enter numbers. \n");//character
			continue;
				}	
		if(sscanf(userInput, "%d", & prod.expiration.day) != 1){
			 prod.expiration.day== 0;
			 printf("No Expiration day (--/mm/yy)\n");
			continue;}		
		if( prod.expiration.day < 0 ||  prod.expiration.day > 31) {
			printf("Invalid Range of days. Please try again. \n"); //range
			continue;}
		
		printf("day ok:%d\n",prod.expiration.day);									
	} while((flag)||( prod.expiration.day < 0||  prod.expiration.day > 31));
///	day end
	do{	///month start
		length = 0;
		flag = 0;
		prod.expiration.month;

		
		printf("Enter Month: ");
		fgets(userInput, 50, stdin);
		length = strlen(userInput);
			
		length--;	
			for(i = 0; i < length; ++i){
			if(userInput[i] < '0' || userInput[i] > '9')
			{
				flag = 1;
				break;		}		
			}
			if(flag){
				printf("Invalid Input. Please enter numbers. \n");//character
				continue;
				}	
			if(sscanf(userInput, "%d", & prod.expiration.month) != 1){
				 	prod.expiration.month= 0;
				 	if ((prod.expiration.day==0 )&& (prod.expiration.month==0)){ 
				 	printf("No Expiration day and month (--/--/yy)\n");}
				 	else {
				 		printf("No Expiration month (dd/--/yy)\n");
					 }
				continue;}		
			if( 	prod.expiration.month < 0 || 	prod.expiration.month > 12) {
				printf("Invalid Range of months. Please try again. \n"); //range
				continue;}
		
				printf("Month OK:%d\n",	prod.expiration.month);									
	} while((flag)||( 	prod.expiration.month < 0 ||  	prod.expiration.month > 12));
	///month end
	do{			//year start
		length = 0;
		flag = 0;
		prod.expiration.year;

		printf("Enter year: ");
		fgets(userInput, 50, stdin);
		length = strlen(userInput);
			
		length--;	
		for(i = 0; i < length; ++i){
			if(userInput[i] < '0' || userInput[i] > '9')
			{
				flag = 1;
				break;		}		
			}
		if(flag){
			printf("Invalid Input. Please enter numbers. \n");//character
			continue;
			}	
		if(sscanf(userInput, "%d", &prod.expiration.year) != 1){
		 	prod.expiration.year= 0;
			if (((prod.expiration.day==0 )&& (prod.expiration.month==0))&& (prod.expiration.year==0)){ 
		 		printf("No Expiration day, month and year (--/--/--)\n");}
		 	else {
				printf("No Expiration year (dd/month/--)\n");
				 }
				continue;}		
		if( prod.expiration.year < 0 || 	prod.expiration.year > 10000) {
			printf("Invalid Range of year. Please try again. \n"); //range
			continue;}
		
		printf("Year OK:%d\n",prod.expiration.year);									
	} while((flag)||( prod.expiration.year < 0 ||  	prod.expiration.year > 10000));
	///year end

do{
	length = 0;
	flag = 0;
	prod.prodPrice;
	
	printf("Price : \n");
	fgets(userInput, 50, stdin);
	if(sscanf(userInput, "%f", &prod.prodPrice) != 1){
		printf("Invalid Input. Please try again. \n");//cant scanf
		continue;}		
	if(prod.prodPrice < 1 ||prod.prodPrice > 10000) {
		printf("Invalid Range of prices. Please try again. \n"); //range
		continue;}
		
		printf("Price OK:%.2f\n",prod.prodPrice);									
	} while((flag)||( prod.prodPrice < 1 || prod.prodPrice> 10000)||( sscanf(userInput, "%f", &prod.prodPrice) != 1));
	fprintf(filep,"%d, %s, %d, %d-%d-%d, %.2f\n", prod.prodID, prod.prodName, prod.prodQuantity,prod.expiration.year,prod.expiration.month, prod.expiration.day, prod.prodPrice);
 	printf("\n Item Added Successfully!");

fclose(filep);

}