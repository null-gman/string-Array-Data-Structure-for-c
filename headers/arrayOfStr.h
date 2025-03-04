typedef unsigned int UNINT ;

typedef  struct strArr_t{
    UNINT size;
    UNINT len;
    char ** elements;
} strArr_t ;


strArr_t  createArrayOfStr();

/*
return 1 : if succed
return -1 : if no memory left
return 0 : if somsing gose wrong
*/

int  pushStrArr(strArr_t * myStrArr ,const char * string);
int freeStrArr(strArr_t * myStrArr);
void printStrArr(strArr_t * myStrArr);

int removeIndexStrArr(strArr_t * myStrArr,int index);
char *  getEleStrArr(strArr_t * myStrArr , int index);
int replaceEleStrArr(strArr_t * myStrArr ,int index ,const char * newString);
