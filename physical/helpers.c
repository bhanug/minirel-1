#include<string.h>

#include "../include/globals.h"
#include "../include/defs.h"
#include "../include/error.h"

/*
 * Contains helper functions used throughout the project
 *
 *  Created on: 29-Oct-2014
 *      Author: nithin
 */

//FIXME Move to another folder?
int readStringFromByteArray(char * string, const char *byteArray, const int offset, const int size) {
    if (byteArray == NULL || string == NULL) {
        return ErrorMsgs(NULL_POINTER_EXCEPTION, g_print_flag);
    }
    strncpy(string, (byteArray + offset), size);
    return OK;
}

int readIntFromByteArray(const char *byteArray, const int offset) {

    if (byteArray == NULL) {
        ErrorMsgs(NULL_POINTER_EXCEPTION, g_print_flag);
        return 0;
    } else {
        const char *offsetedByteArray = byteArray + offset;

        return ((offsetedByteArray[0] << 24) & 0xFF000000)
                | ((offsetedByteArray[1] << 16) & 0x00FF0000)
                | ((offsetedByteArray[2] << 8) & 0x0000FF00) | (offsetedByteArray[3] & 0x000000FF);
    }
}

float readFloatFromByteArray(const char* byteArray, const int offset) {

    Flip converter;
    converter.int_val = readIntFromByteArray(byteArray, offset);
    return converter.float_val;
}

void convertIntToByteArray(int value, char *byteArray) {
    byteArray[0] = (value >> 24) & 0xFF;
    byteArray[1] = (value >> 16) & 0xFF;
    byteArray[2] = (value >> 8) & 0xFF;
    byteArray[3] = value & 0xFF;
}

void convertFloatToByteArray(float value, char *byteArray) {
    Flip converter;
    converter.float_val = value;
    convertIntToByteArray(converter.int_val, byteArray);
}

/*************************************************************
 COMPARISONS
 *************************************************************/

bool compareNum(float val1, float val2, int compOp) {
    switch (compOp) {
        case EQ:
            return val1 == val2 ? TRUE : FALSE;
        case NEQ:
            return val1 != val2 ? TRUE : FALSE;
        case GEQ:
            return val1 >= val2 ? TRUE : FALSE;
        case LEQ:
            return val1 <= val2 ? TRUE : FALSE;
        case GT:
            return val1 > val2 ? TRUE : FALSE;
        case LT:
            return val1 < val2 ? TRUE : FALSE;
        default:
            ErrorMsgs(INVALID_COMP_OP, g_print_flag);
            break;
    }
    return FALSE;
}

//TODO Ask about supported string comparison
bool compareStrings(char *s1, char *s2, int compOp) {
    switch (compOp) {
        case EQ:
            return strcmp(s1, s2) == 0 ? TRUE : FALSE;
        case NEQ:
            return strcmp(s1, s2) ? TRUE : FALSE;
        case GEQ:
            return (strcmp(s1, s2) >= 0) ? TRUE : FALSE;
        case LEQ:
            return (strcmp(s1, s2) <= 0) ? TRUE : FALSE;
        case GT:
            return (strcmp(s1, s2) > 0) ? TRUE : FALSE;
        case LT:
            return (strcmp(s1, s2) < 0) ? TRUE : FALSE;
        default:
            ErrorMsgs(INVALID_COMP_OP, g_print_flag);
            break;
    }
    return FALSE;
}
/**
 * Gets the last valid Rid in a relation
 *
 * @param   relNum
 * @return  last valid Rid
 */
Rid getLastRid(int relNum) {
    int numRecs = g_catcache[relNum].numRecs;
    int recsPerPg = g_catcache[relNum].recsPerPg;
    Rid last;
    last.pid = numRecs / recsPerPg + 1;
    last.slotnum = numRecs % recsPerPg + 1;
    return last;
}

/*
 * Function: seperate_db_path() 
 * ----------------------------
 * Seperates dbname and path from the the string, dbname with path
 *
 *  db_with_path : full path of database
 *  path         : path of database without dbname
 *  dbname       : database name
 *
 *  returns: OK on success
 *           NOTOK on failure
 */

int seperate_db_path(char* db_with_path, char* path, char* dbname){

    char db_path_copy[100], *temp;
    strcpy(db_path_copy, db_with_path);

    temp = strtok(db_path_copy,"/");

    strcpy(dbname,temp);
    strcpy(path,"");

    if(db_with_path == NULL)
        return NOTOK;

    if(strlen(temp) != strlen(db_with_path)) {
        while((temp = strtok(NULL,"/")) != NULL){
            strcat(path,dbname);
            strcat(path,"/");

            strcpy(dbname, temp);
        }
    }
    path[ strlen(path)-1 ] ='\0';
    return OK;
}