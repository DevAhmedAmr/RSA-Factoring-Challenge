#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int factorize(char *buffer);

unsigned long int _atoi(char *line);
int main(int argc, char **argv)
{
	char *line = NULL;

	(void)argc;
	size_t size = 0;
	FILE *file = fopen(argv[1], "r");

	while (getline(&line, &size, file) != -1)
	{
		u_int32_t num, i = 2;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		num = _atoi(line);

		factorize(line);
	};

	free(line);
	line = NULL;
	fclose(file);
}
unsigned long int _atoi(char *line)
{
	unsigned long int sum = 0, i = 0;
	int is_negative = 0;

	if (line[0] == '-')
	{
		is_negative = 1;
		i = 1;
	}

	for (; i < strlen(line); i++)
	{
		sum = sum * 10;
		sum += line[i] - 48;
	}

	if (is_negative)
	{
		sum = sum * -1;
	}
	return sum;
}
int factorize(char *buffer)
{

	u_int32_t num;
	u_int32_t i;

	num = atoi(buffer);

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, num / i, i);
			break;
		}
	}

	return (0);
}