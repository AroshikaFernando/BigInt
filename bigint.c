#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bigint.h"

/* implement the functions in *.h 
 * Given are broken code!!!!!!!
 */ 

int count = 0;                            //to get size of the linked list


//creating new_bigint function
bigint_t new_bigint(char a[]){
	
	int i ;

   	bigint_t head = NULL;                //create bigint_t type pointer called head
	bigint_t number;                     //create bigint_t type node
	
	for(i=0;i<strlen(a);i++){
		number = (bigint_t)malloc(sizeof(bigint));   //allacation memory for a number
		number->val = a[i]-'0';                      //assigning value(int value) of a to the val in number(new node) 
		number->next = head;                         //assigning head to the next in number(new node)
		head = number;                               //assigning number to the head
		count++;                                     //increase count by one 									
	}
	return number;      
}

//creating add function
int add(bigint_t* sum, bigint_t a, bigint_t b){

	int carry = 0 , temp;
	
	bigint_t head = NULL;                         //create bigint type pointer called head and assignin it as  NULL
	bigint_t temp1;                               //create bigint type temporary pointer called temp1
    
    if(a != NULL && b != NULL){                   //check whether a or b is NULL or not
		while(a!=NULL || b!=NULL){             
			
			temp1 = (bigint_t)malloc(sizeof(bigint));  //allocation memory for temporary pointer temp1
			
			if(a == NULL){                             //if size of a is less than b
				temp = b->val + carry;                 //then add only b and value of carry
				b = b->next;                           //then go to the next node of the b
			}else if(b == NULL){                       //if size of b is less than a
				temp = a->val + carry;                 //then add only a and value of carry
				a = a->next;                           //then go to the next node in a
			}else{                                     //if size of a and size of b equal
				temp = a->val + b->val + carry;        //add a , b , carry
				a = a->next;                           // then go to the next node of a
				b = b->next;                           //then go to the next node of b
			}
			
			if(temp<=9){                                //check whether sum of above is less than or equal 9
				carry = 0;                              //if it is true assigning  0 to the carry 
				temp1->val = temp;                      //then assigning temp to the val in temp1
			}else{                                      //if above condition is false
				carry = temp/10;                        //then assigning first digit to the carry
				temp1->val = temp%10;                   //and assigning second digit to the val in temp1
			}
			
			temp1->next = head;                         
			head = temp1;
			
		}
		
		if(carry>0){                                   //check whether value carry is greater than zero
			temp1 = (bigint_t)malloc(sizeof(bigint));  //if it is true then allcate memory for new temp1
			temp1->val = carry;                        //and assigning value of this carry to val in temp1 that create above
			temp1->next = head;                        
			head = temp1;
		}
		
		
		//reversing linked list
		*sum = NULL;
		while(temp1 != NULL){                           
			bigint_t current = (bigint_t)malloc(sizeof(bigint));
			current->val = temp1->val;
			current->next = *sum;
			*sum = current;
			temp1 = temp1->next;
		}
	return 0;
	}else{                                //if a and b both are null then return -1
		return -1;
	}
}


//creating show_bigint function
void show_bigint(bigint_t v) {
	
	 int arr[count] , i=0 , j;     //create array which size is value of count that define above
	while(v != NULL){
		arr[i] = v->val;           //assigning val in v to first array element
		v = v->next;               //go to next node
		i++;                       //increase value of i by one
	}
	//printing above array in reverse order
	for(j=i-1;j>=0;j--){
			printf("%d",arr[j]);
	}
	printf("\n");
}

//creating free_bigint function
void free_bigint(bigint_t intNum){
	
	bigint_t temp;
	
	while(intNum != NULL){
		temp = intNum;              //assigning first node to the temporary variable
		intNum = intNum->next;      //then go to the next node
		free(temp);                 //free temp node
	}
} 


  
