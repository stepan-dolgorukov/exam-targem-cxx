#include <cstring>
#include <cstddef>

#include "string.hh"

exam::string::string( const char initial[] )
{
  if( nullptr == initial )
  {
    return;
  }

  std::size_t length{ strlen( initial ) };

  if( 0 == length )
  {
    return;
  }

  _content = new char[ length ]{};
  _length = _capacity = length;

  std::memcpy( _content, initial, length );
}

exam::string::~string( void )
{
  delete[] _content;
}