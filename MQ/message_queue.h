/**
 * @file message_queue.h
 * @author Jeremy Trendoff - 101160306
 * @brief A Header File for Message Queue Operations.
 */

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <sys/msg.h>

int create_message_queue(key_t key);
void send_message(int msgqid, void *send_buffer, int message_size);
void receive_message(int msgqid, void *receive_buffer, int message_size, int message_type, int msg_flg);
void delete_message_queue(int msgqid);

#endif