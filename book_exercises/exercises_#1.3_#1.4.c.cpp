#include <stdio.h>
main ()
{
	printf("Celsius to Fahrenheit\n");
	float celsius, fahr;
	int lower, upper, step;
	lower = 0;
	upper = 200;
	step = 5;
	
	celsius = lower;
	while(celsius<=upper) {
		fahr = ((9.0/5.0)*celsius+32);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius+step;
	}
}
