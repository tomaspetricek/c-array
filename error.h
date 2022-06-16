//
// Created by Tomáš Petříček on 16.06.2022.
//

#ifndef CODE_ERROR_H
#define CODE_ERROR_H

#include <string.h>

#define NOT_FOUND 2
#define OUT_OF_RANGE 3
#define BAD_ALLOCATION 4
#define INVALID_ARGUMENT 5
#define FULL 6
#define EMPTY 7

#define MAX_ERR_MSG_SIZE 20

void get_error_message(int err, char* msg)
{
    switch (err) {
    case(EXIT_FAILURE):
        strcpy(msg, "exit failure");
        break;
    case (NOT_FOUND):
        strcpy(msg, "not found");
        break;
    case (OUT_OF_RANGE):
        strcpy(msg, "out of range");
        break;
    case (BAD_ALLOCATION):
        strcpy(msg, "bad allocation");
        break;
    case (INVALID_ARGUMENT):
        strcpy(msg, "invalid argument");
        break;
    case (FULL):
        strcpy(msg, "full");
        break;
    case (EMPTY):
        strcpy(msg, "empty");
        break;
    default:
        strcpy(msg, "unknown error");
        break;
    }
}

void log_error(char* msg, int err){
    char err_msg[MAX_ERR_MSG_SIZE];
    get_error_message(err, err_msg);
    printf("%s: %s\n", msg, err_msg);
}

#endif //CODE_ERROR_H
