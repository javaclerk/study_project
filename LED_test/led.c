#include <stdlib.h>
#include <stdio.h>

#define SYS_GPIO_DIR "/sys/class/gpio"

int main(int argc, char** argv){
    int port_num=174, val, i;
    char buff[256];
    FILE *fp;

    snprintf(buff, sizeof(buff), "%s/export", SYS_GPIO_DIR);
    fp = fopen(buff, "w");
    fprintf(fp, "%d\n", port_num);
    fclose(fp);

    snprintf(buff, sizeof(buff),
        "%s/gpio%d/direction", SYS_GPIO_DIR, port_num);
    fp = fopen(buff, "w");
    fprintf(fp, "out\n");
    fclose(fp);

    snprintf(buff, sizoef(buff),
        "%s/gpio%d/value", SYS_GPIO_DIR, port_num);
    fp = fopen(buff, "w");
    setvbuf(fp, NULL, _IONBF, 0);

    val = 0;
    for (i=0; i<10; i++){
        fprintf(fp, "%d\n", val);
        sleep(1);
        val = !val;
    }

    fclose(fp);

    snprintf(buff, sizeof(buff), "%s/unexport", SYS_GPIO_DIR);
    fp = fopen(buff, "w");
    fprintf(fp, "%d\n", port_num);
    fclose(fp);

    return 0;
}