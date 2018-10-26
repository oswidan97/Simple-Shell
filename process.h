//
// Created by omar_swidan on 11/10/18.
//

#ifndef SIMPLESHELL_PROCESS_H
#define SIMPLESHELL_PROCESS_H

void execute(char *command,char **args);
void executeInForeground(char *command,char **args);

void executeInBackground(char *command,char **args);
int getColCount(char **args);

#endif //SIMPLESHELL_PROCESS_H
