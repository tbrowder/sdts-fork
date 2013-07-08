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

#ifdef WIN32
#pragma warning( disable : 4786 )
#endif

#include <cstdlib>
#include <cstring>
#include <cstrings>

#include <boost/filesystem/path.hpp>

#include <sdts++/io/sio_Utils.h>
#include <sdts++/io/sio_ConverterFactory.h>

static const char * ident_ = 
  "$Id: sio_Utils.cpp,v 1.5 2002/10/07 20:44:24 mcoletti Exp $";

long
sio_Utils::getLong(char const* buf, long startpos, long length)
{
   // XXX There's probably a better way to do this, but I don't see it right now.

   char* tempBuf = new char[length+1];

   strncpy(tempBuf, buf + startpos, length);
   tempBuf[length] = '\0';

   long result = atol(tempBuf);

   delete [] tempBuf;

   return result;

} // sio_Utils::getLong

string
sio_Utils::getString(char const* buf, long startpos, long length)
{
   char* tempBuf = new char[length+1];

   strncpy(tempBuf, buf + startpos, length);
   tempBuf[length] = '\0';

   string result = tempBuf;

   delete [] tempBuf;

   return result;

} // sio_Utils::getString



void
sio_Utils::dumpConverterDictionary( sio_8211_converter_dictionary const & cd,
                                    ostream & os )
{

  for ( sio_8211_converter_dictionary::const_iterator i = cd.begin();
        i != cd.end();
        i++ )
    {
      os << (*i).first << " : ";

      if ( sio_ConverterFactory::instance()->get( "BI8" ) == (*i).second)
        {
          os << "BI8\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BI16" ) == (*i).second)
        {
          os << "BI16\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BI24" ) == (*i).second)
        {
          os << "BI24\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BI32" ) == (*i).second)
        {
          os << "BI32\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BUI8" ) == (*i).second)
        {
          os << "BUI8\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BUI16" ) == (*i).second)
        {
          os << "BUI16\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BUI24" ) == (*i).second)
        {
          os << "BUI24\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BUI32" ) == (*i).second)
        {
          os << "BUI32\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BFP32" ) == (*i).second)
        {
          os << "BFP32\n";
        }
      else if ( sio_ConverterFactory::instance()->get( "BFP64" ) == (*i).second)
        {
          os << "BFP64\n";
        }
      else
        os << "unknown\n";
    }

} // dump_converter_dictionary

bool
sio_Utils::find_file_case_insensitive(const string& orig_fname,
                                      string& insens_fname)
{
  // get dir from file name
  string dir   = fileutils::dirname(orig_fname);
  string fname = fileutils::basename(orig_fname);

  size_t L1 = fname.size();

  // check all files in the dir
  path p(dir);
  if (is_directory(p)) {
    vector<path> v;
    copy(directory_iterator(p), directory_iterator(), back_inserter(v));

    // sort, since directory iteration is not ordered on some file
    // systems
    sort(v.begin(), v.end());

    for (vec::const_iterator i = v.begin(); i != v.end(); ++i) {
      if (is_directory(*i))
        continue;

      size_t L2 = (*i).size();
      // match?
      if (L1 == L2) {
        if (!strncasecmp(orig_fname.c_str(), (*i).c_str(), L1)) {
          // a match
          insens_fname = *i;
          return true;
        }
      }
    }
  }
  else {
    assert(0 && "unexpected ERROR!");
  }

  return false
}
