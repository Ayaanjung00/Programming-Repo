#ifndef _POINT_H_

#define _POINT_H_
typedef struct phoneList {
    char name[50];
    char number[50];
    struct phoneList* ptr;
}PhoneList;

#endif
