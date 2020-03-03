#pragma once
#ifndef RAND_H
#define RAND_H

#if defined(_MSC_VER)
	#include "ms_stdbool.h"
#else
	#include <stdbool.h>
#endif
#ifdef __cplusplus
extern "C"
{
#endif


float randBm(void);
unsigned int randTimeBm(unsigned int min, unsigned int max);
unsigned int randTimeSin(unsigned int min, unsigned int max);


#endif /* RAND_H */

#ifdef __cplusplus
}
#endif


