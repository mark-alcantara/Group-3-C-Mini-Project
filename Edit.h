#include<stdio.h>
#include<stdlib.h>	
#include <string.h>

typedef struct product {
int prodID, quantity;
char prodName[30], expDate[10];
float prodPrice;
} prod;
void edit()
{
char line[100], *sp, ans;
int ItemNo, choice;
struct product prod;
FILE *file;
file=fopen("Inventory.csv","r");
	
if (file == NULL)
{
printf("Error Opening File");
exit(1);
}	

while (fgets(line, 55, file) !=NULL)
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

	printf("Update Item ? Y/N : ");
	scanf("%s",&ans);
	if (ans=='Y'||'y')
	{
		printf("\n Update:");
		printf("\n [1] ID ");
		printf("\n [2] Description ");
		printf("\n [3] Expiry Date ");
		printf("\n [4] Quantity ");
		printf("\n [5] Price ");
		printf("\n [6] Exit Edit ");
		printf("\nChoice--> ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : 
//				ID()
			case 2:
//				Description();
			case 3:
//				ExpiryDate();
			case 4: 
//			    Quantity();
			case 5: 
//				Price();
			case 6:
				break;
			default:
				printf("Wrong Input please try again.");
				break;
		}	
	}
}
}
void ID()
{
	product prod;
	FILE *file = fopen("Inventory.csv","rb");
	fread(&prod, sizeof(product),1,file);
	
	FILE *cntr = fopen("counter.dat","r");
	int count;
	fscanf(cntr, "%d", &count);
	fclose(cntr);

	int NprodID;
	scanf("%d", &NprodID);

	int i;
	int flag = 0;
	for (i=0;i<count;i++)
	{
		if (product.prodID == id)
		{
			flag = 1;
			product[i].prodID = NprodID;
			printf("Product ID Successfully updated");
			break
		}
	}
	if (flag == 1)
	{	
		FILE *fp2 = fopen("temp.bin","wb");
		fwrite(&product, sizeof(product), count, fp2);
		remove("Inventory.csv");
		rename("temp.bin", "Inventory.csv");
		fclose(fp2);

		char prompt;
		printf("Modify more items ? Y/N :");
		get char();
		scanf("%c", &prompt);
			if (prompt == 'Y'||prompt == 'y')
			{
				Search();
			}
			else
			{
				//main menu
			}
	} 
}

//////////////////////////////////////////////////////////////////////////////////////////////
void editDescription()
{

length = 0;
flag = 0;
prod.prodName[30]=0;		

printf("Product Description (max 30 characters): \n");
fgets(userInput, 50, stdin);
length = strlen(userInput);

if( length < 1 || length > 31) 
{
	printf("Exceed description limit(Max 30 chars including spaces). Please try again\n"); //strlength
	continue;			
}
if( sscanf(userInput, "%s", &prod.prodName) != 1)
{
	printf("No Description Entered. Please try again. \n");//cant scanf
	continue;
}	
	//	while(( length < 1 || length > 31)||( sscanf(userInput, "%s", &prod.prodName) != 1));
}
void editQuantity()
{
/////Start Quantity Input
length = 0;
flag = 0;
prod.prodQuantity=0;

printf("Quantity: \n");
fgets(userInput, 50, stdin);
length = strlen(userInput);

length--;	
for(i = 0; i < length; ++i)
{
	if(userInput[i] < '0' || userInput[i] > '9')	
		{
			flag = 1;
			break;		
		}		
}
if(flag)
	{
		printf("Invalid Input. Please enter Quantity numbers. \n");//character
		continue;	
	}	
if(sscanf(userInput, "%d", &prod.prodQuantity) != 1)
	{
		printf("No Quantity Entered. Please try again. \n");//cant scanf
		continue;
	}		
if(prod.prodQuantity < 1 || prod.prodQuantity > 10000) 
	{
		printf("Invalid Range, Quantity must be [1-9999]. Please try again. \n"); //range
		continue;
	}

printf("QUantity OK:%d\n",prod.prodQuantity);									
//	 while((flag)||( prod.prodQuantity < 1 || prod.prodQuantity > 10000)||( sscanf(userInput, "%d", &prod.prodQuantity) != 1));

}
////////////////////////////////////////////////////////////////////////////////////////////
void editExpiryDate()
{		//day start
length = 0;
flag = 0;
prod.expiration.day=0;


printf("Enter day: ");
fgets(userInput, 50, stdin);
length = strlen(userInput);

length--;	
for(i = 0; i < length; ++i)
{
	if(userInput[i] < '0' || userInput[i] > '9')
		{
			flag = 1;
			break;		
		}		
}
if(flag)
{
	printf("Invalid Input. Please enter numbers. \n");//character
	continue;
}	
if(sscanf(userInput, "%d", & prod.expiration.day) != 1)
{
	prod.expiration.day== 0;
	printf("No Expiration day (--/mm/yy)\n");
	continue;
}		
if( prod.expiration.day < 0 ||  prod.expiration.day > 31) 
{
	printf("Invalid Range of days. Please try again. \n"); //range
	continue;
}

printf("day ok:%d\n",prod.expiration.day);									
while((flag)||( prod.expiration.day < 0||  prod.expiration.day > 31));
///	day end
do{	///month start
length = 0;
flag = 0;
prod.expiration.month;


printf("Enter Month: ");
fgets(userInput, 50, stdin);
length = strlen(userInput);

length--;	
for(i = 0; i < length; ++i)
{
	if(userInput[i] < '0' || userInput[i] > '9')
	{
		flag = 1;
		break;		
	}		
}
if(flag)
	{
		printf("Invalid Input. Please enter numbers. \n");//character
		continue;
	}	
if(sscanf(userInput, "%d", & prod.expiration.month) != 1)
{
	prod.expiration.month= 0;
	if ((prod.expiration.day==0 )&& (prod.expiration.month==0))
	{ 
		printf("No Expiration day and month (--/--/yy)\n");
	}
	else 
	{
		printf("No Expiration month (dd/--/yy)\n");
	}
	continue;
}		
if( 	prod.expiration.month < 0 || 	prod.expiration.month > 12) 
	{
		printf("Invalid Range of months. Please try again. \n"); //range
		continue;
	}

	printf("Month OK:%d\n",	prod.expiration.month);									
} while((flag)||( 	prod.expiration.month < 0 ||  	prod.expiration.month > 12));
///month end
do
{			//year start
length = 0;
flag = 0;
prod.expiration.year;

printf("Enter year: ");
fgets(userInput, 50, stdin);
length = strlen(userInput);

length--;	
for(i = 0; i < length; ++i)
{
	if(userInput[i] < '0' || userInput[i] > '9')
		{
			flag = 1;
			break;		
		}		
}
if(flag)
{
	printf("Invalid Input. Please enter numbers. \n");//character
	continue;
}	
if(sscanf(userInput, "%d", &prod.expiration.year) != 1)
{
	prod.expiration.year= 0;
	if (((prod.expiration.day==0 )&& (prod.expiration.month==0))&& (prod.expiration.year==0))
		{ 
			printf("No Expiration day, month and year (--/--/--)\n");
		}
	else 
		{
			printf("No Expiration year (dd/month/--)\n");
		}
	continue;
}		
if( prod.expiration.year < 0 || 	prod.expiration.year > 10000) 
	{
		printf("Invalid Range of year. Please try again. \n"); //range
		continue;
	}

printf("Year OK:%d\n",prod.expiration.year);									
} while((flag)||( prod.expiration.year < 0 ||  	prod.expiration.year > 10000));
///year end
}
///////////////////////////////////////////////////////////////////////////////////////////////
void editPrice()
{
length = 0;
flag = 0;
prod.prodPrice;

printf("Price : \n");
fgets(userInput, 50, stdin);
if(sscanf(userInput, "%f", &prod.prodPrice) != 1)
	{
		printf("Invalid Input. Please try again. \n");//cant scanf
		continue;
	}		
if(prod.prodPrice < 1 ||prod.prodPrice > 10000) 
	{
		printf("Invalid Range of prices. Please try again. \n"); //range
		continue;
	}

printf("Price OK:%.2f\n",prod.prodPrice);									
} 
while((flag)||( prod.prodPrice < 1 || prod.prodPrice> 10000)||( sscanf(userInput, "%f", &prod.prodPrice) != 1));
fprintf(filep,"%d, %s, %d, %d-%d-%d, %.2f\n", prod.prodID, prod.prodName, prod.prodQuantity,prod.expiration.year,prod.expiration.month, prod.expiration.day, prod.prodPrice);
printf("\n Item Added Successfully!");
}
