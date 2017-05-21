#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define  BUFF_SIZE   1024

typedef struct {
   long  data_type;
   int   data_num;
   char  data_buff[BUFF_SIZE];
} t_data;

int main( void){
	int msqid;
	int ndx   = 0;
	t_data data;

	if ( -1 == ( msqid = msgget( (key_t)1234, IPC_CREAT | 0666))){
	fprintf(stderr, "msgget() 실패");
	exit( 1);
	}
	while(1){
		data.data_type = 2;   // data_type 는 1, 2, 3
		data.data_num  = ndx;
		//sprintf( data.data_buff, "d901e34c-19de-11e7-93ae-92361f002671");
		fscanf(stdin, "%s", &data.data_buff);
		if ( -1 == msgsnd( msqid, &data, sizeof( t_data) - sizeof( long), 0))
		{
		 fprintf(stderr, "msgsnd() 실패");
		 exit( 1);
		}
	}
}
