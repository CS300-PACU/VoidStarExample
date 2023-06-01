/**********************************************************************
 File name:  	main.c
 Author:     	chadd williams
 Date:       	9/13/22
 Class:      	CS300
 Assignment: 	In Class Example
 Purpose:    	Void Star Example
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
  int data;
  int *pInt;
  void *pData;
} Element;

/**********************************************************************
 Function:    printMyStruct

 Description: Print the members of the struct
 
 Parameters:  sData - the struct to print
 
 Returned:    None
 *********************************************************************/
void printMyStruct(Element sData)
{
  printf("\nsData.data: %d\n", sData.data);  
  printf("*sData.pInt: %d\n", *sData.pInt);
  printf("*(int*)sData.pData: %d\n\n", *(int*)sData.pData);
}

/**********************************************************************
 Function:    fillVoidStar

 Description: Copy data into memory pointed to by a void*
 
 Parameters:  pData - the void* pointer
              size - the number of bytes to copy into memory
 
 Returned:    None
 *********************************************************************/
void fillVoidStar(void* pData , int size)
{
  // fill the memory pointed to by pData with 
  // zeros
  // memset(destination, byte, count)
  memset(pData, '\0', size);
}

/**********************************************************************
 Function:    copyDoubleToVoidStar

 Description: Copy a double into memory pointed to by a void*
 
 Parameters:  pData - the void* pointer
              data  - the double to copy into the void*
 
 Returned:    None
 *********************************************************************/
void copyDoubleToVoidStar(void* pData , double data)
{
  // memcpy(destination, source, size)
  memcpy(pData, &data, sizeof(double));
}

/**********************************************************************
 Function:    copyDoubleFromVoidStarAndPrint

 Description: Copy a double from memory pointed to by a void*
 
 Parameters:  pData - the void* pointer
 
 Returned:    None
 *********************************************************************/
void copyDoubleFromVoidStarAndPrint(void* pData)
{
  double theDouble;

  memcpy(&theDouble, pData, sizeof(double));

  printf("The Double: %f - *(double*) pVoid %f\n", theDouble, *(double*) pData);
}

/**********************************************************************
 Function:    main

 Description: Practice with void*
 
 Parameters:  None
 
 Returned:    int, exit status
 *********************************************************************/

#define SIZE 100

int main()
{
  double decimal = 0.0;
  Element sMyStruct;

  int intValue;
  void *pVoid;

  void *apData[SIZE];

  /******int*********/

  pVoid = & intValue;

  intValue = 1;

  printf("*(int*) pVoid: %d\n", *(int*) pVoid);
  printf("intValue: %d\n", intValue);

  *(int*) pVoid = 2;

  printf("*(int*) pVoid: %d\n", *(int*) pVoid);
  printf("intValue: %d\n", intValue);

  fillVoidStar(pVoid, sizeof(int));
  printf("intValue: %d\n", intValue);


  /******Double*******/

  pVoid = &decimal;

  printf("decimal: %f\n", decimal);
  copyDoubleToVoidStar(pVoid, 300.202);
  printf("decimal: %f\n", decimal);


  copyDoubleFromVoidStarAndPrint(pVoid);


  /*******Struct*******/

  sMyStruct.pData = &sMyStruct.data;
  sMyStruct.pInt = &sMyStruct.data;
  sMyStruct.data = 202;
  printMyStruct(sMyStruct);

  fillVoidStar(sMyStruct.pData, sizeof(int));

  printMyStruct(sMyStruct);

  sMyStruct.data = 222;
  printMyStruct(sMyStruct);

  pVoid = sMyStruct.pData;
  // pVoid = &sMyStruct.data; // ???
  fillVoidStar(pVoid, sizeof(int));
  printMyStruct(sMyStruct);


  /***** Array ******/
  apData[0] = malloc(sizeof(int));
  *(int*)apData[0] = 9;
  printf("%d %p\n", *(int*) apData[0], apData[0]);

  free(apData[0]);

  return EXIT_SUCCESS;
}