#include <stdio.h>

struct pkt{
char ch1;
char ch2[2];
char ch3;
};
int main(){
unsigned int n;
printf("Enter the number:");
scanf("%d",&n);
struct pkt p1;
p1.ch1=(n >> 0) & 0xFF;
p1.ch2[0]=(n >> 8) & 0xFF;
p1.ch2[1]= (n >> 16) & 0xFF;
p1.ch3=(n >> 24) & 0xFF;
printf("The 1st byte is: %d\n",p1.ch1);
printf("The 2nd byte is: %d\n",p1.ch2[0]);
printf("The 3rd byte is: %d\n",p1.ch2[1]);
printf("The 4th byte is: %d\n",p1.ch3);
printf("1st member of the structure: %d\n",p1.ch1);
printf("2nd members of the structure: %d , %d\n",p1.ch2[0],p1.ch2[1]);
printf("3rd member of the structure: %d\n",p1.ch3);

int val=(int)(p1.ch3<<24)+(int)(p1.ch2[1]<<16)+(int)(p1.ch2[0]<<8)+(int)(p1.ch1);
printf("Aggregated number: %d",val);
return 0;
}