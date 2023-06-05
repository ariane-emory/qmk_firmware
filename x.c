#include <stdio.h>
#include <stdint.h>

void print_num(uint8_t num, const uint8_t size) {
  const uint8_t siz = 5;
  char buf[siz] = { 0 };
  uint8_t ix = siz - 2;
    
  while (num) {
    const uint8_t modulo = num % 10;
    printf("modulo '%d'\n", modulo);
    
    num -= modulo;
    num /= 10;
    if (modulo == 0) {
      buf[ix--] = 48 + modulo;
    } else {
      buf[ix--] = 48 + modulo;
    }
  }
    
  printf("\nstr  @ %p   = '%s'\n", &buf[ix+1], &buf[ix+1]);
  printf("ix                   = %d\n", ix);
  printf("\n");
  
  for (uint8_t i = 0; i < siz; i++)
    printf("buf[%d] @ %p = %d\n", i, &buf[i], buf[i]);

  printf("\n");
}

int main() {
  print_num(123, 5);
  print_num(123, 4);
}
