#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    char *c[]={"apt","update",'\0'};

    int x=execvp(c[0],c);
    printf("%d",x);
    return 0;
}