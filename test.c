#include <stdio.h>
#include "bigint.h" 

int main(){
	char a[] = "523";
	bigint_t num1 = new_bigint(a);          //put return value of new_bigint function to num1 variable
	show_bigint(num1);                      //print num1
	
	char b[] = "23";
	bigint_t num2 = new_bigint(b);
	show_bigint(num2);
	
	char c[] = "712";
	bigint_t num3 = new_bigint(c);
	show_bigint(num3);
	
	char d[] = "128";
	bigint_t num4 = new_bigint(d);
	show_bigint(num4);
	
	bigint_t sum = NULL;
	int return_value = add(&sum,num1,num2);                  //call add function to add num1 and num2
	show_bigint(sum);                                        //print sum
	printf("Return value is: %d\n",return_value);            //print return value
	
	add(&sum,num1,num4);
	show_bigint(sum);
	
	add(&sum,num1,num3);
	show_bigint(sum);
	
	printf("free\n");
	free_bigint(num1);               //free num1 variable 
	show_bigint(num1);               //and check whether it is free or not by printing num1
	printf("END\n");
return 0;	
}
