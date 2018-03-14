#include "../include/header.h"
/// Implements an iterative linear seach on an range [first; last) of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int * linear_s_i( int *first, int *last, int * abs_last, int value )
{
    while(first != last){
        if(*first == value){
            return first;
        }else{
            first++;
        }
    }
    return abs_last; // STUB
}
