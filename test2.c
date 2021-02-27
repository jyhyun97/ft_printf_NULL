
#include <stdio.h>

int main ()
{
	printf("1|%0000000++++++++++++*d|\n",10, 123);
	printf("1.1|%*.*d|\n", -10, 7, -123);
	printf(" |1234567890|\n");
	printf("2|%*.4d|\n", -10,-10);
	printf("*|%-+*d|\n", 10,0);
	printf("3|%*s|\n",012,"123456789");
	printf("4|%0+10d|\n",-13);
	printf("5|%+010d|\n",-13);
	printf("6|%- d|\n",1234567890);
	printf("7|%- 10d|\n",-13);
	printf("8|%0 10d|\n",-13);
	printf("9|%+010d|\n",-13);
	printf(" |1234567890|");
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
