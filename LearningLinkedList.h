#ifndef LEARNINGLINKEDLIST_H
#define LEARNINGLINKEDLIST_H
/**************************A PLACE TO INCLUDE LIBS.**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**************************A PLACE TO DEFINE MACROS**************************/
#define _CRT_SECURE_NO_WARNINGS
#define PRIVATE static
#define PUBLIC

/**************************A PLACE TO DECLARE GLOBAL FUNCTIONS**************************/
PUBLIC void SaveLinkedList(void* voidPtr);
PUBLIC void ShowLinkedList(void* voidPtr);
PUBLIC void LinkedListUserInterfaceTestCode(void);
PUBLIC void* AddBeforeTheFirstNode(void** voidPtr, int total_amount);
PUBLIC void* AddAfterTheLastNode(void** voidPtr, int total_amount);
#endif
