//
// filename.h
//
// $Id: filename.h,v 1.2 2003/02/13 23:37:46 mcoletti Exp $
//

#include <string>

#include <sdts++/sdts-config.h>

// takes the given file name and converts it to all lower depending on
// what the global bool force_lowercase is set to

std::string filename(std::string const& fn);

#ifndef HAVE_BASENAME
// UNIX basename for those systems that lack it.
const char* basename(const char*);

// UNIX dirname for those systems that lack it.
std::string dirname(std::string const&);

#endif
