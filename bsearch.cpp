#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()

/// Implements an iterative linear seach on an range [first; last) of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int * lsearch( int *first, int *last, int value )
{

    while(first != last){
      if (value == *first){
          return first;
      }
      first++;
    }
    return last; // STUB
}

/// Implements an interative binary search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int * bsearch_i( int *first, int *last, int value )
{
  auto ini (first);
  auto end (last);
  int * m;
  while(ini != end){

    m = ini + ((end-ini)/2);
    if(*m == value){
      return m;
    }else if(value < *m){
      end = m;
    }else{
      ini = m++;
      if(ini == (last-1)){
        return last;
      }
    }
  }
  return last;
}

int * bsearch_r( int *first, int *last,  int * abs_last, int value )
{
  auto ini (first);
  auto end (last);
  int * m;

    if(ini != end and end-ini>1){
      m = ini + ((end-ini)/2);
      if(*m == value){
        return m;
      }else if(value < *m){
        return bsearch_r(ini,m,abs_last,value);
      }
        return bsearch_r(m++,end,abs_last,value);
    }
    if(end - ini == 1 and *ini == value){
      return ini;
    }

  return abs_last;
}

int * tsearch_i(int * first, int * last, int value){

  auto ini (first);
  auto end (last);
  int * t1;
  int * t2;

  while(end-ini >= 1){
    t1 = ini + ((end - ini)/3);
    t2 = end - ((end - ini)/3);

    if (*t1 == value){
      return t1;
    }
    if(*t2 == value){
      return t2;
    }
    if(value < *t1){
      end = t1;
    }
    if(value > *t2){
      ini = t2;
    }
    if(value > *t1 and value < *t2){
      if(t2-t1>3){
        ini = t1;
        end = t2;
      }else{
        return t1+1;
      }
    }

  }

  return last;
}

int * tsearch_r(int * first, int * last, int * abs_last ,int value){

  auto ini (first);
  auto end (last);
  int * t1;
  int * t2;

  while(end-ini >= 1){
    t1 = ini + ((end - ini)/3);
    t2 = end - ((end - ini)/3);

    if (*t1 == value){
      return t1;
    }
    if(*t2 == value){
      return t2;
    }
    if(value < *t1){
      return tsearch_r(ini,t1,abs_last,value);
    }
    if(value > *t2){
      return tsearch_r(t2,end,abs_last,value);
    }
    if(value > *t1 and value < *t2){
      if(t2-t1>3){
        return tsearch_r(t1,t2,abs_last,value);
      }else{
        return t1+1;
      }
    }

  }

  return abs_last;
}
// Driver function.
int main()
{
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Data container.
    int targets[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 , 10,-4, 59,-6}; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
    for( const auto & e : targets )
    {
        // Look for target in the entire range.
        auto result = tsearch_r( std::begin(A), std::end(A), std::end(A),e );

        // Process the result
        if ( result != std::end(A) )
        {
            std::cout << ">>> Found \"" << e << "\" at position "
                      << std::distance(std::begin(A),result) << ".\n";
        }
        else
        {
            std::cout << ">>> Value \"" << e << "\" not found in array!\n";
        }
    }

    return 0;
}
