## Structures

A structer is a collection of related data items

## Pointers

- Pointers are address variables
- Pointer are used to access heap memory
- Pointers are used to access the resources which are outside the programs

sizeof of a pointer is independent to its data type. In modern compilers it takes 8bytes of memory.

## References

- References must be initialized while declartion only
- It is an alias (another name given to a variable)
- Useful in parameter passing
- References does not consume memory

## Pointer to a structure

- . takes higher precedence than *
  (*p).length = 10;

- malloc function returns void pointer

- struct keyword is not mandatory while declartion in cpp
  Rectangle r={10, 20};


## Arrays as parameter

- Arrays cannot be passed by value both in C and cpp
- sizeof(array) gives size of an pointer not array
