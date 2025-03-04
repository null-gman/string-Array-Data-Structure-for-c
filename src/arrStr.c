#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayOfStr.h"


/*
typedef unsigned int UNINT ;
typedef  struct strArr_t{
    unsigned int size;
    char ** elements;
} strArr_t ;
*/



strArr_t  createArrayOfStr(){
    strArr_t myStrArr = {
        .size = 0,
    };

    return myStrArr;
}

/*
return 1 : if succed
return -1 : if no memory left
return 0 : if somsing gose wrong
*/

// int  pushStrArr(strArr_t * myStrArr , char * string){
//     if (myStrArr->len == 0) {
//         myStrArr->elements = malloc(sizeof(char*));
//         if (!myStrArr->elements) {
//             return -1;
//         }
//     }else if (myStrArr->len > 0) {
//         void * newAddress = realloc(myStrArr->elements,sizeof(char*) * (myStrArr->len + 1)) ;
//         if (newAddress) {
//             myStrArr->elements = newAddress;
//         }else {
//             return -1;
//         }
//     }
//     size_t stringLen = strlen(string) + 1;
//     myStrArr->elements[ myStrArr->len] = malloc(stringLen);

//     if (!myStrArr->elements[ myStrArr->len] ) {
//         return -1;
//     }
//     strncpy(myStrArr->elements[ myStrArr->len],string,stringLen);
//     myStrArr->len++;
//     return 1;
// }

// int  pushStrArr(strArr_t * myStrArr , char * string){
//     /*

//     */

// }

int freeStrArr(strArr_t * myStrArr)
{
    for (unsigned int index = 0; index < myStrArr->len; index++) {
        free(myStrArr->elements[index]);
    }
    free(myStrArr->elements);
    return 1;
}


void printStrArr(strArr_t * myStrArr)
{
    for (unsigned int index = 0; index < myStrArr->len; index++) {
        puts(myStrArr->elements[index]);
    }

}


/*
return NULL : if invalid index
return pointer to string in strArr array that allocated in head!! : if succed

the index prameter
    if you pass a negative number the the function will return from back words of the array
    ex:
        (-1) mean last element in the array;
*/
char *  getEleStrArr(strArr_t * myStrArr , int index)
{
    unsigned int strArrLen = myStrArr -> len;

    if (index < 0) {
        int reverseIndex = strArrLen + index;
        if ( reverseIndex < 0 ) {

            return NULL;
        }
        return myStrArr->elements[reverseIndex];
    }else {
        if (strArrLen <= index) {

                return NULL;
        }
        return myStrArr->elements[index];
    }
}
