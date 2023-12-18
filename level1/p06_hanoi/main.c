#include<stdio.h>
#include<windows.h>
void work(char a,char b,int k){
     if(k==1){
         printf("%c -> %c\n",a,b);
         return ;
     }
     char d='A'+'B'+'C'-a-b;
     work(a,d,k-1);
     work(a,b,1);
     work(b,d,k-1);
}
int main() {
    int num;
    printf("Please enter the num of the plates:");
    scanf("%d",&num);
    work('A','C',num);
    return 0;
}
