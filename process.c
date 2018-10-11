//
// Created by omar_swidan on 11/10/18.
//

#include <zconf.h>
#include <sys/wait.h>
#include "process.h"

void executeInForeground(char *command, char **args) {

    int status;
    int pid=fork();
    if (pid>0)
        wait(&status);
    else if (pid==0){

        execvp(command,args);
    }
}

void executeInBackground(char *command, char **args) {
    int pid=fork();
    if(pid==0){
        sleep(10);
        execvp(command,args);
    }


}
