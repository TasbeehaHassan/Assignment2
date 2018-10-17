#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<pthread.h>
int chunk_Size=100;
int arr[1000];
void * totalSumFunction(void * arg);
int main(){
    int t=0,totalSum=0,start=0,end=0;
    //int p1[2],p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2],p9[2],p10[2];
    void *status_t1,*status_t2, *status_t3,*status_t4, *status_t5, *status_t6, *status_t7,*status_t8, *status_t9,*status_t10;
    for(int i=0;i<1000;i++){
        arr[i]=i;
    }
    pthread_t thread_t1,thread_t2,thread_t3,thread_t4,thread_t5,thread_t6,thread_t7,thread_t8,thread_t9,thread_t10;
    pthread_create(&thread_t1,NULL,totalSumFunction, (void*)(0*chunk_Size));
    pthread_create(&thread_t2,NULL,totalSumFunction, (void*)(1*chunk_Size));
    pthread_create(&thread_t3,NULL,totalSumFunction, (void*)(2*chunk_Size));
    pthread_create(&thread_t4,NULL,totalSumFunction, (void*)(3*chunk_Size));
    pthread_create(&thread_t5,NULL,totalSumFunction, (void*)(4*chunk_Size));   
    pthread_create(&thread_t6,NULL,totalSumFunction, (void*)(5*chunk_Size));
    pthread_create(&thread_t7,NULL,totalSumFunction, (void*)(6*chunk_Size));
    pthread_create(&thread_t8,NULL,totalSumFunction, (void*)(7*chunk_Size));
    pthread_create(&thread_t9,NULL,totalSumFunction, (void*)(8*chunk_Size));
    pthread_create(&thread_t10,NULL,totalSumFunction, (void*)(9*chunk_Size));
    pthread_join(thread_t1,(void**)&status_t1);
    pthread_join(thread_t2,(void**)&status_t2);
    pthread_join(thread_t3,(void**)&status_t3);
    pthread_join(thread_t4,(void**)&status_t4);
    pthread_join(thread_t5,(void**)&status_t5);
    pthread_join(thread_t6,(void**)&status_t6);
    pthread_join(thread_t7,(void**)&status_t7);
    pthread_join(thread_t8,(void**)&status_t8);
    pthread_join(thread_t9,(void**)&status_t9);
    pthread_join(thread_t10,(void**)&status_t10);

    totalSum= (int)status_t1+(int)status_t2+(int)status_t3+(int)status_t4+(int)status_t5+(int)status_t6+(int)status_t7+(int)status_t8+(int)status_t9+(int)status_t10;
    printf("THE TOTAL SUM IS %d" , totalSum);
}
void * totalSumFunction(void * arg){
    int start = (int)arg;
    int end = start + chunk_Size;
    int t=0;
    for(int i= start;i<end;i++){
        t+=arr[i];
    }
    return (void *)t;
}
