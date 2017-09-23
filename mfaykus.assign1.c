/*************************
*Max Faykus
*ECE 2230
*Programming Assignment 1
*mfaykus
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "guitardb.h"



int main(){
//imput cmd is the user input that is then broken up with sscanf to 
//inputwrd inputkey
char inputCmd[99];
char inputwrd[99];
int inputkey;

//these are temp values for the years string and length
//to test if they are full of number the validate
//the input
char years[100];
char stringg[100];
char pickup[100];


int len=0;
//flag is for errors
int flag=1;

//these are variables for some loops later in the code
int i=0;
int k,j;

//these are the pointers for the two structs
struct guitardb *db;
struct guitardb_guitar *gtar;
//the key for keeping track of the diffirent guitars
static int key;

//the creation of the guitardb struct
db = guitardb_create();
key=0;

printf("Please note keys start at 0\n");
	while(1){
		//takes user input from stdin 
		printf("possible commands:\n");
		printf("ADD, LOOK, LIST, DEL, QUIT\n\n");
		printf("please enter a command:\n");
		memset(inputCmd,0,sizeof(inputCmd));
		memset(inputwrd,0,sizeof(inputCmd));
		inputkey=-1;
		fgets(inputCmd,30,stdin);
		sscanf(inputCmd,"%s %d",inputwrd,&inputkey);
		if(strcmp(inputwrd,"ADD")==0){
			//creating the memory and contents of a guitar
			i=0;
			
			//here i allocate memory each time add guitar is called
			gtar = NULL;
			gtar = malloc(sizeof(struct guitardb_guitar));
			//each guitar gets a unique item key
			gtar->item_key=key;
			
			//here is the input for the guitars make
			printf("enter the guitar's make\n");
			fgets(gtar->make,15,stdin);
			//here is data validation for the make string if the user
			//inputs too many characters it will truncate and clear the buffer
			if(gtar->make[strlen(gtar->make)-1] != '\n'){
			printf("warning input overflow\n");
			scanf("%*[^\n]");
			scanf("%*c");
			}

			printf("enter the guitar's model\n");
			fgets(gtar->model,15,stdin);
			//here is data validation for the make string if the user
			//inputs too many characters it will truncate and clear the buffer
			if(gtar->model[strlen(gtar->model)-1] != '\n'){
			printf("warning input overflow\n");
			scanf("%*[^\n]");
			scanf("%*c");
			}

			printf("enter the guitar's submodel\n");
			fgets(gtar->submodel,15,stdin);
			//here is data validation for the make string if the user
			//inputs too many characters it will truncate and clear the buffer
			if(gtar->submodel[strlen(gtar->submodel)-1] != '\n'){
			printf("warning input overflow\n");
			scanf("%*[^\n]");
			scanf("%*c");
			}

			while(i==0){
				printf("enter the guitar's body type\nbody type options are:\nSB solid body\nHB hollow body\nSH semihollow\n\n");
				scanf(" %s",gtar->body_type);
				if(strcmp(gtar->body_type,"SB")==0||strcmp(gtar->body_type,"SH")==0||strcmp(gtar->body_type,"HB")==0){
					i=1;
				}
			}
			//this loop continues till the user inputs a number for the year
			i=0;
			while(i==0){
				printf("enter the guitar's year\n");
				scanf(" %9s",years);
				k=0;
				j=0;
				len = strlen(years);
				//i run through each space in the array to check for numbers
				for(k=0;k<len;k++){
					if (!isdigit(years[k])){
						j=-1;
					}
				}
				if(j==-1){
					printf("you did not enter a number\n");
				}
				if(j==0){
					//conversion to a int
					gtar->year = atoi(years);
					i=1;
				}			
			}

			scanf("%*[^\n]");
			scanf("%*c");

			printf("enter the guitar's finish\n");
			fgets(gtar->finish,15,stdin);
			//here is data validation for the make string if the user
			//inputs too many characters it will truncate and clear the buffer
			if(gtar->finish[strlen(gtar->finish)-1] != '\n'){
			printf("warning input overflow\n");
			scanf("%*[^\n]");
			scanf("%*c");
			}

			//it will loop till the user inputs a number
			i=0;
			while(i==0){
				printf("enter the guitar's strings\n");
				scanf(" %9s",stringg);
				k=0;
				j=0;
				len = strlen(stringg);
				//i run through each space in the array to check for numbers
				for(k=0;k<len;k++){
					if (!isdigit(stringg[k])){
						j=-1;
					}
				}
				if(j==-1){
					printf("you did not enter a number\n");
				}
				if(j==0){
					//conversion to a int
					gtar->strings = atoi(stringg);
					i=1;
				}			
			}
//it will loop till the user inputs a number
			i=0;
			while(i==0){
				printf("enter the guitar's pickup\n");
				scanf(" %9s",pickup);
				k=0;
				j=0;
				len = strlen(pickup);
				//i run through each space in the array to check for numbers
				for(k=0;k<len;k++){
					if (!isdigit(pickup[k])){
						j=-1;
					}
				}
				if(j==-1){
					printf("you did not enter a number\n");
				}
				if(j==0){
					//conversion  to a int
					gtar->pickups = atoi(pickup);
					i=1;
				}			
			}
//here is the validation for the guitars neck
			i=0;
			while(i==0){
				printf("\npickup type - H humbucker, C single coil, P-90,\n F Filtertron, N none\n\n");
				printf("enter the guitar's neck\n");
				scanf(" %c",&gtar->neck);
				scanf("%*[^\n]");
				scanf("%*c");
				if( (gtar->neck=='H') | (gtar->neck=='C') | (gtar->neck=='P') | (gtar->neck=='F') | (gtar->neck=='N') ){
					i=1;
				}
			}
//here is the validation for the guitars middle
			i=0;
			while(i==0){
				printf("\npickup type - H humbucker, C single coil, P-90,\n F Filtertron, N none\n\n");
				printf("enter the guitar's middle\n");
				scanf(" %c",&gtar->middle);
				scanf("%*[^\n]");
				scanf("%*c");
				if( (gtar->middle=='H') | (gtar->middle=='C') | (gtar->middle=='P') | (gtar->middle=='F') | (gtar->middle=='N') ){
					i=1;
				}
			}
//here is the validation for the guitars bridge
			i=0;
			while(i==0){
				printf("\npickup type - H humbucker, C single coil, P-90,\n F Filtertron, N none\n\n");
				printf("enter the guitar's bridge\n");
				scanf(" %c",&gtar->bridge);
				scanf("%*[^\n]");
				scanf("%*c");
				if( (gtar->bridge=='H') | (gtar->bridge=='C') | (gtar->bridge=='P') | (gtar->bridge=='F') | (gtar->bridge=='N') ){
					i=1;
				}	
			}
			//adds the now created guitar to the database with the add call
			flag = guitardb_add(db,gtar);
			
			//error check
			if(flag == -1){
				free(gtar);
				gtar = NULL;
				printf("invalid entry\n");
			}
			if(flag != -1){
				key++;
				gtar = NULL;
				printf("data added\n");
			}
		}
		if(strncmp(inputwrd,"LOOK",4)==0){
			if(inputkey!=-1 && inputkey<=key){
				//finds first guitar in database to begin the look
				gtar = guitardb_first(db);
				//error check
				if(gtar == NULL){
					printf("invalid entry\n");
				}
				while(gtar != NULL){
					//run through the guitardb array using next to look for a key
					if(gtar ->item_key != inputkey){
						gtar = guitardb_next(db);
					}

					if(gtar != NULL){
						//when a guitar is found the contents are printed
						if(gtar->item_key == inputkey){
							printf("item_key: %d\n",gtar->item_key);
							printf("make: %s\n",gtar->make);
							printf("model: %s\n",gtar->model);
							printf("submodel: %s\n",gtar->submodel);
							printf("body_type: %s\n",gtar->body_type);
							printf("year: %d\n",gtar->year);
							printf("finish: %s\n",gtar->finish);
							printf("string: %d\n",gtar->strings);
							printf("pickups: %d\n",gtar->pickups);
							printf("neck: %c\n",gtar->neck);
							printf("middle: %c\n",gtar->middle);
							printf("bridge: %c\n\n",gtar->bridge);
							gtar=NULL;
						}
					}

				}
			}
			//error check
			if(inputkey == -1 || inputkey>key){
				printf("invalid key\n");
			}	
		}
		if(strncmp(inputwrd,"DEL",3)==0){
			//removes a guitar from the array with a function call
			if(inputkey != -1){
				gtar = NULL;
				gtar = guitardb_lookup(db,inputkey);
				if(gtar != NULL){	
					flag = guitardb_delete(db,inputkey);
					if(flag != -1){
					free(gtar);						
					}

				}
			}
			//error check
			if(flag == -1)
				printf("invalid entry\n");
		}
		if(strcmp(inputwrd,"LIST")==0){
			//finding first guitar in array
			gtar = guitardb_first(db);
			//error check
			if(gtar == NULL){
				printf("database is empty\n");
			}
			//list guitars till end of the list
			while(gtar != NULL){
				printf("item_key: %d\n",gtar->item_key);
				printf("make: %s\n",gtar->make);
				printf("model: %s\n",gtar->model);
				printf("year: %d\n\n",gtar->year);
				printf("*********************************************************\n");
				gtar = guitardb_next(db);
			}


		}
		if(strcmp(inputwrd,"QUIT")==0){
			gtar = guitardb_first(db);
			//calls delete to remove the guitars from the array and free them
			while(gtar != NULL){
				flag= guitardb_delete(db,gtar->item_key);
				free(gtar);
				gtar = guitardb_first(db);
			}
			//deallocates the array
			flag = guitardb_destroy(db);
			break;
		}
		

	}
return 0;
}