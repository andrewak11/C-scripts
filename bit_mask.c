#include<stdio.h>
int main()
{
    int led=0xff; //value = 0b11111111
    printf("original value before masking = %d\n",led);
    led=led & 0xf0;
    printf("value after masking=%d\n",led);

    led=0xff; //value = 0b11111111
    printf("original value before masking = %d\n",led);
    led=led ^ 0xf0;
    printf("value after masking=%d",led);
}