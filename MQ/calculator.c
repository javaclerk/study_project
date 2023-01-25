/**
 * @file calculator.c
 * @author Jeremy Trendoff - 101160306
 * @brief The calculator server for SYSC4001A Assignment 3.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include "array_list.h"
#include "message_queue.h"
#include "calculator_model.h"

#define MAX_TEXT 35 // The maximum characters that can be send through the buffer.

/**
 * @brief The message struct to send data to the user.
 */
typedef struct 
{
    long int my_msg_type; 
    char some_text[MAX_TEXT]; 
    double num; 
    double median2; 
} send_to_user;

/**
 * @brief The message struct to get data from the user.
 */
typedef struct
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
} get_from_user;

int main()
{
    // 1 = run the program. 0 = stop.
    int running = 1;

    // Msg queue id's
    int msgid1, msgid2;

    // Data received from user.
    get_from_user data_received;

    // Data sent to user.
    send_to_user send_data;

    // The message to receive.
    long int msg_to_receive = 0;

    // The backing list to the calculator.
    intlist_t* list = intlist_construct(50);

    // Variables to calculate time to process.
    struct timeval start, end;
    double insertTime = 0, deleteTime = 0, sumTime = 0, avgTime = 0, minTime = 0, medianTime = 0, averageTime = 0;

    // Create message queues.
    msgid1 = create_message_queue((key_t)1999);
    msgid2 = create_message_queue((key_t)2001);

    // While running...
    while (running)
    {
        // Receieve the message from the user.
        receive_message(msgid1, (void *) &data_received, MAX_TEXT, msg_to_receive, 0);

        /* Process the request. */

        printf("You typed: %s", data_received.some_text);

        if (strncmp(data_received.some_text, "end", 3) == 0)
        {
            running = 0;
            printf("System Shutdown.\n");
            break;
        } 
        else if (strncmp(data_received.some_text, "insert", 6) == 0)
        {
            gettimeofday(&start, NULL);
            int len = strlen(data_received.some_text);

            char value[len - 9];
            int counter = 0;
            for (int i = 7; i < len - 2; i++)
            {
                value[counter] = data_received.some_text[i];
                counter++;
            }
            int val = atoi(value);

            insertToCalculator(list, val);

            intlist_print(list);
            printf("\n");

            char sendback[MAX_TEXT];
            sprintf(sendback, "Inserted %d", val);

            strcpy(send_data.some_text, sendback);

            gettimeofday(&end, NULL);
            insertTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else if (strncmp(data_received.some_text, "sum", 3) == 0)
        {
            gettimeofday(&start, NULL);
            double val = (double) add(list);
            send_data.num = val;
            printf("The sum is: %0.2f\n", val);

            char sendback[MAX_TEXT];
            sprintf(sendback, "The sum is: %0.0f", val);

            strcpy(send_data.some_text, sendback);

            gettimeofday(&end, NULL);
            sumTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else if (strncmp(data_received.some_text, "delete", 6) == 0)
        {
            gettimeofday(&start, NULL);
            int len = strlen(data_received.some_text);

            char value[len - 9];
            int counter = 0;
            for (int i = 7; i < len - 2; i++)
            {
                value[counter] = data_received.some_text[i];
                counter++;
            }
            int val = atoi(value);

            deleteFromCalculator(list, val);

            intlist_print(list);
            printf("\n");

            char sendback[MAX_TEXT];
            sprintf(sendback, "Deleted %d", val);

            strcpy(send_data.some_text, sendback);

            gettimeofday(&end, NULL);
            deleteTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else if (strncmp(data_received.some_text, "average", 7) == 0)
        {
            gettimeofday(&start, NULL);
            double val = average(list);
            send_data.num = val;
            printf("Average is: %0.2f\n", val);

            char sendback[MAX_TEXT];
            sprintf(sendback, "The average is: %0.2f", val);

            strcpy(send_data.some_text, sendback);

            gettimeofday(&end, NULL);
            avgTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else if (strncmp(data_received.some_text, "min", 3) == 0)
        {
            gettimeofday(&start, NULL);
            double val = min(list);
            send_data.num = val;
            printf("The min value is: %0.0f\n", val);

            char sendback[MAX_TEXT];
            sprintf(sendback, "The min is: %0.0f", val);

            strcpy(send_data.some_text, sendback);

            gettimeofday(&end, NULL);
            minTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else if (strncmp(data_received.some_text, "median", 6) == 0)
        {
            gettimeofday(&start, NULL);
            int* vals = (int *) malloc(2 * sizeof(int));
            vals = median(list);
            send_data.num = vals[0];
            send_data.median2 = vals[1];

            char sendback[MAX_TEXT];

            if (vals[1] == -1)
            {
                sprintf(sendback, "The Median is: %d", vals[0]);

                printf("Median is: %d\n", vals[0]);
            } else 
            {
                sprintf(sendback, "The Median is: %d and %d", vals[0], vals[1]);

                printf("Median is: %d and %d\n", vals[0], vals[1]);
            }

            strcpy(send_data.some_text, sendback);

            free(vals);
            gettimeofday(&end, NULL);
            medianTime = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
        }
        else
        {
            char sendback[MAX_TEXT];
            strcpy(sendback, "Invalid Command");
            strcpy(send_data.some_text, sendback);

            printf("That Command was Invalid\n");
        }

        /* Notify User Request Was Processed. */

        send_data.my_msg_type = 1;
        send_message(msgid2, (void *) &send_data, MAX_TEXT);
    }

    // Calculate average time.
    averageTime = (insertTime + deleteTime + sumTime + avgTime + minTime + medianTime) / 6;
    printf("Average time to perform all operations was %.6f ms\n", averageTime);

    // Destroy the list.
    intlist_destroy(list);

    // Delete message queues.
    delete_message_queue(msgid1);
    delete_message_queue(msgid2);
    
    exit(EXIT_SUCCESS);
}
