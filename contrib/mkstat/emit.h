//
// emit.h
//

#ifndef EMIT_H
#define EMIT_H

#include <string>
#include <iostream>

class sb_Module;
class sio_8211Writer;

// This function will take the state of the given builder module and
// emit it as a record to the given writer.
void emit(sb_Module const& module, sio_8211Writer& writer );



//
// emits a valid sed statement for converting the first string into the second
// into the given output stream
//
template <class T>
void
emit_sed(std::string const& orig_str, T const& val, std::ostream& os )
{
  os << "s/" << orig_str << "/" << val << "/g\n";

} // emit_sed



//
// This does what you'd expect.
//
inline
std::string
clipTrailingSpaces(std::string const& str)
{
  std::string tmp_str( str );

  std::string::size_type pos = tmp_str.find_last_not_of( " " );

  if (std::string::npos != pos) {
    tmp_str.resize( pos + 1 );
  }

  return tmp_str;
} // clipTrailingSpaces



#endif
