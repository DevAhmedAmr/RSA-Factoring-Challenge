#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long int _atoi(char *line);
int main(int argc, char **argv)
{
	char *line = NULL;

	(void)argc;
	size_t size = 0, i = 2;
	FILE *file = fopen(argv[1], "r");

	while (getline(&line, &size, file) != -1)
	{
		unsigned long int num;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		num = _atoi(line);

		while (i < num)
		{
			if (num % i == 0)
			{
				unsigned long int x = num / i;
				printf("%lu=%lu*%lu\n", num, x, i);
				break;
			}
			i++;
		}
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
