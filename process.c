//
// Created by omar_swidan on 11/10/18.
//

#include <zconf.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "process.h"

void executeInForeground(char *command, char **args) {

    int status; //status flag to be used by the wait function
    int pid=fork();
    if (pid>0)
        wait(&status); //wait until the child process has terminated
    else if (!pid)
        execvp(command,args); //execute the command using the child process

}

void executeInBackground(char *command, char **args) {
    int pid=fork();
    if(!pid) {//execute using the child process and don't wait with the parent process
        execvp(command, args);

    }


}

void execute(char *command, char **args) {

    if (strcmp(args[0],"exit")==0)
        exit(0);
    else if (strcmp(args[1],"&")==0) //execute in background if '&' is specified in the arguments
        executeInBackground(command,args);
    else executeInForeground(command,args);

}
