#ifndef HinputFuns_H
#define HinputFuns_H
#include "dataTypes.h"



int input(const char *msg, char *dest, int buff);
int inputAsk(char * msg);
void inputStrNum(char *string, char *dest, int buff);
void inputStrReq(const char *string, char *dest, int buff);

int getRecord(RECORD *dest);
int getRecordReq(RECORD *dest);

#endif //HinputFuns_H
