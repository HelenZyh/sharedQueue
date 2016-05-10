/*************************************************************************
	> File Name: comm.h
	> Author: zyh_helen
	> Mail: zyh_helen@yeah.net 
	> Created Time: Mon 09 May 2016 10:33:18 AM EDT
 ************************************************************************/

#ifndef _COMM_SHM_
#define _COMM_SHM_

#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<errno.h>
#include<string.h>
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

#define _PATH_ "."
#define _PROJECT_ID_ 0x6666
#define _COUNT_ 10
//#define _SIZE_ (sizeof(string))*(_COUNT_)
#define _SIZE_ 2048

/*头节点：标识循环队列的逻辑上的头，尾下表*/
struct Head{
	size_t front;
	size_t rear;
};

/*循环队列类*/
class Queue{
private:
	Head *_head;
	string *_arr;

public:
	/*循环队列的操作*/
	explicit Queue(){
		_head = NULL;
		_arr = NULL;
	}
	virtual ~Queue(){
		sleep(10);
		shm_detach(_head);		
	}

	bool push(string &val);
	/*
	 * 向循环队列中插入一个值：
	 *		成功返回true
	 *		失败返回false
	 *
	 * */
	bool pop(string &str);
	/*
	 * 向循环队列中取出一个值：
	 *		成功返回true，并将结果存储于参数str中
	 *		失败返回false
	 *
	 * */
	void queue_write_init();
	/*
	 *	仅仅用于写者的函数（获取共享内存并且初始化头信息）
	 *		获取共享内存：ftok + shmget  大小：sizeof(head) + sizeof(string)*_COUNT_
	 *		sizeof(Head):保存关于循环队列的头尾下标
	 *		sizeof(string)*_COUNT_:实际循环队列string数组
	 *
	 * */

	void queue_read_init();
	/*
	 *	仅仅用于读者的函数（初始化类成员）
	 *		 _head指向循环队列头部
	 *		 _arr:指向实际循环队列头部
	 *
	 * */
	
private:
	bool is_full();
	bool is_empty();

private:

	/*对共享内存的操作封装函数*/
	int shm_create();
	int shm_get();
	int shm_detach(const void *shmaddr);
	void *shm_attach(int shmid);
	int shm_destory(int shmid);
	int shm_create_get(int flag);
};

#endif

