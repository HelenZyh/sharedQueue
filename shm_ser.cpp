/*************************************************************************
	> File Name: shm_ser.cpp
	> Author: zyh_helen
	> Mail: zyh_helen@yeah.net 
	> Created Time: Mon 09 May 2016 10:34:05 AM EDT
 ************************************************************************/


#include"comm.h"

int main()
{
	Queue q;
	q.queue_write_init();
	Text t1;
	Text t2;
	Text t3;
	Text t4;
	strcpy(t1.text,"zyh");
	strcpy(t2.text,"zyh_helen");
	strcpy(t3.text,"xxxx");
	strcpy(t4.text,"yyyyy");
	while(1){
		q.push(t1);
		q.push(t2);
		q.push(t3);
		q.push(t4);
		sleep(2);
	}
	return 0;
}
