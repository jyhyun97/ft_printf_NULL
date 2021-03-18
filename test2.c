
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void test(const char *a, ...)
{
  va_list ap;

  va_start(ap, a);
  printf("%ll", va_arg(ap, long long));
  va_end(ap);
}

int main ()
{
  test("a", 1231123123123123);
	return 0;
}
//warning
//- 0 
//+ ' '

// %[flag][width][.precision][type]
//flag는 - 혹은 0
//width는 * 혹은 정수
//precision은 . 뒤에 * 혹은 정수(-는 X)
//type는 c,s,d...등
