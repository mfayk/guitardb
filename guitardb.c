/*************************
*Max Faykus
*ECE 2230
*Programming Assignment 1
*mfaykus
**************************/

#define max_guitars 20
#include "guitardb.h"
#include <stdlib.h>

struct guitardb{
	struct guitardb_guitar *guitars[max_guitars];
	int guitarcnt;
	int curser;
};

/** Allocates and initializes a new empty guitar database.
 *
 * Returns the new database or NULL if out of memory.
 */
struct guitardb *guitardb_create(){
	//ret is the new allocated database
	struct guitardb *ret = malloc(sizeof (struct guitardb));
	//set inital values in the database struct
	ret->curser = -1;
	ret->guitarcnt = 0;
	return ret;	
}


//adds a guitar to the database
int guitardb_add(struct guitardb *db, struct guitardb_guitar *gtar){
	struct guitardb_guitar *gtar_test = guitardb_lookup(db,gtar->item_key);
	if(db->curser == -1){
		//returns -1 if guitar cant be added
		if(db->guitarcnt >= max_guitars){
			return -1;
		}
		//if it can be added counter is incrimented and it is added to array
		db->guitars[db->guitarcnt] = gtar;
		db->guitarcnt++;
		return 0;
	}
	gtar_test->item_key = -1;
	return -1;
}

//returns a guitar in the database and is determined by its key
struct guitardb_guitar *guitardb_lookup(struct guitardb *db, int key){
	int i=0;
	db->curser = 0;
	//this loops through array with some error checks before returing anything
	while(i==0 && db->guitarcnt!=0 && db->curser < db->guitarcnt){
		if(db->guitars[db->curser] != NULL){

			if(key == db->guitars[db->curser]->item_key){
				return db->guitars[db->curser];
			}
		}
		db->curser++;
	}
	//curser is set to error and NULL is returned
	db->curser = -1;
	return db->guitars[db->curser];
}


//removes a guitar from the database by its key
int guitardb_delete(struct guitardb *db,int key){
	int sortcnt =0;
	int i;
	//calles lookup to find the wanted guitar by its key
	struct guitardb_guitar *gtar = guitardb_lookup(db,key);
	//if the lookup is successful the guitar is removed and freed
	if(gtar != NULL && db->curser != -1){
			db->guitars[db->curser]=NULL;
			db->guitarcnt--;
		
		//this shifts all of the guitars to the left in the array
		for (i=0;i<=db->guitarcnt;i++){
			if(db->guitars[i] != NULL){
				db->guitars[sortcnt++] = db->guitars[i];
			}
		}
		
		
		while (sortcnt < max_guitars){
			db->guitars[sortcnt++]=NULL;
		}
	}
	//returns -1 on error
	if(db->curser == -1){
		return -1;
	}
	return 0;
}


//returns the first guitar in the database
struct guitardb_guitar *guitardb_first(struct guitardb *db){
//i didnt need to set up an error check in this function i have the list sorted
//in my delete and my add always puts it into the first slot so it will return null
//if the list is empty	
db->curser=0;
return db->guitars[0];

}

//returns the next guitar in the array keeps track by curser
struct guitardb_guitar *guitardb_next(struct guitardb *db){
	db->curser++;
	//this checks to see if the array is full or error
	if(db->guitars[db->curser] != NULL && db->curser < db->guitarcnt){
		return db->guitars[db->curser];
	}
	return NULL;
}

//deallocates the storage for the database and the guitars
int guitardb_destroy(struct guitardb *db){
	free(db);
	db = NULL;
	return 0;
}