This project started with a copy of the USGS's SDTS++ (a C++ toolkit
for SDTS files) referenced at its home page:

  http://mcmcweb.er.usgs.gov/sdts/sdtsxx/index.html

from:

  http://thor-f5.er.usgs.gov/sdts/sdtsxx/sdts++-1.5.1.tar.gz

The following files and directories were removed from the original distribution:

  ./Windows/
  ./boost-build.jam
  ./Jamrules
  ./compile
  ./depcomp
  ./sysutils/
  ./Jamfile

We also removed all Makefiles, Jamfiles, and other obviously
auto-generated files.

We removed the Windows directory and the other files because we will
change to a CMake system eventually.  We are not interested in
supporting any other build systems.

We removed the sysutils directory because it is not needed on modern
Linux systems (nor on Windows).

It has been modified to get it to compile on a Debian 6.0.7 system.
