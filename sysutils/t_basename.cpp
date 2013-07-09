#include <iostream>
#include <cstdlib>

#include "fileutils.h"

using namespace std;

int
main( int argc, char** argv )
{
   if ( argv[1] )
      cout << fileutils::basename( argv[1] ) << "\n"; 
   else
      cout << fileutils::basename( string("") ) << "\n"; 

   exit( 0 );
}
