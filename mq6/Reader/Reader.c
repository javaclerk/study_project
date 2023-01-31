// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <string.h>
  
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
  
int main()
{
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
  
    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);
  
    // display the message
    printf("Data Received is : %s \n", 
                    message.mesg_text);


    //scanf("%s", a);

    if(strncmp(message.mesg_text, "led", 3) == 0)
	{
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("START TIME: %s \n", message.mesg_text); //st


		printf("!2\n");

        if(strncmp(message.mesg_text, "1", 1) == 0)
        {
            msgrcv(msgid, &message, sizeof(message), 1, 0);
            printf("END TIME: %s \n", message.mesg_text); //et

            if(strncmp(message.mesg_text, "1", 1) == 0)
            {
                msgrcv(msgid, &message, sizeof(message), 1, 0);
                printf("LED NUMBER: %s \n", message.mesg_text); //ln

                if (strncmp(message.mesg_text, "1", 1) == 0) //ln
                {
                    msgrcv(msgid, &message, sizeof(message), 1, 0);
                    printf("PATTERN NUMBER: %s \n", message.mesg_text); //ln

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    { ///home/psj/psj_docker/LED/P1/led1_p1.c
                        system("/home/root/led/led1_p1.c");
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        system("/home/root/led/led1_p2.c");
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        system("/home/root/led/led1_p3.c");
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "2", 1) == 0) //ln
                {
                    msgrcv(msgid, &message, sizeof(message), 1, 0);
                    printf("PATTERN NUMBER: %s \n", message.mesg_text); //ln

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    { ///home/psj/psj_docker/LED/P1/led1_p1.c
                        system("/home/root/led/led2_p1.c");
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        system("/home/root/led/led2_p2.c");
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        system("/home/root/led/led2_p3.c");
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "3", 1) == 0) //ln
                {
                    msgrcv(msgid, &message, sizeof(message), 1, 0);
                    printf("PATTERN NUMBER: %s \n", message.mesg_text); //ln

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    { ///home/psj/psj_docker/LED/P1/led1_p1.c
                        system("/home/root/led/led3_p1.c");
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        system("/home/root/led/led3_p2.c");
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        system("/home/root/led/led3_p3.c");
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "4", 1) == 0) //ln
                {
                    msgrcv(msgid, &message, sizeof(message), 1, 0);
                    printf("PATTERN NUMBER: %s \n", message.mesg_text); //ln

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    { ///home/psj/psj_docker/LED/P1/led1_p1.c
                        system("/home/root/led/led4_p1.c");
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        system("/home/root/led/led4_p2.c");
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        system("/home/root/led/led4_p3.c");
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "5", 1) == 0) //ln
                {
                    msgrcv(msgid, &message, sizeof(message), 1, 0);
                    printf("PATTERN NUMBER: %s \n", message.mesg_text); //ln

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    { ///home/psj/psj_docker/LED/P1/led1_p1.c
                        system("/home/root/led/led5_p1.c");
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        system("/home/root/led/led5_p2.c");
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        system("/home/root/led/led5_p3.c");
                        printf("LED PATTERN 3 \n");
                    }
                }

            }
        }
    }
    else
    {
        printf("false \n");
    }


  
    // to destroy the message queue
    // msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}
