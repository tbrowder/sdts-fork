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
