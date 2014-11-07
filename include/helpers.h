/*
 * helpers.h
 *
 *  Created on: 30-Oct-2014
 *      Author: nithin
 */

#ifndef HELPERS_H_
#define HELPERS_H_

#include <string.h>

void readStringFromByteArray(char * string, const char *byteArray, const int offset, const int size);

int readIntFromByteArray(const char *byteArray, const int offset);

float readFloatFromByteArray(const char* byteArray, const int offset);

bool compareNum(float val1, float val2, int compOp);

bool compareStrings(char *s1, char *s2, int compOp);

void convertIntToByteArray(int value, char *byteArray);

void convertFloatToByteArray(float value, char *byteArray);

Rid getLastRid(int relNum);

int separate_db_path(char* db_with_path, char* path, char* dbname);

/*  Helpers for schema/physical layer */
int compareRecords(char *record1, char *record2, int sizeOfRecord);

int getN(char *sN);

int isValidString(char *string);

int getSizeOfAttr(char *attrFormat);

#endif /* HELPERS_H_ */
