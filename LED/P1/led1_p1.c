#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int led1_main(){
printf("led 1 (RUN)  Pattern 1");
printf("if want end: ctrl + c") ;

for(;;);
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.1s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.3s
  echo 0 > /sys/class/gpio/gpio491/value
  sleep 0.2s
  echo 1 > /sys/class/gpio/gpio491/value
  sleep 0.4s
  break;
}