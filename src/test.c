#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayOfStr.h"



int main(int argc , char ** argv){

   strArr_t myData = createArrayOfStr();
   pushStrArr(&myData,"hello");
   pushStrArr(&myData,"world");
   pushStrArr(&myData,"omar");

   // printStrArr(&myData);
   char * pStr = getEleStrArr(&myData ,44);
   if (pStr) {
       puts(pStr);
   }else {
       puts("invalid index");
   }

   freeStrArr(&myData);
   return  0;
}
