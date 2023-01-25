/**
 * @file message_queue.c
 * @author Jeremy Trendoff - 101160306
 * @brief Message Queue Operations.
 */

#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "message_queue.h"

/**
 * @brief Create a message queue object
 * 
 * @param key The key for the message queue.
 * @return int, the message queue id.
 */
int create_message_queue(key_t key)
{
    int msgqid = msgget(key, IPC_CREAT | 0600);
    if (msgqid == -1) {
        fprintf(stderr, "msgget failed\n");
        exit(EXIT_FAILURE);
    }
    return msgqid;
}

/**
 * @brief Send message to message queue.
 * 
 * @param msgqid int, the message queue id.
 * @param send_buffer void*, send_buffer
 * @param message_size int, message size.
 */
void send_message(int msgqid, void *send_buffer, int message_size)
{
    if (msgsnd(msgqid, send_buffer, message_size, 0) == -1) {
        fprintf(stderr, "msgsnd failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Receive message from message queue.
 * 
 * @param msgqid  int, the message queue id.
 * @param receive_buffer void*, the receive buffer.
 * @param message_size int, message size.
 * @param message_type int, message type.
 */
void receive_message(int msgqid, void *receive_buffer, int message_size, int message_type, int msg_flg)
{
    if (msgrcv(msgqid, receive_buffer, message_size, message_type, msg_flg) == -1) {
        fprintf(stderr, "msgrcv failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Delete message queue
 * @param msgqid int, the message queue id.
 */
void delete_message_queue(int msgqid) {
    if (msgctl(msgqid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl failed\n");
    }
}