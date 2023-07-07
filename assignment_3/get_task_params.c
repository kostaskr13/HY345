/*konstantinos_krouti_csd4111*/

#include<linux/d_params.h>
#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/syscalls.h>



asmlinkage long sys_get_task_params(struct d_params * params){

 if(params==NULL){
	printk("ERROR, params=NULL\n");
    return EINVAL;
 }
 params->deadline=current->deadline;
 params->estimated_runtime=current->estimated_runtime;

return 0;

}