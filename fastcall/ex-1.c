#include <stdio.h>

// input ecx, output eax
//
// compile : gcc -o ex-1 ex-1.c -z execstack


const char test[] = "\x31\xc0\x89\xc8\x40\xc3";

/*
     6 00000000 31C0                            xor     eax, eax
     7 00000002 89C8                            mov     eax, ecx
     8 00000004 40                              inc     eax
     9 00000005 C3                              ret

*/

static unsigned __attribute__((fastcall)) (*input)(unsigned) = test;

int main() {
                           // input
   printf("%d -> %d\n", 0, input(0));       // input = 0 , output = 1  
   return 0;
}
