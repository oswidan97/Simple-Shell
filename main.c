#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <signal.h>
#include "shell.h"

void childLogger(int signum){
    FILE *childFile=fopen("./child process log","a");
    fprintf(childFile,"Child process terminated \n");
    fflush(childFile);

}
int main() {


    signal(SIGCHLD,childLogger);//set the signal handler to the "SIGCHLD" signal
    startShell();

    return 0;
}