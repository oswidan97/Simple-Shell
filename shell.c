//
// Created by omar_swidan on 10/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include "shell.h"
#include "input.h"
#include "process.h"

void startShell() {



    //while(1) {
        char **tokenizedInput = getInput();
        execute(tokenizedInput[0], tokenizedInput);

   // }
//    for (int i = 0; i < MAX; ++i) {
//        if (tokenizedInput[i] == NULL)
//            break;
//        printf("%s..", tokenizedInput[i]);
//        printf("%d\n",i);
//    }


    free(tokenizedInput);
}
