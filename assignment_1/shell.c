#include "shell.h"


void signal_callback_handler(int signum){
	printf("Caught signal %d\n",signum);
	exit(signum);
}

//execute simple system commands
void sysExe(char** parsed){
	pid_t pid = fork();

	if(pid == -1){
		printf("Forking failed");
		return;
	} else if(pid == 0){ // try to run in fork, throw error if it doesn't work
		if(execvp(parsed[0],parsed) < 0){
			printf("Command not found\n");
		}
		exit(0);
	} else {
		wait(NULL);
		return;
	}
}


int main(){
         char line[MAX_BUFFER_SIZE];
         char *token;
         int i;
         char *parsed[MAX_BUFFER_SIZE];

	signal(SIGINT, signal_callback_handler);

        while(1){
              i=0;

	char *dir = getcwd(NULL, 0);
	printf("csd4111@cs345sh%s~$ ",dir);

     fgets(line,MAX_BUFFER_SIZE,stdin);

// check if no input
     if(strcmp(line,"\n")==0)continue;

// remove newline char
     char *line2 = strstr(line, "\n");
     if(line2 != NULL){
       	strncpy(line2, "\0",1);
	}
// parsing through line
     char delimit[]="\" \=";
     char del[]="\"";
     token = strtok(line, delimit);

     while(token != NULL) {
       	parsed[i]=strdup(token);
	i++;
	token = strtok(NULL, del);
	}
	parsed[i]=NULL;


      if(builtIns(parsed)==0){
		sysExe(parsed);
         }
   }
return 0;
}

