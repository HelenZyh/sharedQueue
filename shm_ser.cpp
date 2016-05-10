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
	string s1 = "hello";
	string s2 = "world";
	q.push(s1);
	q.push(s2);
	return 0;
}
