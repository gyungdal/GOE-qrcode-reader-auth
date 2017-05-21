#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define  BUFF_SIZE   1024

typedef struct {
   long  data_type;
   int   data_num;
   char  data_buff[BUFF_SIZE];
} t_data;

int main( void)
{
   int      msqid;
   t_data   data;

   if ( -1 == ( msqid = msgget( (key_t)1234, IPC_CREAT | 0666)))
   {
      perror( "msgget() 실패");
      exit( 1);
   }

   while(1){
      // 메시지 큐 중에 data_type 이 2 인 자료만 수신
      if ( -1 == msgrcv( msqid, &data, sizeof( t_data) - sizeof( long), 2, 0)){
         perror( "msgrcv() 실패");
         exit( 1);
      }
	char* call = (char*)calloc(sizeof(char),  1512);
	sprintf(call, "%s%s", "curl -o respon -d \"{\"data\":\"%s\"}\" -H \"Content-Type: application/json\" https://httpbin.org/post", data.data_buff);
    printf( "%s\n", call);
	system(call);
   }
}
