//
// $Id: stringutils.h,v 1.1 2001/07/17 20:50:15 mcoletti Exp $
//
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>

namespace stringutils
{
   /// removes trailing whitespace from given string
   /**
      returns number of chracters so removed
    */
   size_t chomp( std::string & s );
} // namespace stringutils


#endif
