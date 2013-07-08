#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

namespace fileutils
{
   std::string dirname( std::string const & path );

   std::string basename( std::string const & path );

} // namespace fileutils


#endif
