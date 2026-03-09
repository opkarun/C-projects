#include <stdio.h>
#include <stdarg.h>
#include <string.h>
void karunf(char print[],...){
int len = strlen(print);
char put='\0';
va_list args;
va_start(args,print);
for(int i=0;i<len;i++){
put = print[i];
if(put!='%'){
putchar(put);
}
else{
if(i+1<len){
i++;
switch(print[i]){
case 'c':
    put = va_arg(args,int);
    putchar(put);
    break;
case '%':
    putchar('%');
    break;
case 'd':{
    int real = va_arg(args,int);
    unsigned int value;
    if(real<0){
        putchar('-');
        value = (unsigned)-(real+1)+1;
    }
    else{
        value=(unsigned)real;
    }
    if(value == 0){
        putchar('0');

    }
    else{

    int dig_c = 0;
    unsigned int temp = value;
    unsigned int tempfill = value;
    //while(temp!=0){//just counting the digits of a number, not usedd
        //temp= temp/10;
        //dig_c++;
    
    int arr[12];
    int counter = 0;
    while(tempfill!=0){
        arr[counter] = tempfill%10;
        tempfill = tempfill/10;
        counter++;
        }
    for (int j=counter-1;j>=0;j--){
        //printf("\n%d",arr[i]);
        int out = '0' + arr[j];
        putchar(out);

        }

    }
    break;
}
case 's':{
char *str = va_arg(args,char *);
while(*str!='\0'){
    putchar(*str);
    str++;
}
break;
}
default:
}
}
else{
putchar('%');
}
}

}
va_end(args);
}



int main() {
// Your code implementation goes here
karunf("%% hi my name is%sand i am %d years old and my grade is %c %","" ,0,'O');

return 0;
}