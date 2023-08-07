#include <stdio.h>
#include <stdlib.h>

int check_for_endians(){
    unsigned int x=1;
    char * c=(char*) &x;
    return (int)*c;
}
void convert(unsigned int num)
{
    int ctr=0;
    ctr|=(num & 0x000000FF)<<24;
    ctr|=(num & 0x0000FF00)<<8;
    ctr|=(num & 0x00FF0000)>>8;
    ctr|=(num & 0xFF000000)>>24;
    printf("\nAfter conversion from little to big endian the value is:0x%x",ctr);
}
int main()
{
    printf("Checking whether the host machine is Little Endian or Big Endian: \n");
    int check=check_for_endians();
    if(check==1){
        printf("Little Endian\n");
    }
    else{
        printf("Big Endian\n");
    }

    unsigned int num;
    int i;
    printf("Enter a 4 byte hexadecimal number:");
    scanf("%x",&num);
    unsigned char *ptr=(unsigned char *) &num;
    printf("\nContents of each memory location:");
    for(i=0;i<4;i++)
    printf("\nValue:0x%x,memory location:%p",*(ptr+i),(ptr+i));
    convert(num);
    


    return 0;
}