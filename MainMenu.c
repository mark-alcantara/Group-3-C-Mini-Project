#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Search.h"
#include "View.h"
#include "Add.h"
#include "Update.h"

void Add();
void Update();
void View();
void Search();

int main(){

int opt;
do { 
    system("CLS");
    printf("MAIN MENU\n");
    printf(" [1] Add Inventory Item \n");
    printf(" [2] Update Inventory Item \n");
    printf(" [3] View Inventory Item \n");
    printf(" [4] Search Inventory Item \n");
    printf(" [5] Exit \n \n");
    
    printf("Enter choice: \n");
    scanf("%d", &opt);
    switch (opt){
    	
    	case 1:
    		Add();
    		break;
    	case2;
    		Update();
    		break;
    	case 3:
    		View();
    		break;
    	case 4:
    		Search();
    		break;
    	case 5
    		exit(1);
    	default:
    		printf("Invalid Input. Please try again.");
    		break;
	}

} while (opt != 5);

return 0; 
}

