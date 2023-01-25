/**
 * @file user.c
 * @author Jeremy Trendoff - 101160306
 * @brief The user client for the SYSC4001A Assignment 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <ctype.h>
#include "message_queue.h"

#define MAX_TEXT 35 // The maximum characters that can be send through the buffer.

/**
 * @brief Message struct to send data to calculator.
 */
typedef struct 
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
} send_to_calc;

/**
 * @brief Message struct to get data from calculator.
 */
typedef struct 
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
    double num;
    double median2;
} get_from_calc;

int main()
{
    // 1 = run the program. 0 = stop.
    int running = 1;

    // Msg queue id's
    int msgid1, msgid2;

    // Send data to calculator struct.
    send_to_calc send_data;

    // Get data from calculator struct.
    get_from_calc data_received;

    // Message to receive.
    long int msg_to_receive = 0;

    // Buffer to get input from the user.
    char buffer[MAX_TEXT];

    // Create message queues.
    msgid1 = create_message_queue((key_t) 1999);
    msgid2 = create_message_queue((key_t) 2001);

    // Print a list of valid commands.
    printf("Valid Commands: insert(integer goes here), sum, delete(integer goes here), average, min, median\n");

    // While running...
    while (running)
    {
        /* Ask for a command */

        printf("Enter a Command: ");
        fgets(buffer, MAX_TEXT, stdin);
        send_data.my_msg_type = 1;
        strcpy(send_data.some_text, buffer);

        /* Process the command. */

        if (strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
            printf("System Shutdown.\n");
            send_message(msgid1, (void *)&send_data, MAX_TEXT);
            break;
        }

        // Send the message to the calculator.
        send_message(msgid1, (void *) &send_data, MAX_TEXT);

        // Receieve the message from the calculator.
        receive_message(msgid2, (void *) &data_received, MAX_TEXT, msg_to_receive, 0);

        // Print the message from the calculator.
        printf("%s\n", data_received.some_text);
    }

    exit(EXIT_SUCCESS);
}
