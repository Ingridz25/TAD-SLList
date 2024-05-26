#ifndef _SLNODE_H_
#define _SLLIST_H_

typedef struct _slnode_{
    void *data;
    struct _slnode_ *next
}SLNode;

typedef struct _sllist_{
    SLNode *first;
} SLList;

SLList *sllCreate(void);
int sllDestroy(SLList *l);
int sllIsEmpty(SLList *l);
int sllNNodes(SLList *l);
int sllInsertFirst(SLList *l, void *data);
int sllInsertLast(SLList *l, void *data);
int sllInsertAfterSpecQuery(SLList *l)