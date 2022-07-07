# Llanycore
The heart of most of my libs
## Header only
This libs are only headers to save defines and types for each job
### asciidefines
Stores defines like, the diference between a upper char and lower char<br>
And much more about ASCII Table
### llanytypeslib
This header is the real core of all projects<br>
Contains the types used in all projects<br>
Redefines all types to make easyer chage later the types if is needed<br>
There is one type for each job, like, for countables non negative 'len_t':<br>
```cpp
typedef unsigned long long ll_ulonglong_t;
typedef ll_ulonglong_t ll_uint64_t;
typedef ll_uint64_t len_t;
```
### llanymathtypeslib
Stores math functions as #define and math values as PI

## Core lib
Contains all functions that are not in classes, this means, this libs are easily portable to pure C
### Memlib
This lib contains alot of funtions realted with arrays, like, move memory, find object, swap memory and move void* pointers without changing the original type
### Charslib
Contains functions that works with chars, usually ASCII<br>
Has a function to compare 2 similar chars