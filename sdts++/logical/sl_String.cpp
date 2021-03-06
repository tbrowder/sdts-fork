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

#include <sdts++/logical/sl_String.h>

using namespace std;

//
// sl_String
//

static std::string const string_object_code = "LS";


std::string const &
sl_String::objectCode() const
{
   return string_object_code;
} // sl_::objectCode()
