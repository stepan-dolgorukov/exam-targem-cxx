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

exam::string::string( const exam::string& source )
{
  delete[] _content;

  _length = source._length;
  _capacity = source._capacity;
  _content = new char[ _capacity ]{};

  std::memcpy( _content, source._content, _length );
}

exam::string::~string( void )
{
  delete[] _content;
}