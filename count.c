#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int value;
	int key; 
	struct node* next;
};

struct node* first=NULL;
struct node* temp; 
struct node* hash[1000]; //hash table of nodes 1000 across

int count=0; 
	
int key;
 
int search(int key, unsigned long s){
	temp=(struct node*)malloc(sizeof(struct node)); 
	temp=hash[key];
	//printf("%d", temp->value); 
	while(temp!=NULL && temp->value!=s){ //first node in the key is done
		temp=temp->next;
	}
	if(temp==NULL){
	//	printf("search is fine1\n");
		return 0; 
	}
	//printf("temp: %d", temp->value);
	if(temp->value==s){
	//	printf("search is fine2\n");
	//	printf("temp: %d", temp->value); 
		return 1; 
	}
	else{
		return 0;
	}
} 

int insert(int key, int i){
	int s=search(key, i);
	if(s==1){ //duplicate found
//		printf("inserting %d\n", first->value); 
		return 1;
	}
	if(s==0){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->value=i;
		temp->key=key;
		temp->next=first;
		first=temp;
	//	printf("inserting %d\n", first->value); 
		hash[key]=first; 
		count = count + 1;
		return 0;
	}
	else{
		return 0;
	}
}


int main(int argc, char** argv){

	unsigned long dec;
	
	char hex[100]; 

	FILE* file; 

	if(argc!=2){
		exit(0);
	}

	file=fopen(argv[1], "r"); //opens the file name found in argv[1], in read mode	

	if(file!=NULL){ //if a file is inputed, the program continues
		while(fscanf(file, "%s\n", hex)!=EOF){ 	 
			//printf("%s\n", hex); 
			dec=strtoul(hex, NULL, 16);  
			//printf("%lu\n", dec); 
			key=dec%999;
		//	printf("KEY: %d\n", key);
			insert(key, dec);
		}
		printf("%d\n", count);
	}
	else{ //ends the program by printing error if a file is not included. 
		printf("error\n");
	}
return 0;
}
