
#include "defs.h"



unsigned int size = 0;
char  cmd[1024];

void main(void){

bk_init();
cmd_init();

while(1){

if(!fgets(cmd,sizeof(cmd),stdin)){
  continue;}


if(cmd_process(cmd) == (-1)){
 break;
 }
}	

return;
}
