//
// Created by omar_swidan on 12/10/18.
//

#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"


char **tokenize(char *line, char delimiter, int max) {
    //allocate an array of characters
    char **tokens =(char **) malloc(50 * sizeof(char **));
    int k = 0;
    char *token = (char *)malloc(10);

    int j = 0;

    for (int i = 0; i < strlen(line); ++i) {

        if (line[i] == ' ' || line[i] == '\n' || line[i] == '/0') {
            if (line[i - 1] == ' ')
                break;
            tokens[k] = token;
            //strncpy(tokens[k], token, (size_t) j-1);
            k++;
            //printf("%s9", token);
            j = 0;
            continue;
        }
        //printf("%c\n",line[j+x]);
        token[j] = line[i];
        j++;


    }

    return tokens;
}
