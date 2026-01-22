#include <stdint.h>
#include <stdbool.h>

#include "Dummy.h"

//returns true if value is even, false otherwise
bool Dummy_PublicFunction(int8_t Value)
{
    return (Value % 2) == 0;
}
