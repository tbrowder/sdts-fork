#include <iostream>
#include <cstdlib>

#include "fileutils.h"

using namespace std;

int
main( int argc, char** argv )
{
   if ( argv[1] )
      cout << fileutils::dirname( argv[1] ) << "\n"; 
   else
      cout << fileutils::dirname( string("") ) << "\n"; 

   exit( 0 );
}
