#include<stdio.h>
// #include<stdlib.h>

int main(){
    // int i = 5;
    // int * pi = &i;
    // int ** ppi = &pi;
    // // size of any kind of pointer in c is the same
    // // 32bit system: 4 Byte, 64bit system: 8 Byte
    // printf("%d\n", sizeof(i));      
    // printf("%d\n", sizeof(pi));
    // printf("%d\n", sizeof(ppi));
    // printf("%d\n", sizeof(char));
    // printf("%d\n", sizeof(char *));
    // // pointer operations are based on the size of the data they are pointing to
    // printf("%p\n", pi);
    // printf("%p\n", pi+100);         // pi+toHex(4*100)
    // printf("%p\n", ppi);            
    // printf("%p\n", ppi+100);        // ppi+toHex(8*100)
    // printf("%p\n", ppi+0x100);      // ppi+(8*0x100)
    // printf("%p\n", ppi+0b100);      // ppi+toHex(8*0b100)
    // char c = 'z';
    // char * pc = &c;
    // printf("%p\n", pc);
    // printf("%p\n", pc+0x100);
    // printf("%d\n", sizeof(void *));
    // char ** p = calloc(8, sizeof(char *));
    // printf("%d\n", sizeof(p));
    // printf("%d\n", sizeof(*p));
    // printf("%d\n", sizeof(**p));

    int * p = 0x001000;
    printf("%p\n", p+5);
}