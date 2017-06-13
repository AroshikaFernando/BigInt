#include "bigint.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
  int i, f; 
  for(f = 1; f < 50; f++) {
    bigint_t a, b, fib;                
     
    // a,b,fib variable initialize as bigint_t type
    for(i=2, a = new_bigint("1") , b = new_bigint("1") , fib = new_bigint("1") ; i < f; i++) { 
      add(&fib , a , b);         //call add funtion 
      a = b; 
      b = fib; 
    }

    printf("%d the Fib is: ",f);
    show_bigint(fib);        //call show_bigint function 

  } // end for(fib=10..)

  return 0; 
}
  
  
