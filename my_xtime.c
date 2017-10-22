#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/printk.h>
#include <linux/time.h>
#include <linux/init.h>
#include <linux/export.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <asm/uaccess.h>

//change long to int, void to struct timespec...
asmlinkage int  sys_my_xtime(struct timespec *current_time) {
	struct timespec c_time;

	/*if you the space that the timespec struct 
          is held in is not writable then return EFAULT
	*/
	if(!access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec)))
		return EFAULT;

                                                  
	c_time  =  current_kernel_time();  //get the current time from the kernel 
	current_time = &c_time;  //set the current time struct to the current time
	
	//print out the current time in nanoseconds
	printk("The current time is %ld  ", current_time->tv_nsec);

	return 0;
}

EXPORT_SYMBOL(sys_my_xtime);

