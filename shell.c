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


    char **tokenizedInput;
    while(1) {
        printf(">>");
        tokenizedInput = getInput();
        execute(tokenizedInput[0], tokenizedInput);

    }
//    for (int i = 0; i < MAX; ++i) {
//        if (tokenizedInput[i] == NULL)
//            break;
//        printf("%s9", tokenizedInput[i]);
//    }


    free(tokenizedInput);
}
