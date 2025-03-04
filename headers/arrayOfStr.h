typedef unsigned int UNINT ;

typedef  struct strArr_t{
    UNINT size;
    char ** elements;
} strArr_t ;


strArr_t  createArrayOfStr();
int freeStrArr(strArr_t * myStrArr);
int  pushStrArr(strArr_t * myStrArr , char * string);
void printStrArr(strArr_t * myStrArr);
char *  getEleStrArr(strArr_t * myStrArr , int index);
