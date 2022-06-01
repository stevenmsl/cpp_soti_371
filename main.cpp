#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol11;

/*
Input: a = 1, b = 2
Output: 3
*/
tuple<int, int, int>
testFixture1()
{
  return make_tuple(1, 2, 3);
}

/*
Input: a = -2, b = 3
Output: 1
*/
tuple<int, int, int>
testFixture2()
{
  return make_tuple(-2, 3, 1);
}

/*
Input: a = 3, b = 5
Output: 8
*/
tuple<int, int, int>
testFixture3()
{
  return make_tuple(3, 5, 8);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.getSum(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.getSum(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.getSum(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}