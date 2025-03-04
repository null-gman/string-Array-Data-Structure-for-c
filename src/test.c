#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayOfStr.h"



int main(int argc , char ** argv){
   strArr_t myData = createArrayOfStr();
   pushStrArr(&myData,"hello");
   pushStrArr(&myData,"world");
   pushStrArr(&myData,"omar");
   pushStrArr(&myData,"king");
   printStrArr(&myData);

   char * res = getEleStrArr(&myData,-2);
   if (res) {
       puts(res);
   }else{
       puts("invalid index");
   }

   freeStrArr(&myData);

   return  0;
}
