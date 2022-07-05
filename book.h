#ifndef __BOOK_H__
#define __BOOK_H__



#define TEXT_MAX 256

typedef struct{
//--------------------------------------------------------------------------
char n[TEXT_MAX];//name
char f[TEXT_MAX];//family
char p[TEXT_MAX];//phone number
}TABLE;

#define TABLE_MAX 10


extern void bk_init();
extern int  bk_print();
extern int  bk_push(TABLE*);
extern int  bk_find(TABLE*);
extern int  bk_del_ix(int);
extern int  bk_del_pm(TABLE* t);

#endif
