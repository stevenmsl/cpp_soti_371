#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol11;
using namespace std;

/*takeaways
  - The constant 0x7FFFFFFF is a 32-bit integer in hexadecimal with all
    but the highest bit set.
    - this is to allow to reset the most significant digit in
      a negative number to zero to allow it to be left shifted for
      carry
  - a = 3 = (11), b = 5 = (111), a + b = 8 (1110)
    - let's just look at the lowest bit
    - produce sum 0 (111[0]) using XOR
      - 1 + 1 = 0
      - 1 + 0 = 1
      - 1 + 1 = 0 (as it will carry to the next higher bit)
      - 0 + 1 = 1
      - if we ignore the carry to the higher bit this is the XOR
        operation
    - so now the sum is 0 (as we ignore the carry while calculating the sum)
    - let's look at the carry now
      - only 1 + 1 will trigger a carry so it's (a&b) << 1
      - so the carry is now (10)
    - we then add the sum and carry together to get the result
  - the carry will change following this path 10 -> 100 -> 1000
*/

int Solution::getSum(int a, int b)
{
  if (b == 0)
    return a;
  /*
     - add sum and previous carry
       from the lower bit together
       to produce a new sum
     - remember we still
       ignore carry when producing
       the new result in this step
     - just think of it as adding
       another two new numbers
  */
  auto sum = a ^ b;
  /* calculate the new carry for the next higher bit  */
  auto carry = (a & b & 0x7fffffff) << 1;

  return getSum(sum, carry);
}