//
// This file is part of the SDTS++ toolkit, written by the U.S.
// Geological Survey.  It is experimental software, written to support
// USGS research and cartographic data production.
// 
// SDTS++ is public domain software.  It may be freely copied,
// distributed, and modified.  The USGS welcomes user feedback, but makes
// no committment to any level of support for this code.  See the SDTS
// web site at http://mcmcweb.er.usgs.gov/sdts for more information,
// including points of contact.
//
//


#include <iostream>
#include <fstream>


using namespace std;


#include <sdts++/io/sio_8211Converter.h>
#include <sdts++/io/sio_Reader.h>
#include <sdts++/container/sc_Record.h>
#include <sdts++/builder/sb_Ring.h>


int
main( int argc, char** argv )
{

  if ( ! argv[1] ) 
    {
      cerr << "usage: " << argv[0] << " RING module " << endl;
      exit( 1 );
    }

#ifdef WIN32
  ifstream ddf( argv[1], ios::binary );
#else
  ifstream ddf( argv[1] );
#endif

  if ( ! ddf ) 
    {
      cerr << "couldn't open " << argv[1] << endl;
      exit( 2 );
    }

  sio_8211Reader  reader( ddf );
  sc_Record record;
  sb_Ring sb_ring;

  for( sio_8211ForwardIterator i( reader );
        ! i.done();
        ++i )
   {
     i.get( record );

     if ( ! sb_ring.setRecord( record ) ) 
      {
	    cerr << " sb_ring::setRecord() failed\n";
	    abort();
      }
     else
     {
        cout << "what we read in:\n";
        cout << record << endl;

        sb_ring.setRecord( record );

        cout << "\nand what the RING object says it is:\n";
        cout << sb_ring << endl;

     
      }
  }

  exit(0);
}
