
#include "password_generator.h"

#include "../backdoor.h"

#include <string.h>
#include <stdint.h>

static int rdrand64 (uint64_t *rand);

/**
\brief Reads a random number from the CPU
\param rand The output variable to store the uint64 number
\return 0 on failure, != 0 on success
*/
int rdrand64 (uint64_t *rand)
{
        unsigned char ok;

        asm volatile ("rdrand %0; setc %1"
                : "=r" (*rand), "=qm" (ok));
	
        return (int) ok;
}

int generate_password( char *output, unsigned int len )
{
	int i;
	
	for ( i = 0; i < len; ++i )
	{
		uint64_t rand = 0;
		
		if ( rdrand64( &rand ) )
			output[i] = 'a' + rand % 26;
		else
			return -1;
	}
	
	return 0;
}

