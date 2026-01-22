#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <Dummy.h>

int main(int argc, char* argv[])
{
	int8_t Value = 0;

	if (argc < 2) 
	{
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    Value = atoi(argv[1]);

    if (Dummy_PublicFunction(Value))
        printf("The Number (%d) is even\n", Value);
    else
        printf("The Number (%d) is odd\n", Value);

    return 0;
}