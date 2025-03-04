#include <stdio.h>
#include <string.h>


static void clearBuff()
{
    while ( getchar() != '\n' ) {
    }
}

int input(const char * msg , char * dst , size_t buffer)
{

    size_t tempBuffer = buffer + 1;
    char tempStr[tempBuffer];


    printf("%s",msg);
    if(!fgets(tempStr,tempBuffer,stdin))
    {
        return 0;
    }

    for (size_t i = 0 ; i < tempBuffer; i++) {
        if (tempStr[i] == '\n' || tempStr[i] == '\0') {
            tempStr[i] = '\0';
            break;
        }
    }

    size_t len = strlen(tempStr);

    if (len >= tempBuffer - 1) {
        // puts("overFlow"); /*used in develop and debuge*/
        clearBuff();
        dst[0] = '\0';
        return  -1;
    }

    // printf("size : %lu\n",len); /*used in develop and debuge*/

    for (size_t i=0; i < buffer; i++) {
        if (tempStr[i] == '\n' || tempStr[i] == EOF || tempStr[i] == '\0')
        {
            dst[i] = tempStr[i];
            break;
        }
        dst[i] = tempStr[i];
    }

    dst[buffer -1 ] = '\0';

    return 1;

/*
    return 0; //error has accours
    return -1; //buffer over flow
    return 1; //all good
*/
}
