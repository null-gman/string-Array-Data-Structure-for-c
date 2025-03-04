#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayOfStr.h"


/*
======on header: "arrayOfStr.h"======
typedef unsigned int UNINT ;
typedef  struct strArr_t{
    UNINT size;
    UNINT len;
    char ** elements;
} strArr_t ;
======================================
*/


strArr_t  createArrayOfStr(){
    strArr_t myStrArr = {
        .size = 0,//size of memory that allocated for echo string pointer
                  // if it 4 then it can hold 4 elements
        .len = 0,//length of the array
    };
    void * newP =  malloc(sizeof(char *) * 4);
    if (!newP) {
        return myStrArr;
    }
    myStrArr.size += 4;
    myStrArr.elements =  newP;

    return myStrArr;
}



/*
return 1 : if succed
return -1 : if no memory left
return 0 : if somsing gose wrong
*/

int  pushStrArr(strArr_t * myStrArr ,const char * string)
{

    if (myStrArr -> len >=  myStrArr -> size) {
        UNINT newSize =  myStrArr -> size + 4;
        void * newP = realloc(myStrArr->elements , sizeof(char *) * newSize);

        if (!newP) {
            return -1;
        }

        myStrArr->elements = newP;
        myStrArr->size = newSize;
    }

    const size_t StringSize = strlen(string) + 1;
    char * newP = (char *) malloc(sizeof(char) * StringSize);
    if (!newP) {
        return  -1;
    }
    strncpy(newP, string, StringSize);
    myStrArr->elements[myStrArr -> len] = newP;
    myStrArr -> len += 1;
    return 1;

}


int freeStrArr(strArr_t * myStrArr)
{
    for (UNINT index = 0; index < myStrArr->len; index++) {
        free(myStrArr->elements[index]);
        myStrArr->elements[index] = NULL;
    }
    free(myStrArr->elements);
    myStrArr->elements = NULL;
    myStrArr->len = 0;
    myStrArr->size = 0;
    return 1;
}


void printStrArr(strArr_t * myStrArr)
{
    for (UNINT index = 0; index < myStrArr->len; index++) {
        puts(myStrArr->elements[index]);
    }

}

/*
    check if indx is valid and if it negative will return from last index ,
    e.g: -1 mean last index(element) .
    return -1 if invalid index;
*/
static int getFixedIndex(strArr_t * myStrArr,int index)
{
    UNINT strArrLen = (myStrArr -> len);
    if (index < 0) {
        index = strArrLen + index;
    }
    if (index >= strArrLen || index < 0) {
        return -1;
    }

    return index;
}


/*
    #return
        -1 : if falid
        0 : invalid index
        1 : if succed
    #job
        remove element from array and reset the index
*/

int removeIndexStrArr(strArr_t * myStrArr,int index)
{
    index = getFixedIndex(myStrArr,index);
    if (index == -1) {
        return 0;
    }

    free(myStrArr->elements[index]);
    for (size_t i=index; i < myStrArr->len - 1 ; i++) {
        myStrArr->elements[i] = myStrArr->elements[i + 1] ;
    }
    myStrArr->elements[ myStrArr->len -1 ] = NULL;
    myStrArr->len--;
    return 1;
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
    index = getFixedIndex(myStrArr,index);
    if (index == -1) {
        return NULL;
    }
    return myStrArr->elements[index];
}
