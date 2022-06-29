#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include<time.h>



typedef struct Password {

    char password[35];

}Password;


 struct hashTable {
	
	int available;
	char password[35];
	
	
};

struct node
{
    char data[35];
    struct node* next;
    int index_id;
    
};

struct node* head = NULL;

int TABLESIZE1 = 1001;
int TABLESIZE2 = 10007;
int TABLESIZE3 = 100001;
int TABLESIZE4 = 1000001;
struct hashTable HASHTABLE1 [1001];
struct hashTable HASHTABLE2 [10007 ];
struct hashTable HASHTABLE3 [100001];
struct hashTable HASHTABLE4 [1000001];

Password plist1[1000];
Password plist2[10000];
Password plist3[100000];
Password plist4[1000000];



char* passw_1b[1000] ;
char* passw_10b[10000] ;
char* passw_100b[100000] ;
char* passw_1m[1000000] ;











char filePath[50] = "10-million-password-list-top/";



















int  ReadPlist(char** arr,const char* fileName){
	
	
	
	
	
	char path_filename[50];
	
	strcpy(path_filename, filePath);
	
	int sizeFileName = strlen(fileName);
	strncat(path_filename, fileName, sizeFileName);


	
	
	
	
	FILE* fp;
	fp = fopen(path_filename, "r+");
	int i = 0;


	while (!feof(fp)) {
		arr[i] = (char*)malloc(sizeof(char) * 30);

		fscanf(fp, "%s\n", arr[i]);

		i++;

	}


	int size = i;
	fclose(fp);
	return size;

	
}









void Read1(){
	FILE* fp;
    fp = fopen("10-million-password-list-top/1000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");

        return ;
    }

    int i = 0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist1[i].password);

        i++;
    }	
	
	
	
	
	
	
	
	
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
void Read2(){
	FILE* fp;
    fp = fopen("10-million-password-list-top/10000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");

        return ;
    }

    int i = 0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist2[i].password);

        i++;
    }		
	}
	
	void Read3(){
	FILE* fp;
    fp = fopen("10-million-password-list-top/100000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");

        return ;
    }

    int i = 0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist3[i].password);

        i++;
    }		
	}
	
	
	
	

void Read4(){
	FILE* fp;
	fp = fopen("10-million-password-list-top/1000000.txt", "r");
	
	
	if( fp== NULL) {
	    printf("Fýle not opened");
	
	    return ;
	}
	
	int i = 0;

	while (!feof(fp)) {
	
	    fscanf(fp, "%s\n",  plist4[i].password);
	
	    i++;
	}		
	
	
	
	
	
}









//Search Operations

int linearSearchPassword(Password arr[], int x, char* a)

{
    int i;
    int j = 0;
    for (i = 0; i < x; i++) {

        if (strcmp(arr[i].password, a) == 0) {

            return i;
       
        }

    }

    return -1;

}


//Hash Operations
//1000 passwords
void readHash1(){
	FILE* fp;
    fp = fopen("10-million-password-list-top/1000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;



	int x = 0;
	while(x<TABLESIZE1) {
		HASHTABLE1[x].available=0;
		
		x++;
	}	
	
	
	int a;
	
    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist1[i].password);
		a=hashFunc(plist1[i].password);
		
			
		i++;
	
	}
}



int hashFunc(char arr[]) {
	int x=0;	
	int val= 0;
	while(arr[x]!='\0') {
				
		val= val + arr[x]*x;
		if(val<0) 
			val=-val;
		x++;
		
	}
	
	val=val%TABLESIZE1;
	int p = 0;
	int c=0;
		
	while(HASHTABLE1[val].available !=0 ){
		
		val=val+1;
		
		if(val<0) 
			val=-val;
			
		if(val>TABLESIZE1)
			val=val%TABLESIZE1;	
		c++;
		
	}

	HASHTABLE1[val].available=1;
	strcpy(HASHTABLE1[val].password,arr);

	
	return c;
	
}
int hashsearch(char arr[]) {
	int x=0;
	
	int val= 0;

	while(arr[x]!='\0') {
		
		
		val= val + arr[x]*x;
		
	
		if(val<0) 
			val=-val;
			
	
		x++;
		
	}
	
	val=val%TABLESIZE1;
	int p = 0;
	int c=0;
	
	
	while(strcmp(HASHTABLE1[val].password,arr)!=0){
		
		val=val+1;
		
		if(val<0) 
			val=-val;
			
		if(val>TABLESIZE1)
			val=val%TABLESIZE1;
		
		
		c++;
		
	}

printf("Password : %s \t --> Collisions : %d ",arr,c);

	
	return c;
	
}

//10.000 passwords
void readHash2(){
	FILE* fp;
    fp = fopen("10-million-password-list-top/10000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;



	int x = 0;
	while(x<TABLESIZE2) {
		HASHTABLE2[x].available=0;
		
		x++;
	}	
	
	
	int a;
	
    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist2[i].password);
		a=hashFunc2(plist2[i].password);
		
			
		i++;
	
	}
}










int hashFunc2(char arr[]) {
	int x=0;	
	int val= 0;
	while(arr[x]!='\0') {
				
		val= val + arr[x]*x;
		if(val<0) 
			val=-val;
		x++;
		
	}
	
	val=val%TABLESIZE2;
	int p = 0;
	int c=0;
		int i=0;
		
	while(HASHTABLE2[val].available !=0 ){
		
		val=val+1;
		
		if(val<0) 
			val=-val;
			
		if(val>TABLESIZE2)
			val=val%TABLESIZE2;	
		c++;
		
		
		
		i++;	
	}

	HASHTABLE2[val].available=1;
	strcpy(HASHTABLE2[val].password,arr);

	
	return c;
	
}
int hashsearch2(char arr[]) {
	int x=0;
	
	int val= 0;

	while(arr[x]!='\0') {
		
		
		val= val + arr[x]*x;
		
	
		if(val<0) 
			val=-val;
			
	
		x++;
		
	}
	
	val=val%TABLESIZE2;
	int p = 0;
	int c=0;
	
	
	while(strcmp(HASHTABLE2[val].password,arr)!=0){
		
		val=val+1;
		
		if(val<0) 
			val=-val;
			
		if(val>TABLESIZE2)
			val=val%TABLESIZE2;
		
		
		c++;
		
	}

printf("Password : %s \t --> Collisions : %d ",arr,c);

	
	return c;
	
}


//Singly Linked List Operations
//1000 passwords
void insert_node1(){
    
	
	
    FILE* fp;
    fp = fopen("10-million-password-list-top/1000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;
     int pos=0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist1[i].password);
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,plist1[i].password);
	ptr->index_id =pos;
	ptr->next =NULL;
	
	
    if (ptr == NULL)
    {
        printf("\nThere is an error in Malloc!");
    }
    else{
    	
    	strcpy(ptr->data, plist1[i].password);
        
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
       
        }
        else{
           
            ptr->next = head;
            head = ptr;
        }
    }
    i++;
    pos++;
	}
		}
		
//10.000 passwords
void insert_node2(){
      
    FILE* fp;
    fp = fopen("10-million-password-list-top/10000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;
     int pos=0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist2[i].password);
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,plist2[i].password);
	ptr->index_id =pos;
	ptr->next =NULL;
	
	
	
	
    if (ptr == NULL)
    {
        printf("\nThere is an error in Malloc!");
    }
    else{
    	
    	strcpy(ptr->data, plist2[i].password);
        
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
       
        }
        else{
           
            ptr->next = head;
            head = ptr;
        }
    }
    i++;
    pos++;
}
		}


//100.000 passwords
void insert_node3(){
      
    FILE* fp;
    fp = fopen("10-million-password-list-top/100000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;
     int pos=0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist3[i].password);
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,plist3[i].password);
	ptr->index_id =pos;
	ptr->next =NULL;
	
	
	
	
    if (ptr == NULL)
    {
        printf("\nThere is an error in Malloc!");
    }
    else{
    	
    	strcpy(ptr->data, plist3[i].password);
        
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
       
        }
        else{
           
            ptr->next = head;
            head = ptr;
        }
    }
    i++;
    pos++;
}
		}	
		
//1.000.000 passwords
void insert_node4(){
      
    FILE* fp;
    fp = fopen("10-million-password-list-top/1000000.txt", "r");
    if( fp== NULL) {
        printf("Fýle not opened");


        return ;
    }
     int i = 0;
     int pos=0;

    while (!feof(fp)) {

        fscanf(fp, "%s\n",  plist4[i].password);
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,plist4[i].password);
	ptr->index_id =pos;
	ptr->next =NULL;
	

    if (ptr == NULL)
    {
        printf("\nThere is an error in Malloc!");
    }
    else{
    	
    	strcpy(ptr->data, plist4[i].password);
        
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
       
        }
        else{
           
            ptr->next = head;
            head = ptr;
        }
    }
    i++;
    pos++;
}
		}			
		
		

void display() {
	
	
	int a=0;
    struct node* ptr = head;
    if (head == NULL)
    {
        printf("\nList is empty!");
    }
    else {
        while (ptr->next !=NULL && a<3)
        {
        	printf("\t%d----> %s\n", ptr->index_id,ptr->data);
           
            ptr = ptr->next;
            a++;
        }
        
    }
    printf("\n");
}



void SLLsearch(){
	
	
	clock_t start,end; 
	
	
	
    start = clock(); 
    
    
	struct node *ptr;
	int item, flag,i=0;
	ptr= head;
	
	if(head ==  NULL){
		printf("\nEmpty List\n");
	}
	else{
		printf("Enter index which you want to search?\t");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->index_id == item){
				printf("\t%d ---> %s",item, ptr->data);
				flag=0;
				break;
				
			}
			else{
				flag=1;
			}
		i++;
			ptr= ptr->next;
		}
		if(flag==1)
		{
			printf("\nIndex is not found!!!");
		}
	}
	end=clock();
	
	
	double time_taken = ((double)(end-start)/CLOCKS_PER_SEC);
	
	
	
	
	
	printf("\n%.7f",time_taken);
	
	
	
	
	
	
	
}










void Merge(char* arr[],int low,int mid,int high) //Merging the Array Function
{
	
	
    int nL= mid-low+1;
    int nR= high-mid;
	
	
    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    
    
   

    int i;
    for(i=0;i<nL;i++)
    {
    	
    	
    	
        L[i]=malloc(sizeof(char ) *40 );
        
        strcpy(L[i],arr[low+i]);
        
        
        
        
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(char ) *40 );
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)	strcpy(arr[k++],L[i++]);
    while(j<nR)	strcpy(arr[k++],R[j++]);
	
	
	
	free(L);
	free(R);
	
	
}



void MergeSort(char* arr[],int low,int high) //Main MergeSort function
{
	
	
	
    if(low<high)
    {
   
       int mid=(low+high)/2;
    	MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
        
        
        
        
    }
}
 
 
 
void displayArray(char** arr,int x) {
	

	int size=0;
	
	while(size<x) {
		printf("%s\n",arr[size]);
		size++;
	}
	
	
	
}

















int main()
{
	
printf(" Please select the file you want to process.\n");
int fileoption;
int option;
char search[30];
int passw;
char hashval[30];
int hashp;

        printf("\n\n 1: For 1000 passwords");
        printf("\n 2: For 10.000 passwords");
        printf("\n 3: For 100.000 passwords");
        printf("\n 4: For 1.000.000 passwords");
        printf("\n\n Enter Your Option:");
        scanf("%d", &fileoption);
        
    if (fileoption==1){
    	 printf("\n1000.txt file selected.");
   do{
   	    printf("\n\n 1: Display The Sorted List");
        printf("\n 2: Searching An Password");
        printf("\n 3: Hashing The List");
        printf("\n 4: Singly Linked List");
        printf("\n 0: EXIT");
        printf("\n\n Enter Your Option:");
        scanf("%d", &option);
  switch (option)
        {
        case 1:
		
		
		
		printf("read");
		int s = ReadPlist(passw_1b,"1000.txt");
		
		printf("%d",s);
		
		int size =999;
		
		
		MergeSort(passw_1b,0,size);
		
		displayArray(passw_1b,8);
		
		
		
		
		
		
		
		
		
		
		
		
		
		break;
		 
		case 2:
			
			
			
			
			
			
			
		//Read1();
		
		
		
		//ReadPlist(&plist1);
		
		
		
		
		
		printf("Enter A Password:");
        scanf("%s",search);
        passw = linearSearchPassword(plist1, 1000,search);
            if (passw == -1){
	           printf("%s is NOT FOUND!!!",search);
           }else{
	    printf("SUCCESSFUL...\n");
	    printf("%s is present at index %d.\n", search, passw);
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
}
		 break;
		 
		case 3:
			readHash1();
		 printf("Enter A Password:");
        scanf("%s",hashval);
        hashp = linearSearchPassword(plist1,1000,hashval);
        if(hashp== -1){
        	printf("%s is NOT FOUND!!!",hashval);
		}else{
			hashsearch(hashval);
			//printf("\n%s is present at index %d.\n", hashval, hashp);
			//yerini bastýrmak lazým
			
		}
		 break;
		 
		case 4:
		 insert_node1();
                printf("\nLast 3 datas of the singly linked list\n");
                display();
                printf("\n\n");
                SLLsearch(); 
		 break;

   }
  
  
 } while (option != 0);
 
}
 else if (fileoption==2){
 	printf("\n10000.txt file selected.");
  do{
   	  printf("\n\n 1: Display The Sorted List");
        printf("\n 2: Searching An Password");
        printf("\n 3: Hashing The List");
        printf("\n 4: Singly Linked List");
        printf("\n 0: EXIT");
        printf("\n\n Enter Your Option:");
        scanf("%d", &option);
  switch (option)
        {
        case 1:
		ReadPlist(passw_1m,"1000000.txt");
		
		printf("read");
		
		int size =999999;
		
		MergeSort(passw_1m,0,size);
		
		displayArray(passw_1m,size);
		
		
		
		break;
		 
		case 2:
		Read2();
		printf("Enter A Password:");
        scanf("%s",search);
        passw = linearSearchPassword(plist2, 10000,search);
            if (passw == -1){
	           printf("%s is NOT FOUND!!!",search);
           }else{
	    printf("SUCCESSFUL...\n");
	    printf("%s is present at index %d.\n", search, passw);
}
		 break;
		 
		case 3:
		readHash2();
		
		
		
		
		
		printf("Enter A Password:");
        scanf("%s",hashval);
        hashp = linearSearchPassword(plist2,10000,hashval);
        if(hashp== -1){
        	printf("%s is NOT FOUND!!!",hashval);
		}else{
			hashsearch2(hashval);
			//printf("\n%s is present at index %d.\n", hashval, hashp);
			//yerini bastýrmak lazým
			
		}
		 break;
		 
		case 4:
		 insert_node2();
                printf("\nLast 3 datas of the singly linked list\n");
                display();
                printf("\n\n");
                //SLLsearch();  
		 break;

   }
  
  
 } while (option != 0);
  
 } else if (fileoption==3){
 	printf("\n100000.txt file selected.");

 do{
   	  printf("\n\n 1: Display The Sorted List");
        printf("\n 2: Searching An Password");
        printf("\n 3: Hashing The List");
        printf("\n 4: Singly Linked List");
        printf("\n 0: EXIT");
        printf("\n\n Enter Your Option:");
        scanf("%d", &option);
  switch (option)
        {
        case 1:
		 printf("sort mort\n");
		 break;
		 
		case 2:
			 Read3();
		printf("Enter A Password:");
        scanf("%s",search);
        passw = linearSearchPassword(plist3, 100000,search);
            if (passw == -1){
	           printf("%s is NOT FOUND!!!",search);
           }else{
	    printf("SUCCESSFUL...\n");
	    printf("%s is present at index %d.\n", search, passw);
}
		 break;
		 
		case 3:
		 printf("hash mash\n");
		 break;
		 
		case 4:
		 insert_node3();
                printf("\nLast 3 datas of the singly linked list\n");
                display();
                printf("\n\n");
                //SLLsearch();  
		 break;

   }
  
  
 } while (option != 0);
 
 } else if (fileoption==4){
 	printf("\n1000000.txt file selected.");

 do{
   	  printf("\n\n 1: Display The Sorted List");
        printf("\n 2: Searching An Password");
        printf("\n 3: Hashing The List");
        printf("\n 4: Singly Linked List");
        printf("\n 0: EXIT");
        printf("\n\n Enter Your Option:");
        scanf("%d", &option);
  switch (option)
        {
        case 1:
		 printf("sort mort\n");
		 break;
		 
		case 2:
			 Read4();
		printf("Enter A Password:");
        scanf("%s",search);
        
        
        
        passw = linearSearchPassword(plist4, 1000000,search);
        
        
        
            if (passw == -1){
	           printf("%s is NOT FOUND!!!",search);
           }else{
	    printf("SUCCESSFUL...\n");
	    printf("%s is present at index %d.\n", search, passw);
}
		 break;
		 
		case 3:
		 printf("hash mash\n");
		 break;
		 
		case 4:
		insert_node4();
                printf("\nLast 3 datas of the singly linked list\n");
                display();
                printf("\n\n");
                //SLLsearch();  
                //measure eklenecek
		 break;

   }
  
  
 } while (option != 0);
 
 } else {
  printf("You have not entered a valid number!");
 }
 return 0;


}




