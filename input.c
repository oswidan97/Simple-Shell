//
// Created by omar_swidan on 10/10/18.
//

#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//TODO don't forget to free the pointer !!!!
char ** getInput(){
    char command[MAX];
    //read input
    fgets(command,MAX,stdin);

    int len = (int) strlen(command);
    //allocate memory on the heap
    char *commandAsPointer=malloc((size_t) len); //casting to match the function's parameter
    //copy to to the char * to be able to return it
    strncpy(commandAsPointer,command,(size_t)len);
    //printf("%s",command);

    return tokenizer(commandAsPointer);
}
char ** tokenizer(char * command){
        
    //allocate an array of characters
    char **tokens=malloc(MAX* sizeof(char **));
    //tokenize the command with '\n' as a delimeter
    char *token=strtok(command,delimiter);

    int i=0;
    while(token!=NULL){

        tokens[i]= token;
        token=strtok(NULL,delimiter);

        i++;
    }


    //free(command);
    return tokens;

}
