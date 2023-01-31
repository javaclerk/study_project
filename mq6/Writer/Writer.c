// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

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
    message.mesg_type = 1;
  
    printf("Choose Commands: led, temp, gps \n");
    fgets(message.mesg_text,MAX,stdin);
  
    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);
  
    // // display the message
    // printf("Data send is : %s \n", message.mesg_text);

    if (strncmp(message.mesg_text, "led", 3) == 0)
    {
        printf("INPUT START TIME:  \n"); //st
        fgets(message.mesg_text,MAX,stdin);
  
        // msgsnd to send message
        msgsnd(msgid, &message, sizeof(message), 0);
  
        // display the message
        printf("START TIME is : %s \n", message.mesg_text);

        if (strncmp(message.mesg_text, "1", 1) == 0) //et
        {
            printf("INPUT END TIME:  \n");
            fgets(message.mesg_text,MAX,stdin);
            msgsnd(msgid, &message, sizeof(message), 0);
            printf("END TIME is : %s \n", message.mesg_text);
            
            if (strncmp(message.mesg_text, "1", 1) == 0) //ln
            {
                printf("Choose LED NUMBER: 1, 2, 3, 4, 5 \n");
                fgets(message.mesg_text,MAX,stdin);
                msgsnd(msgid, &message, sizeof(message), 0);
                printf("LED NUMBER is : %s \n", message.mesg_text);

                if (strncmp(message.mesg_text, "1", 1) == 0) //ln
                {
                    printf("Choose PATTERN NUMBER: 1, 2, 3 \n");
                    fgets(message.mesg_text,MAX,stdin);
                    msgsnd(msgid, &message, sizeof(message), 0);
                    printf("PATTERN NUMBER is : %s \n", message.mesg_text);

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    {
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "2", 1) == 0) //ln
                {
                    printf("Choose PATTERN NUMBER: 1, 2, 3 \n");
                    fgets(message.mesg_text,MAX,stdin);
                    msgsnd(msgid, &message, sizeof(message), 0);
                    printf("PATTERN NUMBER is : %s \n", message.mesg_text);

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    {
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "3", 1) == 0) //ln
                {
                    printf("Choose PATTERN NUMBER: 1, 2, 3 \n");
                    fgets(message.mesg_text,MAX,stdin);
                    msgsnd(msgid, &message, sizeof(message), 0);
                    printf("PATTERN NUMBER is : %s \n", message.mesg_text);

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    {
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "4", 1) == 0) //ln
                {
                    printf("Choose PATTERN NUMBER: 1, 2, 3 \n");
                    fgets(message.mesg_text,MAX,stdin);
                    msgsnd(msgid, &message, sizeof(message), 0);
                    printf("PATTERN NUMBER is : %s \n", message.mesg_text);

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    {
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        printf("LED PATTERN 3 \n");
                    }
                }
                //--
                else if (strncmp(message.mesg_text, "5", 1) == 0) //ln
                {
                    printf("Choose PATTERN NUMBER: 1, 2, 3 \n");
                    fgets(message.mesg_text,MAX,stdin);
                    msgsnd(msgid, &message, sizeof(message), 0);
                    printf("PATTERN NUMBER is : %s \n", message.mesg_text);

                    if(strncmp(message.mesg_text, "1", 1) == 0)
                    {
                        printf("LED PATTERN 1 \n");
                    }
                    else if(strncmp(message.mesg_text, "2", 1) == 0)
                    {
                        printf("LED PATTERN 2 \n");
                    }
                    else if(strncmp(message.mesg_text, "3", 1) == 0)
                    {
                        printf("LED PATTERN 3 \n");
                    }
                }

            }
        }

          

    }
    else
    {
        printf("false");
    }


  
    return 0;
}