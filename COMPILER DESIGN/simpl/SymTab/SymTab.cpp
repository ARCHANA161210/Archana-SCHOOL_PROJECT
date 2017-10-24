// implementation for the symbol table class
#include "SymTab.h"
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b)? (a): (b))

// the hash function
int SymTab::hash(char *x){
	int sum = 0;
	for(char *p = x; *p != '\0'; p++)
		sum = (sum + *p) % capacity;
	void *z = stuff[sum];
	char *zz = keys[sum];
	if(zz == NULL) return(sum);
	if(strcmp(zz, x) == 0) return(sum);
	for(int k = (sum + 1) % capacity; k != sum; 
	  k = (k + 1) % capacity){
		void *y = stuff[k];
		char *yy = keys[k];
		if(yy == NULL) return(k);
		if(strcmp(yy, x) == 0) return(k);
	} // end of search loop
	return(-1);
} // end of hash

// the constructor
SymTab::SymTab(int c){
	stuff = new void*[capacity = c];
	keys = new char*[capacity];
	augment = max(capacity/2, 5);
	for(int i = 0; i < c; i++) keys[i] = NULL;
} // end of constructor

// add an element to the table
void SymTab::add(char* key, void *x){
	int s = hash(key);
	if(s < 0){ 
		reallocate();
		s = hash(key);
	} // end of no space
	stuff[s] = x;
	keys[s] = key;
} // end of add

// find an element
void *SymTab::get(char *key){
	int s = hash(key);
	if(s < 0) return(NULL);
	return(stuff[s]);
} // end of get

// expand the table
void SymTab::reallocate(void){
	void **ost = stuff;
	char **ok = keys;
	int ocap = capacity;
	capacity += augment;
	stuff = new void*[capacity];
	keys = new char*[capacity];
	for(int i = 0; i < capacity; i++) keys[i] = NULL;
	for(i = 0; i < ocap; i++)
		if(ost[i] != NULL){
			int s = hash(ok[i]);
			keys[s] = ok[i];
			stuff[s] = ost[i];
		} // end of actual entry
	delete ost;
	delete ok;
} // end of reallocate

// the destructor
SymTab::~SymTab(void){
	delete stuff;
	delete keys;
} // end of the destructor

