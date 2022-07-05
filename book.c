


#include "defs.h"



TABLE  table[TABLE_MAX];
TABLE* ptable;



void bk_init(){
//--------------------------------------------------------------------------
TABLE* ptr = table;

for(;ptr<&table[TABLE_MAX-1];ptr++)
 {
 ptr->n[0]='\0';
 ptr->f[0]='\0';
 ptr->p[0]='\0';
 }

ptable = table;
return;
}
int bk_print(){
//--------------------------------------------------------------------------
TABLE* ptr = table;
int cnt = 0;
 
for(;ptr<&table[TABLE_MAX-1];ptr++){
  
 if((!ptr->n[0])||(!ptr->p[0])||(!ptr->f[0])){
   continue;}
cnt++;
 printf("%02d,%s,%s,%s\r\n",(int)(ptr-table),ptr->f,ptr->n,ptr->p);
 }
printf("Print result:%d\r\n",cnt);

return(cnt);
}
int bk_push(TABLE* t){
//--------------------------------------------------------------------------

*ptable = *t;
if((++ptable) >= &table[TABLE_MAX-1]){
  ptable = table;}

return(ptable-table);
}



int bk_find(TABLE* t){
//--------------------------------------------------------------------------
TABLE* ptr = table;


for(;ptr<&table[TABLE_MAX-1];ptr++){
   if(t->n[0]){
     if(strcmp(t->n,ptr->n)){
        continue;
       }
     }

   if(t->f[0]){
     if(strcmp(t->f,ptr->f)){
        continue;
       }
     }

   if(t->p[0]){
     if(strcmp(t->p,ptr->p)){
        continue;
       }
     }

    printf("%d,%s,%s,%s",ptr-table,ptr->n,ptr->f,ptr->p);
}

return(0);
}




int bk_del_ix(int ix){
//-------------------------------------------------------------------------

if(ix >= TABLE_MAX ){return(-1);}


table[ix].p[0]=0;
table[ix].n[0]=0;
table[ix].f[0]=0;
return(ix);
}
int bk_del_pm(TABLE* t){
//-------------------------------------------------------------------------
TABLE* ptr = table;
int cnt;

for(;ptr<&table[TABLE_MAX-1];ptr++){
 if(t->n[0])
  {
  if(strcmp(t->n,ptr->n) != 0){
    continue;}
  }


if(t->f[0]){
  if(strcmp(t->f,ptr->f)){
  continue;
  } 
 }

if(t->p[0]){
 if(strcmp(t->p,ptr->p) != 0) {
  continue;
  }
 }

printf(" %d,%s,%s,%s",ptr-table,ptr->n,ptr->f,ptr->p);

*(ptr->n)=0;
*(ptr->f)=0;
*(ptr->p)=0;

cnt++;
}


return(cnt);
}


