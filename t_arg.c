#include <stdio.h>
#include <stdarg.h>

double average(double value, ...)
{
	double sum;
	int    n;
	va_list ap;

	sum = 0;
	n = 0;
	va_start(ap, value);
	while (ap != 0)
	{
		sum += value;
		n++;
		value = va_arg(ap, double);
	}
	va_end(ap);
	return (sum/n);
}

int main(void)
{
	printf("average: %.3lf\n", average(2.0, 1.0, 4.0));
	return (0);
}