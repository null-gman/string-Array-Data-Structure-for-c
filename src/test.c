#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayOfStr.h"



int main(int argc , char ** argv){

   strArr_t myData = createArrayOfStr();
   pushStrArr(&myData,"hello");
   pushStrArr(&myData,"world");
   pushStrArr(&myData,"omar");

   printStrArr(&myData);
   puts("================");
   removeIndexStrArr(&myData, -4);

   printStrArr(&myData);
   puts("================");
   pushStrArr(&myData,"c");
   printStrArr(&myData);
   freeStrArr(&myData);
   return  0;
}
