#include <stdio.h> 
#include <stdlib.h>    
#include <pthread.h>
#include <limits.h>

struct f{
    int n;
    int a[100000];
};

void* tthread(void *b){
	 struct f *obj = ((struct f *) b);

	
	if(obj->n==1)
	{
	    obj->a[0]=0;
	}
	if(obj->n==2)
	{
	    obj->a[0]=0;
	    obj->a[1]=1;
	}
	else{
	   obj->a[0]=0;
	   obj->a[1]=1;  
	   int i;
	for ( i=2; i<obj->n; i++){
		obj->a[i]=obj->a[i-1]+obj->a[i-2];
	  }
	}
}


int main()
{
    struct f obj;
    scanf("%d" , &obj.n);
    pthread_t thread;
    pthread_create(&thread, NULL,tthread, &obj);
    pthread_join(thread, NULL); 
    for(int i =0;i<obj.n;i++)
    {
        printf("%d ", obj.a[i]);
    }
    printf("\n");
    return 0;
}