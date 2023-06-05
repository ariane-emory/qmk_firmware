#include <stdio.h>
#include <stdint.h>

void print_num(uint8_t num, const uint8_t max_digits) {
  const uint8_t size = max_digits + 1;
  char buf[size];
  uint8_t ix = size - 2;
  for (uint8_t i = 0; i < size; i++) buf[i] = 0;

  if (num == 0) {
    buf[size - 2] = '0';
    ix     = size - 2;
  } else {  
    while (num) {
      const uint8_t modulo = num % 10;
      printf("modulo '%d'\n", modulo);
    
      num -= modulo;
      num /= 10;
      buf[ix--] = 48 + modulo;
    }

    ix++;
  }
  
  printf("ix                   = %d\n", ix);
  printf("str    @ %p = '%s'\n", &buf[ix+1], &buf[ix]);
  
  for (uint8_t i = 0; i < size; i++)
    printf("buf[%d] @ %p = %d\n", i, &buf[i], buf[i]);

  printf("\n");
}

void print_num2(uint8_t num, const uint8_t max_digits) {
  char buf[max_digits];
  uint8_t ix = max_digits - 1;
  for (uint8_t i = 0; i < max_digits; i++) buf[i] = 0;

  if (num != 0) {
    while (num) {
      const uint8_t modulo = num % 10;
      printf("modulo '%d'\n", modulo);
    
      num -= modulo;
      num /= 10;
      buf[ix--] = modulo;
    }

    ix++;
  }
  
  printf("ix                   = %d\n", ix);
  printf("str     @ %p = '", &buf[ix+1]);
  while (ix < max_digits) {
    printf("%c", buf[ix] + 48);
    ix++;
  }
  printf("'\n");

  for (uint8_t i = 0; i < max_digits; i++)
    printf("buf[%d] @ %p = %d\n", i, &buf[i], buf[i]);

  printf("\n");
}

int main() {
//   print_num (219, 3);
  print_num2(219, 3);
//   print_num (29,  3);
  print_num2(29,  3);
//   print_num (7,   3);
  print_num2(7,   3);
//   print_num (0,   3);
  print_num2(0,   3);
}
