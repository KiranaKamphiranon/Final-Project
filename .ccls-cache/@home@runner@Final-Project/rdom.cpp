#include <iostream>
#include <iomanip>
using namespace std;
#include "rdom.h"
#include "color.h"

int rdom::random_activities()
{
  meters=rand()%9;
  return meters;
}

int rdom::getcoin()
{
  coin=rand()%9;
  return coin;
}