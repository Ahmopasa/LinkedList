/**************************A PLACE TO INCLUDE LIBS.**************************/
#define _CRT_SECURE_NO_WARNINGS
#include "LearningLinkedList.h"

/**************************A PLACE TO DEFINE MACROS**************************/
#define check_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
/********************A PLACE TO DECLARE GLOBAL VARIABLES*********************/
struct linkedList
{
	int ID;
	int day;
	int year;

	double average;
	struct linkedList* nextPtr;

	char month[15];
	char name[20];
	char surname[20];
	char city[20];
}student;

typedef struct linkedList linkedList;

typedef enum SORT
{
	EMPTY, SORT_BY_ID, SORT_BY_SCORE, SORT_BY_NAME, SORT_BY_SURNAME, SORT_BY_CITY, SORT_BY_YEAR, SORT_BY_MONTH, SORT_BY_DAY, SORT_BY_DEEPLY

}SORT;

/**************************A PLACE TO DEFINE NON-GLOBAL FUNCTIONS**************************/
// A Random Name Generator
PRIVATE const char* getName()
{
	static const char* const nameList[80] = { "AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
											"AHMET", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ELIZABETH", "AHMET", "ELLEN", "ELLEN", "ELLEN", "EPIPHANY", "EPPIE", "ETTA", "EULA", "FOREST", "FORD", "FOSTER", "FOX",
											"FOREST", "FORD", "FOSTER", "FOX", "EPIPHANY", "EPPIE", "ETTA", "EULA", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "ABRAHAM", "ABIGAIL", "ABBIE", "AHMET", "ELIZABETH", "ELLA", "EULA",
	};

	return nameList[rand() % 80];
}

// A Random Surname Generator
PRIVATE const char* getSurname()
{
	static const char* const surnameList[] = { "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON",	"GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ"	,  "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA",
											  "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS", "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "ABBESTEGE", "HARRIS", "JOHNSON", "HARRIS",
											  "WILSON", "JOHNSON", "GARCIA", "GARCIA", "JOHNSON", "RODRIGUEZ", "RODRIGUEZ", "COLEMAN", "WILSON", "JOHNSON", "ABBESTEGE", "WILSON", "JOHNSON", "ABBESTEGE",
	};

	return surnameList[rand() % 80];
}

// A Random City Name Generator
PRIVATE const char* getCity()
{
	static const char* const cityList[] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Colorado",
									 "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts",
									 "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware", "Louisiana", "Maine", "Maryland", "Massachusetts", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Connecticut", "Delaware",
									 "Florida", "Georgia", "Hawaii", "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida"
	};

	return cityList[rand() % 80];
}

// A Random Date Generator (WIP)
PRIVATE void getDate(void* head)
{
	linkedList* first = (linkedList*)head;
	int year;
	int year_leap;
	int counter_date;

	static const int daytabs[][13] = {
							{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
							{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	static const char* const pmons[] = { "","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };


	year = rand() % (2020 - 1989 + 1) + 1989;
	year_leap = check_leap(year);
	counter_date = rand() % 12 + 1;
	first->year = year;
	strcpy(first->month, pmons[counter_date]);
	first->day = daytabs[year_leap][counter_date];

}

// SORTING FUNCTION BY NAME
PRIVATE int cmp_student_name(const void* voidPtr, const void* _voidPtr)
{
	const linkedList* source1 = (const linkedList*)voidPtr;
	const linkedList* source2 = (const linkedList*)_voidPtr;
	return strcmp(source1->name, source2->name);
}

// SORTING FUNCTION BY SURNAME
PRIVATE int cmp_student_surname(const void* voidPtr, const void* _voidPtr)
{
	const linkedList* source1 = (const linkedList*)voidPtr;
	const linkedList* source2 = (const linkedList*)_voidPtr;
	return strcmp(source1->name, source2->name);
}

// SORTING FUNCTION BY ID
PRIVATE int cmp_student_ID(const void* voidPtr, const void* _voidPtr)
{
	const linkedList* source1 = (const linkedList*)voidPtr;
	const linkedList* source2 = (const linkedList*)_voidPtr;
	return (int)(source1->ID - source2->ID);
}

// SORTING FUNCTION BY AVERAGE SCORE
PRIVATE int cmp_student_Average(const void* voidPtr, const void* _voidPtr)
{
	const linkedList* source1 = (const linkedList*)voidPtr;
	const linkedList* source2 = (const linkedList*)_voidPtr;
	return (int)(source1->average - source2->average);
}

// SORTING FUNCTION DETAILED.
PRIVATE int cmp_student(const void* voidPtr, const void* _voidPtr)
{
	const linkedList* source1 = (const linkedList*)voidPtr;
	const linkedList* source2 = (const linkedList*)_voidPtr;

	int cmp_result = cmp_student_Average(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_ID(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_name(source1, source2);
	if (cmp_result)
		return cmp_result;

	cmp_result = cmp_student_surname(source1, source2);
	if (cmp_result)
		return cmp_result;

	return 0;
}

//GLOBAL SORTING FUNCTION BY ID
PRIVATE void SORT_ID(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY AVERAGE SCORE
PRIVATE void SORT_AVERAGE_SCORE(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_Average);
}

//GLOBAL SORTING FUNCTION BY NAME
PRIVATE void SORT_NAME(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_name);
}

//GLOBAL SORTING FUNCTION BY SURNAME
PRIVATE void SORT_SURNAME(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_surname);
}

//GLOBAL SORTING FUNCTION BY CITY
PRIVATE void SORT_CITY(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY YEAR
PRIVATE void SORT_YEAR(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY MONTH
PRIVATE void SORT_MONTH(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL SORTING FUNCTION BY DAY
PRIVATE void SORT_DAY(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	printf("WIP. SO, SORTING MADE BY ID");
	qsort(my_class, total_size, sizeof(*my_class), cmp_student_ID);
}

//GLOBAL FUNCTION SORTING DEEPLY
PRIVATE void SORT_DEEPLY(void* voidPtr, int total_size)
{
	linkedList* my_class = (linkedList*)voidPtr;
	qsort(my_class, total_size, sizeof(*my_class), cmp_student);
}


// LOOK-UP TABLE FOR USER SORTING DESIRE
PRIVATE SORT strToEnum(const char* index)
{

	const char SORTING_DESIRE[][8] = { "ID", "SCORE", "NAME", "SURNAME", "CITY", "YEAR", "MONTH", "DAY", "DEEPLY" };
	int databaseWish = (sizeof(SORTING_DESIRE) / sizeof(*SORTING_DESIRE));

	while (databaseWish--) {
		if (!strcmp(index, SORTING_DESIRE[databaseWish]))
			break;
	}

	if (databaseWish == 0) return SORT_BY_ID;
	if (databaseWish == 1) return SORT_BY_SCORE;
	if (databaseWish == 2) return SORT_BY_NAME;
	if (databaseWish == 3) return SORT_BY_SURNAME;
	if (databaseWish == 4) return SORT_BY_CITY;
	if (databaseWish == 5) return SORT_BY_YEAR;
	if (databaseWish == 6) return SORT_BY_MONTH;
	if (databaseWish == 7) return SORT_BY_DAY;
	if (databaseWish == 8) return SORT_BY_DEEPLY;
	else return EMPTY;
}

// A FUNCTION TO INCREASE THE LIST RIGHTWARD
PRIVATE linkedList* AppendToRight(linkedList** head)
{
	if (*head == NULL)
	{
		*head = (linkedList*)malloc(sizeof(linkedList));
		if (*head == NULL)
			exit(EXIT_FAILURE);

		(*head)->ID = rand() % 1001 + 101;
		(*head)->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy((*head)->city, getCity());
		getDate(*head);
		strcpy((*head)->name, getName());
		strcpy((*head)->surname, getSurname());
		(*head)->nextPtr = NULL;
		return *head;
	}

	else
	{
		linkedList* first = *head;
		linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
		if (newNode == NULL)
			exit(EXIT_FAILURE);

		newNode->ID = rand() % 1001 + 101;
		newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(newNode->city, getCity());
		getDate(newNode);
		strcpy(newNode->name, getName());
		strcpy(newNode->surname, getSurname());
		newNode->nextPtr = NULL;

		for (; first->nextPtr != NULL; first = first->nextPtr)
			;

		first->nextPtr = newNode;

		return *head;
	}
	return NULL;
}

// A FUNCTION TO INCREASE THE LIST LEFTWARD
PRIVATE linkedList* AppendToLeft(linkedList** head)
{
	if (*head == NULL)
	{
		*head = (linkedList*)malloc(sizeof(linkedList));
		if (*head == NULL)
			exit(EXIT_FAILURE);

		(*head)->ID = rand() % 1001 + 101;
		(*head)->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy((*head)->city, getCity());
		getDate(*head);
		strcpy((*head)->name, getName());
		strcpy((*head)->surname, getSurname());
		(*head)->nextPtr = NULL;

		return *head;
	}

	else
	{
		linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
		if (newNode == NULL)
			exit(EXIT_FAILURE);

		newNode->ID = rand() % 1001 + 101;
		newNode->average = ((double)rand() * (100. - 0.)) / (double)RAND_MAX + 0.;
		strcpy(newNode->city, getCity());
		getDate(newNode);
		strcpy(newNode->name, getName());
		strcpy(newNode->surname, getSurname());

		newNode->nextPtr = *head;

		return newNode;
	}

	return NULL;
}


/**************************A PLACE TO DECLARE GLOBAL FUNCTIONS****************************/
// Test UI Function Used for Linked List
PUBLIC void LinkedListUserInterfaceTestCode(void)
{
	srand((unsigned)time(NULL));
	void* first = NULL;
	first = AddAfterTheLastNode(&first, 2); ShowLinkedList(first);
	first = AddBeforeTheFirstNode(&first, 5); ShowLinkedList(first);
	SaveLinkedList(first);

}

//A FUNCTION TO ADD A NEW NODE AT THE START OF THE LIST
PUBLIC void* AddBeforeTheFirstNode(void** voidPtr, int total_amount)
{
	linkedList** head = (linkedList**)(voidPtr);

	fprintf(stdout, "%d new nodes will be added to the list. So, the list will enlarge leftward...\n", total_amount);

	linkedList* first = *head;
	for (int i = 0; i < total_amount; i++)
		first = AppendToLeft(&first);

	return (linkedList*)first;

}

//A FUNCTION TO ADD A NEW NODE AT THE END OF THE LIST
PUBLIC void* AddAfterTheLastNode(void** voidPtr, int total_amount)
{
	linkedList** head = (linkedList**)(voidPtr);

	fprintf(stdout, "%d new nodes will be added to the list. So, the list will enlarge rightward...\n", total_amount);

	linkedList* first = *head;
	int i;
	for (i = 0; i < total_amount; i++)
		first = AppendToRight(&first);

	return (linkedList*)first;
}

//A FUNCTION TO SHOW WHOLE LINKED LIST
PUBLIC void ShowLinkedList(void* voidPtr)
{
	linkedList* head = (linkedList*)(voidPtr);

	if (head == NULL)
		exit(EXIT_FAILURE);

	linkedList* first = head;
	int counter = 0;

	puts("*************************************************************");
	puts(" #    ID   AVERAGE NAME       SURNAME    CITY          YEAR MONTH   DAY");
	for (; first != NULL; first = first->nextPtr, counter++)
		printf("%03d.  %.4d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", counter, first->ID, first->average, first->name, first->surname, first->city, first->year, first->month, first->day);

	printf("(Total [%d] member exist.)\n\n\n", counter);
}

// A FUNCTION TO WRITE LINKED LIST TO TEXT FILE
PUBLIC void SaveLinkedList(void* voidPtr)
{
	linkedList* head = (linkedList*)(voidPtr);
	int counter = 0;
	FILE* fp = fopen("LinkedListResults.txt", "w");
	if (!fp)
	{
		exit(EXIT_FAILURE);
	}

	fprintf(fp, " #    ID   AVERAGE NAME       SURNAME    CITY          YEAR MONTH   DAY\n");

	while (head != NULL)
	{
		fprintf(fp, "%03d.  %.4d %-7.2lf %-10s %-10s %-13s %d %-7s %d\n", counter, head->ID, head->average, head->name, head->surname, head->city, head->year, head->month, head->day);	counter++;
		head = head->nextPtr;
	}

	fprintf(fp, "(Total [%d] member exist.)\n\n\n", counter);

	fclose(fp);
}