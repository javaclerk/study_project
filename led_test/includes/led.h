int i;

if(ledSetup()==-1)retunr -1;

for(i=0;i<5;i++){
    digitalWrite(29,1);
    delay(500);
    digitalWrite(29,0);
    delay(500);
}
return 0;