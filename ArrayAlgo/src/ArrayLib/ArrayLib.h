/*
 * ArrayLib.h
 *
 *  Created on: 12 Feb 2023
 *      Author: david
 */

#ifndef SRC_ARRAYLIB_H_
#define SRC_ARRAYLIB_H_

#include <inttypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern void list_values(int*, size_t);

extern void update_array(int*, size_t*, size_t, int);

extern size_t search_element(int*, size_t, int);

extern void delete_element(int *, size_t*, size_t);

#ifdef __cplusplus
}
#endif

#endif /* SRC_ARRAYLIB_H_ */
