#include "shell.h"


int builtIns(char** token){
        int numCmds = 4;
        char* builtInCmds[numCmds];
        int i = 0;
        int hit = 0;

        builtInCmds[0] = "exit";
        builtInCmds[1] = "cd";
        builtInCmds[2] = "my_var";
        builtInCmds[3] = "echo";


        // loop through array looking for a match
        for(i; i < numCmds; i++){
                if(strcmp(token[0], builtInCmds[i])==0){
                        hit = i + 1;
                        continue;
                }
        }

        if(hit == 0){ // not in built-ins
                return 0;
        } else if(hit == 1){ // exit
                printf("Goodbye!\n");
                exit(0);
        } else if (hit == 2){ // cd
                chdir(token[1]);
                return hit;
        }else if(hit == 3){ //my_var
            if(token[0] == NULL){
                fprintf(stderr, "ERROR: Expected variable name after \"my_var\" command.\n\Example: my_var=\"Hello World!\" var\n");
            }else if(token[1]== NULL){
                setenv(token[0],"",1);
            }else{
                setenv(token[0],token[1],1);}
        }else if (hit == 4){ //echo
              executeVariables(token);
        }
return hit;
}

int executeVariables(char** arg){
    int i = 0;

    for(i = 0; arg[i] != NULL; i++){
        char *str = arg[i];

        if(*str == '$'){
            // make sure the result isn't NULL
            char *tmp = getenv(str + 1);
            if (tmp != NULL) {
                arg[i] = getenv(str + 1); // save the argument
            }
        }
    }
    // execute the function "bash"
   if (strcmp(arg[0], "echo") == 0) {
        int i;
        for (i = 1; arg[i] != NULL; i++) {
            printf("%s ", arg[i]);
        }
        printf("\n");
    }
    return 1;
}

