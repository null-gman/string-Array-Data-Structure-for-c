> Before using any library, package, DBMS, module, or programming language, always read the documentation first. It will save you from potential headaches later.

# Array of strings C data structure.

There is no built-in array of string data structure in C. Instead, we usually use 2D string arrays or an array of `char *`, where each element points to a **string** in the heap or stack.

I used the second approach with heap memory to create that data structure.

## **A high-level algorithm overview**
![image](https://github.com/user-attachments/assets/742aa96a-0d5b-4d81-80b1-a1cf2591aa6b)


## Explanation

- We created a pointer to a pointer `char` variable (`char **`). This means: we created an array of pointers, which we dynamically allocate in the heap using `malloc(number of bytes that can hold a single or multiple char *);` or similar functions.

- Then, each element of the array (pointer `char *`) must point to allocated memory. This can be done using functions like `memcpy(void *dest, const void *src, size_t n);`, `strncpy(char *dst, const char *src, size_t bytes);`, or simpler functions that copy bytes (characters) from one string (or array of memory) to another string (or array of memory), so we can store our strings in the array!


- the data structure is a `struct` with :

 ```
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

> Sorry for my bad explanation! I presume you are a C developer . :)

# usage

## `strArr_t createArrayOfStr();`

- on your function, declare a variable on the stack with the library-defined data type `strArr_t` :
```
strArr_t yourArray = createArrayOfStr();
```

- This function will initialize the struct member with:

```
  strArr_t yourArray = {
  .size = 0,
  .len = 0,
  .elements = NULL;
  };
  ```

- And it will try to allocate space for 4 `char*`. If it succeeds, the struct will contain `.size = 4`; if it fails, the `.size` member will be `.size = 0`.

```
  strArr_t yourArray = {
        .size = 4,
        .len = 0,
        .elements = NULL;
  };
  ```

> And no worries if this function fails; the `int pushStrArr(strArr_t * myStrArr , const char * string );` function will allocate memory later, or if that one fails, we can handle it as well.

-   **Function parameters:** `void`
-   **Function returns:**
    -   A `strArr_t` struct with `{ .size = 0, .len = 0, .elements = NULL }` if memory allocation fails.
    -   A `strArr_t` struct with `{ .size = 4, .len = 0, .elements = NULL }` if memory allocation succeeds.

> DO NOT EVER ASING THESE MEMBERS WITH YOUR VALUS LEAVE THE function DO IT FOR YOU !!!

## `int freeStrArr(strArr_t * myStrArr);`

- **Must be used after `strArr_t createArrayOfStr();` to free/de-allocate the heap memory.**

- **Function parameters:** **pointer to `strArr_t`**
- **Function return:** **1** if successful.

	> There are no other conditions, by the way. :)

> After calling `int freeStrArr(strArr_t *myStrArr);` to free the array, you must use `strArr_t createArrayOfStr();` again to reuse the array. Do not use any other data structure functions; otherwise, memory errors may occur, potentially causing the program to crash.

## `int pushStrArr(strArr_t * myStrArr , const char * string );`

- Add or push a string to the array, appending it after the last element.
-   **Function parameters** :
	   -   **Pointer to `strArr_t`**
    -   **Pointer to a string / string literal**
-   **Function return**:
    -   **1**  : If successful
    -   **-1** : If memory allocation or `realloc` fails
    -   **0**   : Unknown error

## `int removeIndexStrArr(strArr_t * myStrArr,int index);`

- remove(free) a string from index and move the elements after it to shit-left by one .
- the function parameters :

 -   **Pointer to `strArr_t`**
  - **int  number refer to index of the element**

>  Negative indices are allowed: `-1` refers to the last element, `-2` refers to the second-to-last element, and so on.

   -   **Function return**:
		  -   **1**  : If successful
		  -   **-1** :   **invalid index**


## `replaceEleStrArr(strArr_t * myStrArr,int index ,  const char * string);`

- free and replace element (char *) by index  with a new one
- **Function pentameters** :

  - **pointer to  `strArr_t`**
  - **int  number refer to index of the element**

	>  Negative indices are allowed: `-1` refers to the last element, `-2` refers to the second-to-last element, and so on.

  - **pointer to a string or string literal**.
   -   **Function return**:
		  -   **1**  : If successful
		  -   **-1** :   **invalid index**

## `char * getEleStrArr(strArr_t * myStrArr,int index);`

- return a pointer to the element (`char**`) that on the index

> negative index allowed -1 mean last element and so on

- Function parameters :
  - **pointer to  `strArr_t`**
  - **int  number refer to index of the element**
	>  Negative indices are allowed: `-1` refers to the last element, `-2` refers to the second-to-last element, and so on.


- **Function return **:
  - **(`char * `) to string : if successful**
  - **`NULL` : invalid index**

## `void printStrArr(strArr_t * myStrArr);`

- `printf` all elements(`char **`) strings on the terminal
- the function parameters :

  - **pointer to  `strArr_t`**
- Function return : **null**

# Project Structure
```
arrayOfStrings/
├── bin/
│   └── <Executable programs, like tests>
├── headers/
│   └── <Header files for the project, including testing files or the data structure itself>
├── objs/
│   └── <Object files ('precompiled'), used as libraries or to compile with your project files>
├── src/
│   └── <C source files for the project>
│   └── myLibs/
│       └── <C source files for the libraries used for testing or other purposes>
├── Makefile
└── README.md
```
# Building/Compiling

1.  Ensure you have **make** installed.
2.  To compile `src/test.c`, run:

    ```
    make
    ```

3.  To run the `bin/test` executable, run:

    ```
    make play
    ```

4.  To run the `bin/test` with **Valgrind**, run :
    ```
    make playTest
    ```

5.  To clear/remove/delete all object files and binaries, run:

    ```
    make clean
    ```
