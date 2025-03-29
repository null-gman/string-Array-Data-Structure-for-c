#ifndef ARRAY_OF_STRING_DATA_STRUCTURE_H_NULL
#define ARRAY_OF_STRING_DATA_STRUCTURE_H_NULL

typedef unsigned int UNINT ;

typedef  struct {
    UNINT size;
    UNINT len;
    char ** elements;
} strArr_t ;


strArr_t  createArrayOfStr();

int  pushStrArr(strArr_t * myStrArr ,const char * string);
int freeStrArr(strArr_t * myStrArr);
void printStrArr(strArr_t * myStrArr);

int removeIndexStrArr(strArr_t * myStrArr,int index);
char *  getEleStrArr(strArr_t * myStrArr , int index);
int replaceEleStrArr(strArr_t * myStrArr ,int index ,const char * newString);
int reverseEleStrArr(strArr_t * myStrArr ,int index);


#endif
