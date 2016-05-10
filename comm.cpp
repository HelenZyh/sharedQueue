/*************************************************************************
	> File Name: comm.cpp
	> Author: zyh_helen
	> Mail: zyh_helen@yeah.net 
	> Created Time: Mon 09 May 2016 10:33:27 AM EDT
 ************************************************************************/

#include"comm.h"

int Queue::shm_create_get(int flag){
	key_t key = ftok(_PATH_,_PROJECT_ID_);
	if(key == -1){
		cout<<"ftok error,errno: "<<errno<<"strerrno: "<<strerror(errno)<<endl;
		return -1;
	}
	return shmget(key,_SIZE_+sizeof(Head),flag);
}

int Queue::shm_create(){
	return shm_create_get(IPC_CREAT|IPC_EXCL|0700);
}

int Queue::shm_get(){
	return shm_create_get(IPC_CREAT);
}
void *Queue::shm_attach(int shmid){
	return shmat(shmid,NULL,0);
}
int Queue::shm_detach(const void *shmaddr){
	return shmdt(shmaddr);
}

int Queue::shm_destory(int shmid){
	return shmctl(shmid,IPC_RMID,NULL);
}

void Queue::queue_write_init(){
	int shmid = shm_create();
	_shmid = shmid;
	_head = (Head *)(shm_attach(shmid));
	_head->front = 0;
	_head->rear = 0;
	_arr = (Text *)(_head+1);
//	cout<<"++"<<endl;
}
void Queue::queue_read_init(){
	int shmid = shm_get();
	_shmid = shmid;
	_head = (Head *)(shm_attach(shmid));
	_arr = (Text *)(_head+1);	
}

void Queue::queue_destory(){
	shm_destory(_shmid);
}
bool Queue::push(Text &val){
	if(is_full()){
		cout << "the queue is already full,can not push anymore!" << endl;
		return false;
	}
	_arr[_head->rear] = val;
	//cout<<_arr[_head->rear]<<endl;
	_head->rear = (_head->rear + 1) % _COUNT_;
	cout<<"_head->rear: "<<_head->rear<<" front: "<<_head->front<<endl;

	cout<<"push sucess: "<<val.text<<endl;
	return true;
}
bool Queue::pop(Text &str){
	if(is_empty())
	{
		cout << "the queue is already empty,it can not pop anymore!" << endl;
		return false;
	}
	str = _arr[_head->front];
	_head->front = (_head->front + 1) % _COUNT_;
	return true;

}
bool Queue::is_full(){
	return (_head->rear + 1) % _COUNT_ == _head->front;//约定：front在rear的下一个位置表示队列已满
}
bool Queue::is_empty(){
	return _head->front == _head->rear;
}
