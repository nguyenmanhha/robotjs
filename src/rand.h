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


// UTILS
float randBm(void);


#endif /* RAND_H */

#ifdef __cplusplus
}
#endif


