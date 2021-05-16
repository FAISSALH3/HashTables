#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define H_SIZE 23
#define MAX_Name 255

struct student{
	char name[MAX_Name];
	int key ;
};

struct student *hash_table[H_SIZE];
struct student *item;
struct student *dummyItem;

unsigned int hashFunction(int key){
	return key % H_SIZE;
}


void insert(student *p){
			
			int hashIndex =  hashFunction(p->key);
			while(hash_table[hashIndex] != NULL && hash_table[hashIndex]->key != -1 ){
				++hashIndex ; //move to the next cell
				hashIndex %= H_SIZE;
			}
			 hash_table[hashIndex] = p;
	
}

struct student * search(int key ){
	int hashIndex = hashFunction(key);
	//move in array until empty
	while(hash_table[hashIndex] != NULL){
		if(hash_table[hashIndex]->key == key){
		      return hash_table[hashIndex] ;
	     }
	     ++hashIndex ;
	     hashIndex %= H_SIZE;
	}
	return NULL;
	
}
struct student * deleting(int key){
	int hashIndex = hashFunction(key);
	//move in array until empty
	while(hash_table[hashIndex] != NULL){
		if(hash_table[hashIndex]->key == key){
			
			  struct student * temp = hash_table[hashIndex];
			  hash_table[hashIndex] = dummyItem;
	     }
	     ++hashIndex ;
	     hashIndex %= H_SIZE;
	}
	return NULL;

}

void display(){
	for(int i =0 ; i < H_SIZE ; i++){
		if(hash_table[i] != NULL){
			printf("\t%d \t%s\n" , hash_table[i] -> key , hash_table[i]->name );
		}
		else{
			printf("\tnull \tnull\n");
		}
		
	}
	
}


void data (student* data, int key, char* name){

    data->key = key;
    strcpy(data->name, name);
}

int main() {

 
	struct student*p1= (struct student*)malloc(sizeof(struct student));
	struct student*p3= (struct student*)malloc(sizeof(struct student));
	struct student*p5= (struct student*)malloc(sizeof(struct student));
	struct student*p6= (struct student*)malloc(sizeof(struct student));
			


   
   data(p1 , 19 , "John");
   data(p3 , 24 , "Jasmin");
   data(p5 , 35 , "NOOR");
   data(p6 , 90 , "matthew");
   
   


   insert(p1);
   insert(p3);
   insert(p6);
   

   display();
   item = search(19);

   if(item != NULL) {
      printf("Element found: %d\n", item->name);
   } else {
      printf("Element not found\n");
   }

   deleting(19);
   item = search(19);

   if(item != NULL) {
      printf("Element found: %d\n", item->name);
   } else {
      printf("Element not found\n");
   }
}
