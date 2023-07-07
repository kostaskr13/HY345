//csd4111

      #include <stdio.h>
      #include <unistd.h>
      #include <stdlib.h>


      int main(){
              printf("enter\n");

              struct d_params *params=malloc(sizeof(struct d_params));
              set_task_params(5,4000);/*Sosto Access*/
              set_task_params(1,-1);
              get_task_params( params);
              get_task_params(NULL);


              return 0;

           }


