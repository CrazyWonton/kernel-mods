//#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#define timespec linux_timespec
#include <linux/time.h>
//#undef timespec
#include <linux/unistd.h>
//#include <sys/syscall.h>
//#include <sys/types.h>
#include <errno.h>

int main(){
	struct timespec * timeIn;
	int t = 0;
	t = syscall(326, timeIn);
	
	printf("The current time is %d\n",t);
	return t;
}
