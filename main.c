#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <signal.h>
#include "shell.h"

void childLogger(int signum){
    fprintf(fopen("./child process log","a"),"Child process terminated \n");
}
int main() {


    signal(SIGCHLD,childLogger);
    startShell();
//    printf("Hello, World!\n");
//    char *c[]={"cp",'\0'};
//
//    int x=execvp(c[0],c);
//    printf("%d",x);
    return 0;
}