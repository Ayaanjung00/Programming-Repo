#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct phone {
    char name[20];
    char num[20];
    struct phone* next;
}P;

#endif;
