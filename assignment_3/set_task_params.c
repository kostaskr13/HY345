
/*konstantinos_krouti_csd4111*/

#include <linux/kernel.h>
#include <asm-generic/errno-base.h>
#include <linux/sched.h>
#include <asm/current.h>



asmlinkage long sys_set_task_params(int deadline, int estimated_runtime){

printk("Konstantinos ,csd4111 set_task_params(%d,%d)\n",deadline,estimated_runtime);


if((deadline*1000)<=estimated_runtime || estimated_runtime <0 || deadline<=0){
    printk("ERROR\n");
    return EINVAL;
}

current->deadline=deadline;
current->estimated_runtime=estimated_runtime;
printk("deadline : %d \nestimate_runtime : %d \n,",current->deadline,current->estimated_runtime);

}


