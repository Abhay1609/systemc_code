
#include  "half_adder.h"

void half_adder::addition()
{
    sum = a ^ b;
    carry = a & b;
}