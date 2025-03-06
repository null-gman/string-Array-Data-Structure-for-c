/*FILE test.c*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
typedef unsigned int UNINT ;

typedef  struct strArr_t{
    UNINT size;
    UNINT len;
    char ** elements;
} strArr_t ;
+====================================+
and the functions declaration
*/
#include "arrayOfStr.h"




int main(void){
    /*testing the library*/

   strArr_t myData = createArrayOfStr();

   puts("================");
   puts("fun : push \"hello\",\"world\" :");
   pushStrArr(&myData,"hello");
   pushStrArr(&myData,"world");
   printStrArr(&myData);

   puts("================");
   puts("fun : remove last string :");
   removeIndexStrArr(&myData, -1);
   printStrArr(&myData);

   puts("================");
   puts("fun : push \"c\" :");
   pushStrArr(&myData,"c");
   printStrArr(&myData);

   puts("================");
   puts("fun : push \"programmers\" :");
   pushStrArr(&myData,"programmers");
   printStrArr(&myData);

   puts("================");
   puts("fun : replace \"programmers\" with \"developers\":");
   replaceEleStrArr(&myData,-1,"developers");
   printStrArr(&myData);

   puts("================");
   puts("fun : get  before last(arr.len - 2) element :");
   char * myFavLang = getEleStrArr(&myData, -2);
   puts(myFavLang);

   puts("================");
   puts("fun : printf the array with for loop:");
   for (UNINT index = 0; index < myData.len; ++index) {
       printf("[%d] \"%s\"",index,myData.elements[index]) ;
       if (index < myData.len - 1) {
           printf(" | ") ;
       }
   }
   printf("\n") ;
   puts("================");
   puts("fun : printf the array after free it");
   freeStrArr(&myData);
   printStrArr(&myData); //will print nothing

   puts("================");
   puts("fun : acces element after free the array");
   // puts(myData.elements); //Segmentation fault :)
   // puts(myData.elements[0]); //Segmentation fault :)

   puts("================");


   /*
    NOTE
        > don't do that :
            - arr.len = <your number>
            - arr.size = <your number>
            - arr.element = <your pointer>
            - arr.element[index] = <your pointer>
        > the functions will do that for you <3


   */

   return  0;
}
