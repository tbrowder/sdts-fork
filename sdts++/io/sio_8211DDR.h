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
// sio_8211DDR.h
//

#ifndef INCLUDED_SIO_8211DDR_H
#define INCLUDED_SIO_8211DDR_H

#include <iostream>

#include <sdts++/io/sio_8211DDRLeader.h>
#include <sdts++/io/sio_8211Record.h>

///    This corresponds to an 8211 Data Definition Record (DDR)
class sio_8211DDR : public sio_8211Record
{
public:

  ///
  virtual sio_8211Leader const& getLeader() const;

  ///
  sio_8211DDR();


protected:

  ///
  virtual sio_8211Leader& getLeader_();


private:

  ///
  std::istream& streamExtract(std::istream& istr);

  ///
  sio_8211DDRLeader leader_;

}; // sio_8211DDR

#endif  // INCLUDED_SIO_8211DDR_H
