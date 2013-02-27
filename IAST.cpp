/* 
 * File:   IAST.cpp
 * Author: Daniela
 *
 * Created on February 25, 2013, 3:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <String>

using namespace std;

int length(char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}

char* find(char* str, char* toFind) {
    bool equal = false;
    while (*str && !equal) {
        if (*str == *toFind) {
            char* aux = str;
            char* toFindAux = toFind;
            equal = true;
            while (*toFindAux && *aux && equal) {
                if (*aux != *toFindAux) {
                    equal = false;
                }

                *toFindAux++;
                *aux++;
            }
        }

        if (!equal) {
            *str++;
        }
    }

    return str;
}

bool isIAS(char* test, int size) {
    if (size <= 0) {
        return false;
    }

    if (*test == 'o') {
        *test++;
        if (size == 2) {
            return *test == 'h';
        } else {
            if (*test == 'w') {

            }
            if (*test == 'e' || *test == 'u') {

            }
        }
    }
}

bool isIAT(char* test, int size) {
    if (size <= 0) {
        return false;
    }

    if (*test == 'e' || *test == 'u') {
        *test++;

    }
}

bool isIAST(char* test) {
    char* iat = find(test, "u");
    int iatSize = length(iat);

    if (iatSize == 0) {
        iat = find(test, "e");
        iatSize = length(iat);
        if (iatSize == 0) {
            return false;
        }
    }

    int size = length(test);
    if (size > 0) {
        int iasSize = size - iatSize;
        return isIAS(test, iasSize) && isIAT(iat, iatSize) &&
                (test[size - 1] == '?' || test[size - 1] == '?');
    } else {
        return false;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    freopen("IAST.in", "r", stdin);
    int testCases;
    char test[100];
    scanf("%d", &testCases);
    if (testCases < 100) {
        while (testCases--) {
            scanf("%s", &test);
            if (isIAST(test)) {
                printf("IS IAST");
            } else {
                printf("NO IAST");
            }
        }
    }
    return 0;
}

