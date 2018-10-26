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
    int pid=fork();//spawn a child process
    if (pid>0)
        wait(&status); //wait until the child process has terminated
    else if (!pid)
        execvp(command,args); //execute the command using the child process

}

void executeInBackground(char *command, char **args) {
    args[1]='\0';//remove the '&'
    int pid=fork();//spawn a child process
    if (!pid)
        setpgid(0,0);//set a new process group id to the child process as its id,
    if (pid>0)
        tcsetpgrp(0,getpgrp());//make the foreground controlling process group id, the parent's group process
    if(!pid)
        execvp(command, args);//execute using the child process and don't wait with the parent process
}

void execute(char *command, char **args) {

    if (strcmp(args[0],"exit")==0)
        exit(0);
    else if (strcmp(args[getColCount(args)-1],"&")==0) //execute in background if '&' is specified in the arguments
        executeInBackground(command, args);
    else executeInForeground(command,args);

}
int getColCount(char **args){//return columns count of a 2d-array

    int i=0;

    for (i = 0;; ++i)
        if (args[i]==NULL)
            break;

    return i;
}