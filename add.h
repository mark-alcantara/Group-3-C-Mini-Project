	struct date
	{
		int day;
		int month;
		int year;
    };
	struct Product
	{
	int prodID;
	char prodName[50];
	int quantity;
	struct date mfg;
	float prodPrice;
	};


void Add() {
	
	struct Product prod[100];
	int id;
	int f =0;
	int totalProducts=0;
	int i=0;
	int checkInput=0;
	
	
		printf("Enter Id: ");
	scanf("%d", &prod[totalProducts].prodID);
	fflush(stdin);
	printf("Enter Description: ");
	scanf("%d", prod[totalProducts].prodName);
	fflush(stdin);
	totalProducts++;
		
		
	FILE * fileSaveProduct;
	fileSaveProduct = fopen("Inventory.csv", "a");
	for(i=0;i<totalProducts;i++){
	fprintf(fileSaveProduct, "%d  %s %d %d %d  \n", prod[i].prodID,prod[i].prodName,prod[i].quantity,prod[i],prod[i].prodPrice);
	
		}
	fclose(fileSaveProduct);
}
