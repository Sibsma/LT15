#include "defs.h"


#define CMD_WAIT  0
#define CMD_PUSH  1
#define CMD_FIND  2
#define CMD_DELT  3
#define CMD_SAVE  4

#define TEXT_MAIN "Phone book v.1.0.0\r\n 1. PRINT\r\n 2. PUSH\r\n 3. DELETE\r\n 4. FIND\r\n 5. EXIT\r\n"
#define TEXT_DELT "Delete:\r\n 1. ALL\r\n 2. BY INDEX\r\n 3. BY NAME\r\n ESC. BACK\r\n"
#define TEXT_FIND "Find:\r\n (ESC - back Enter - skip) input first name:"
#define TEXT_PUSH "Push:\r\n (ESC - back) input first name:"
#define TEXT_PRNT "Print:\r\n (ESC - back)"
#define TEXT_EXIT "Exit..."


#define TEXT_ERROR "error, unknown cmd\r\n"

int state=CMD_WAIT;
TABLE tmp;


void cmd_init(void){
//--------------------------------------------------------------------------
printf(TEXT_MAIN);
}
int cmd_check(char* cmd){
while((*cmd != '\n') && (*cmd)){
cmd++;}
*cmd=0;
}
int cmd_wait(char* cmd){
//--------------------------------------------------------------------------

switch(cmd[0]){
  case '1':bk_print();
	   printf(TEXT_MAIN);
	   return(CMD_WAIT);  

  case '2':printf(TEXT_PUSH);
	   memset(&tmp,0x00,sizeof(TABLE));
	   return(CMD_PUSH);

  case '3':printf(TEXT_DELT);
	   memset(&tmp,0x00,sizeof(TABLE));
	   return(CMD_DELT);

  case '4':printf(TEXT_FIND);
	   memset(&tmp,0x00,sizeof(TABLE));
	   return(CMD_FIND);

  case '5':printf(TEXT_EXIT);
	   return(-1);

  }
return(CMD_WAIT);
}
int cmd_delt(char* cmd){
//--------------------------------------------------------------------------
static int s;
static int ix=0;

if(*cmd == 27){
  printf(TEXT_MAIN);
  return(CMD_WAIT);
  }


switch(s){
 case 0: switch(*cmd){
	 case '1':printf(" (ESC - back) delete all item (y/n)?");
		  s++;
	 break;
	 case '2':printf(" (ESC - back) input item index:"); 
		  s=2;
	 break;
	 case '3':printf(" (ESC - back Enter - skip) input first name:"); 
		  s=4;
	 break;
	 default :    break;
	 }
 break;
 case 1: if(*cmd == 'n') {
	  s=0;
	  printf(TEXT_DELT);
	  break;
	  }


	 if(*cmd != 'y'){
	   break;
	   }
 

	 bk_init();
	 printf(" all items delete success...\r\n");
	 s=0; printf(TEXT_DELT);
 break;
 case 2: ix = atoi(cmd);

	 printf(" (ESC - back) delete item[%d] (y/n)?",ix);
	 s++;
 break;
 case 3: if(*cmd == 'n') {
	  s=0;
	  printf(TEXT_DELT);
	  break;
	  }


	 if(*cmd != 'y'){
	   break;
	   }

   	 bk_del_ix(ix); 
	 printf(" item[%d] delete success...\r\n",ix);
	 s=0;
	 ix=0;
	 printf(TEXT_DELT);
 break;
 case 4: sprintf(tmp.n,"%s",cmd);
	 printf(" (ESC - back Enter - skip) input last name:");
	 s++;
 break;
 case 5: sprintf(tmp.f,"%s",cmd);
	 printf(" (ESC - back Enter - skip)) input phone:");
	 s++;
 break;
 case 6: sprintf(tmp.p,"%s",cmd);
	 printf(" delete item where name=[%s] last=[%s] phone=[%s] (y/n)?",tmp.n,tmp.f,tmp.p);
	 s++;
 break;
 case 7: if(*cmd == 'n') {
          s=0;
	  printf(TEXT_DELT);
	  break;
	  }


	 if(*cmd != 'y'){
	   break;
	   }
 

	 bk_del_pm(&tmp);
	 printf(" delete success...\r\n");
	 s=0; memset(&tmp,0,sizeof(TABLE));
			 printf(TEXT_DELT);
 break;

 
 }

return(CMD_DELT);
}




#define TEXT_FIND0 " (ESC - back Enter - skip) input last  name:"
#define TEXT_FIND1 " (ESC - back Enter - skip) input phone  number:"
#define TEXT_FIND2 " (ESC - back) push  item to book:(y/n)?"



int cmd_find(char* cmd){
//--------------------------------------------------------------------------
static int s;

if(*cmd == 27){
  printf(TEXT_MAIN);
  return(CMD_WAIT);
  }


switch(s){
  case 0: sprintf(tmp.n,"%s",cmd);
	  printf(TEXT_FIND0);
	  s++;
  break;
  case 1: sprintf(tmp.f,"%s",cmd);
	  printf(TEXT_FIND1);
	  s++;
  break;
  case 2: sprintf(tmp.p,"%s",cmd);
	  printf(" name=[%s],last=[%s],phone=[%s];find(y/n)?",tmp.n,tmp.f,tmp.p); 
	  s++;
  break; 
  case 3: if(*cmd == 'n'){
	   s=0;
	   printf(TEXT_FIND);
	   break;
	   }
	   
	  if(*cmd != 'y'){   
	    break;
	    }
	 
	  s=0;
 	  bk_find(&tmp);
	  memset(&tmp,0x00,sizeof(TABLE));
	  printf(TEXT_FIND);
  break;
 }
 
return(CMD_FIND);
}




#define TEXT_PUSH0 " (ESC - back) input last  name:"
#define TEXT_PUSH1 " (ESC - back) input phone number:"
#define TEXT_PUSH2 " (ESC - back) push  item to book:(y/n)?"




int cmd_push(char* cmd){
//--------------------------------------------------------------------------
static int s;
int ix=0;

if(*cmd == 27){
  s=0;
  printf(TEXT_MAIN);
  return(CMD_WAIT);}



switch(s){
 case 0: sprintf(tmp.n,"%s",cmd);
	 s++;
	 printf(TEXT_PUSH0);
 break;
 case 1: sprintf(tmp.f,"%s",cmd);
	 s++;
	 printf(TEXT_PUSH1);
 break;
 case 2: sprintf(tmp.p,"%s",cmd);
	 s++;
	 printf(TEXT_PUSH2);
 break;
 case 3: if(*cmd == 'n'){
	   s=0;
	   printf(TEXT_PUSH);
	   break;
	   }

	 if(*cmd != 'y'){
 	   break;}
 	
	 s=0; 
	 ix=bk_push(&tmp);
	
	 printf(" push item success, index:%d\r\n",ix);
	 printf(TEXT_PUSH);
 break;
 }
return(CMD_PUSH);
}
/*
 *
 *
 *
 *
 */
int cmd_process(char* cmd){
//-------------------------------------------------------------------------
cmd_check(cmd);

switch(state){ 
  case CMD_WAIT:state=cmd_wait(cmd);break;
  case CMD_PUSH:state=cmd_push(cmd);break;
  case CMD_FIND:state=cmd_find(cmd);break; 			  
  case CMD_DELT:state=cmd_delt(cmd);break;
  default: 	state=CMD_WAIT;     break;
  }
  
return state;
}







