/**
 * @file calculator_model.h
 * @author Jeremy Trendoff - 101160306
 * @brief  Calculator Operations Implementation.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include "array_list.h"

/**
 * @brief Insert an integer into the calculator.
 * 
 * @param list      intlist_t, the list for the calculator.
 * @param element   int, the element to add.
 */
void insertToCalculator(intlist_t *list, int element)
{
    intlist_append(list, element);
}

/**
 * @brief Remove all instances of the specified element in the calculator.
 * 
 * @param list      intlist_t, the list for the calculator.
 * @param element   int, the element to remove.
 */
void deleteFromCalculator(intlist_t *list, int element)
{
    intlist_removeInstancesOf(list, element);
}

/**
 * @brief Calculate the average of the numbers in the calculator.
 * 
 * @param list  intlist_t, the list for the calculator.
 * @return double  The average.
 */
double average(intlist_t *list) 
{
    double total = 0;
    for (int i = 0; i < list->size; i++)
    {
        total += list->elems[i];
    }
    return (total / list->size);
}

/**
 * @brief Add the numbers in the calculators up.
 * 
 * @param list intlist_t, the list for the calculator.
 * @return int the added value.
 */
int add(intlist_t *list)
{
    int total = 0;
    for (int i = 0; i < list->size; i++)
    {
        total += list->elems[i];
    }
    return total;
}

/**
 * @brief Get the min value in the calculator.
 * 
 * @param list intlist_t, the list for the calculator.
 * @return int the min value.
 */
int min(intlist_t *list)
{
    int minval = list->elems[0];
    for (int i = 1; i < list->size; i++)
    {
        if (list->elems[i] < minval)
        {
            minval = list->elems[i];
        }
    }
    return minval;
}

/**
 * @brief Get the max value in the calculator.
 * 
 * @param list intlist_t, the list for the calculator.
 * @return int the max value.
 */
int max(intlist_t *list)
{
    int maxval = list->elems[0];
    for (int i = 1; i < list->size; i++)
    {
        if (list->elems[i] > maxval)
        {
            maxval = list->elems[i];
        }
    }
    return maxval;
}

/**
 * @brief Get the median value or values from the calculator. 
 * 
 * @param list intlist_t, the list for the calculator.
 * @return int* the median values.
 */
int* median(intlist_t *list)
{
    intlist_sort(list);

    int *return_vals = (int *) malloc(2 * sizeof(int));

    if (list->size % 2 == 0)
    {
        return_vals[0] = list->elems[(int)(list->size / 2) - 1];
        return_vals[1] = list->elems[(int)(list->size / 2)];
    } else 
    {
        return_vals[0] = list->elems[(int)((list->size - 1) / 2)];
        return_vals[1] = -1;
    }

    return return_vals;
}

/**
 * @brief Test code for the calculator_model.
 */
// int main()
// {
//     intlist_t* list = intlist_construct(50);
//     insertToCalculator(list, 5);
//     insertToCalculator(list, 2);
//     insertToCalculator(list, 3);
//     insertToCalculator(list, 1);
//     insertToCalculator(list, 8);

//     intlist_print(list);

//     printf("\n");

//     printf("Average: %0.2f\n", average(list));
//     printf("Addition: %d\n", add(list));
//     printf("min: %d\n", min(list));
//     printf("max: %d\n", max(list));

//     int* median_vals = median(list);

//     if (median_vals[0] == 1)
//     {
//         printf("Median: %d\n", median_vals[1]);
//     } else 
//     {
//         printf("Median: %d and %d\n", median_vals[1], median_vals[2]);
//     }

//     intlist_destroy(list);
//     return 0;
// }
