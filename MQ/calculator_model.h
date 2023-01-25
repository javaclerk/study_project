/**
 * @file calculator_model.h
 * @author Jeremy Trendoff - 101160306
 * @brief A Header File for Calculator Operations.
 */

#ifndef CALCULATOR_MODEL_H
#define CALCULATOR_MODEL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include "array_list.h"

void insertToCalculator(intlist_t *list, int number);
void deleteFromCalculator(intlist_t *list, int number);
double average(intlist_t *list);
int min(intlist_t *list);
int max(intlist_t *list);
int* median(intlist_t *list);
int add(intlist_t *list);

#endif