#include <iostream>
#include <cstdlib> // for exit

#include <sdts++/container/sc_Record.h>
#include <sdts++/io/sio_Writer.h>
#include <sdts++/builder/sb_Module.h>

#include "emit.h"

extern bool verbose;

using namespace std;

void
emit( sb_Module const & module, 
      sio_8211Writer& writer )
{

  sc_Record record;
      
  if ( ! module.getRecord( record ) )
    {
      cerr << "unable to build record\n";
      exit( 1 );
    }

  if ( ! writer.put( record ) )
    {
      cerr << "problem writing module record\n";
      exit( 1 );
    }

  if ( verbose )
    {
      cout << record << "\n";
    }

} // emit
