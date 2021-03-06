//
// tomakedts.cpp
//


#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit function

#include "convert.h"

using namespace std;

void
usage( string const & fn )
{
  cerr << fn << " : [-v] SDTS-module\n"
       << "\t-v : toggle on noisy output\n";
} // usage



bool verbose = false;           // true if user wants noisy ouput


int
main( int argc, char** argv )
{
   extern char *optarg;		// getopt() variables
   extern int   optind;
   int   ch;

   while ((ch = getopt(argc, argv, "v")) != -1 )
      switch(ch) 
      {
         case 'v':
            verbose = true;           // verbose output
            break;

         case '?':
         default:
            usage( argv[0] );
            return -4;
      }

   if ( argc < 2 )
   {
      cerr << "need to specify an SDTS module\n";
      exit( 2 );
   }

   ifstream module_stream( argv[ optind ] );

   if ( ! module_stream )
   {
      cerr << "unable to open " << argv[ optind ] 
           << "\n";
      exit( 1 );
   }

   // convert to mksdts' SDTS Definition Language (c.f., mksdts(1) )
   convertToSDL( module_stream );

   exit( 0 );
}
