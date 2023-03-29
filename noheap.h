#ifndef NOHEAP_H
#define NOHEAP_H

#include "addandremove.h"

typedef struct {
    char cardNr[100];
    char access[100];
    char date[100];
} Card2;

void noheap();

void removeChar(char *str, char garbage);

void ReadIniFileWithCallback(const char *fileName,void(*func)(const char *, const char *, const char *, void *, int, bool *), void *payload, int cardNr);

void ReadIniFileWithCallbackOnlyList(const char *fileName,void(*func)(const char *, const char *, const char *, void *), void *payload);

void iniValueCallback(const char *section, const char *key, const char *value, void *payload, int cardNr, bool *foundCardnr);

void iniValueCallbackOnlyList(const char *section, const char *key, const char *value, void *payload);

void ReadIniFileWithCallbackGetStruct(const char *fileName,void(*func)(const char *, const char *, const char *, void *, int, bool *, Card2*), void *payload, int cardNr, Card2* getCard);

void iniValueCallbackGetStruct(const char *section, const char *key, const char *value, void *payload, int cardNr, bool *foundCardnr, Card2* getCard);

void writeStructtoFile(Card2* card);

#endif