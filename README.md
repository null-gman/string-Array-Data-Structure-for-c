> in frist befor use library , pakg , dbms , module or prgraming lang make sure that you read the docs fist it will safe you from headet later .

# array of strings c data structer

there is no built-in array of string data stucter in c , insted we usayly used 2D string arrays or array of (char *) evrey element point to **string** in heap or stack .

i used the scond aproce with the heap memory to create that dat structer .

## **high level algorthem previwe**

![1741148662666](images/README/1741148662666.png)

## explain

- we created a pointer to pointer char varable (char **) **means** : we created a array of pointers that we dynamic allocate in heap by `malloc(*nymber of bytes that can hold a singel or (multi char*)*);` or simaler functhions .
- then each element of the array (pointer (char*)) must point to allocated memory that `memcpy(void dest, const void src, size_t n));` or `strncpy(char * dst , char * src , size_t bytes);` or simpler functhons that will copy bytes(charcters) from string(array) of memory to another string(array) of memoryarray in it , so we can push our strings into the athe rray!!.
- the data structer is a struct with :

  - ```
    typedef unsigned int UNINT ;
    typedef  struct strArr_t{
        UNINT size;/*size of memory that allocated for each string pointer(char *),
                         if it 4 then it can hold 4 elements if it max out then we realloc 4 more 
                          space for 4 more (char*) elements*/
        // (char *) that will contain the string , and (char**) that array that contaen the pointers .
        UNINT len;//length of the array

        char ** elements;/*our dobel char pointer(char**) that will contain an pointer to a strings*/
    } strArr_t ;
    ```

> sorry fo my bad explainthon i prusem you are c develpore and better than me :)

# usage

### strArr_t createArrayOfStr();

```
//on you functon declaer a variable on the stack with lib defined dataType strArr_t
strArr_t yourArray = createArrayOfStr();
```

- this functhon will inthails the struct membler with :

  - ```

    ```

  strArr_t yourArray = {
  .size = 0,
  .len = 0,
  .elements = NULL;
  };

  ```
  - and will try allocate spaces for 4 (char*) if it succed the struct will content `.size = 4;`if afaild the size member will be `.size = 0;`
  -  ```
  strArr_t yourArray = {
        .size = 4,
        .len = 0,
        .elements = NULL;
  };
  ```

> and no warrys if this functhion falid the scound fun we allocate also later or if this one falid.

- the funchon prameters : **null**
- the functhon retuns :
  - **strArr_t struct with *.size = 0 , .len = 0 , elemenst = NULL* on falid on allocate memory .
  - **strArr_t struct with *.size = 4 , .len = 0 , elemenst = NULL* on succed on allocate memory .

> !!!!!!!
>
> DO NOT EVER ASING THESE MEMBERS WITH YOUR VALUS LEAVE THE FUNCTHONS DO IT FOR YOU
>
> !!!!!!

### int freeStrArr(strArr_t * myStrArr);

- must used after  `strArr_t createArrayOfStr();` to free/deallocate the heap memory
- the functhon prameters : **pointer to yourArray**
- functhon return : **1** if succed
  > there is no other condation BTW :)
  >

> !!!!!!!
>
> after using this functhon to use the array again must use strArr_t createArrayOfStr(); again , and no user any athor functhons.
>
> !!!!!!!

### int pushStrArr(strArr_t * myStrArr , const char * string );

- push/add string to array after last element on it
- the functhon prameters :
  - **pointer to yourArray**
  - **pointer to string / string literal**
- functhon return :
  - **1** : if succed
  - **-1** : if no memory/realloc falid
  - **0 : unkown error**

### int removeIndexStrArr(strArr_t * myStrArr,int index);

- remove(free) a string from index and mover the elemnts after it to shit left by one .
- the functhon prameters :

  - **pointer to yourArray**
  - **int  number rebresent the index of the element**

    > negative index allowed -1 mean last element and so on
    >
- functhon return :

  - **1** : if succed
  - **-1 :  invalid index**

### replaceEleStrArr(strArr_t * myStrArr,int index ,  const char * string);

- free and reaplace element (char *) by index  with a new one
- the functhon prameters :

  - **pointer to yourArray**
  - **int  number rebresent the index of the element**

    > negative index allowed -1 mean last element and so on
    >
  - **pointer to a string or string literal**
- functhon return :

  - **1** : if succed
  - **-1 :  invalid index**

### char * getEleStrArr(strArr_t * myStrArr,int index);

- return a pointer to the elemnt(char**) that on the index

> negative index allowed -1 mean last element and so on

- the functhon prameters :
  - **pointer to yourArray**
  - **int  number rebresent the index of the element**

    > negative index allowed -1 mean last element and so on
    >
- functhon return :
  - **(char * ) to string : if succed**
  - **NULL :  invalid index**

### void printStrArr(strArr_t * myStrArr);

- printf all elements(char **) strings on the terminal
- the functhon prameters :

  - **pointer to yourArray
- functhon return : **null**

## project structure

arrayOfStrings/
├── bin/
      └── < your exectable prgrames like tests >
├── headers/
      └── < header files of the project includeing testing files or the data structer it self>
├── objs
      └── < the object file 'precompiled' that used as libs or to compile with your projrct files>
├── src/
      └── < the c files of the project >
├── Makefile
└── README.md

## bulid / compilathion

- just be sure install **MAKE** on your machin and run :
  - `make` on the root dirctory .
