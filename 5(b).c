#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  	

int global_var = 0; 
  
void *tthread(void *a) 
{ 
    
    int *threadid = (int *)a; 
    static int static_var = 0; 
    int local_var =0;
  
    printf("Thread ID: %d, Global: %d, Static: %d,Local: %d\n", *threadid,++global_var,++static_var,++local_var); 
} 
  
int main() 
{ 
     
    pthread_t id1; 
    pthread_t id2; 
    pthread_t id3; 
    pthread_create(&id1, NULL, tthread, (void *)&id1);
    pthread_create(&id2, NULL, tthread, (void *)&id2);
    pthread_create(&id3, NULL, tthread, (void *)&id3);
    pthread_exit(NULL); 
    return 0; 
}