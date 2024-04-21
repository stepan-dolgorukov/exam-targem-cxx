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

exam::string&
exam::string::operator=( const exam::string& source )
{
  if( this == &source )
  {
    return *this;
  }

  delete[] _content;

  _length = source._length;
  _capacity = source._capacity;
  _content = new char[ _capacity ]{};

  std::memcpy( _content, source._content, _length );

  return *this;
}

exam::string
exam::string::operator+( const exam::string& operand_right )
{
  const std::size_t
    length_result{ this->length() + operand_right.length() };

  char* const content_result{ new char[ length_result + 1 ]{} };
  content_result[ length_result ] = '\0';

  std::memcpy( content_result,
               _content,
               length()        );

  std::memcpy( content_result + length(),
               operand_right._content,
               operand_right.length()     );

  return { content_result };
}