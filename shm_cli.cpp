/*************************************************************************
	> File Name: shm_cli.cpp
	> Author: zyh_helen
	> Mail: zyh_helen@yeah.net 
	> Created Time: Mon 09 May 2016 10:33:41 AM EDT
 ************************************************************************/

#include"comm.h"

int main()
{
	Queue q;
	q.queue_read_init();
	Text str;
	while(1){
		if(q.pop(str)){
			cout<<str.text<<endl;
		}
		sleep(1);
	}
	q.queue_destory();	
	return 0;
}

