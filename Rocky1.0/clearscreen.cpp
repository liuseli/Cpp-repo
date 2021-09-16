#include "clearscreen.h"
#include <cstdlib>
using namespace std;
void ClearScreen()
{
#ifdef WINDOWS
  system ( "CLS" );
#else
  // Assume POSIX
  system ( "clear" );
#endif
}