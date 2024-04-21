#ifndef STRING_HH
#define STRING_HH

#include <cstddef>
#include <ostream>
#include <istream>

#include <iostream>

namespace exam
{
  class string
  {
  private:
    char* _content{ nullptr };
    std::size_t _length{ 0u };

  public:
    string( void ) = default;
    string( const char initial[] );
    string( const exam::string& source );
    string( char initial );
    string( exam::string&& source );

    ~string( void );

    std::size_t
    length( void ) const;

    exam::string&
    operator=( const exam::string& source );

    exam::string&
    operator=( const char source[] );

    exam::string
    operator+( const exam::string& operand_right );

    exam::string
    operator+( const char* operand_right );

    exam::string&
    operator+=( const exam::string& operand_right );

    exam::string&
    operator+=( const char* operand_right );

    char
    operator[]( std::size_t index ) const;

    friend
    std::ostream&
    operator<<( std::ostream& stream_output,
                const exam::string& string_output )
    {
      for( std::size_t i{ 0u }; i < string_output.length(); ++i )
      {
        stream_output << string_output._content[ i ];
      }

      return stream_output;
    }

    friend
    std::istream&
    operator>>( std::istream& stream_input,
                exam::string& string_output )
    {
      for( char character_in;
           stream_input.get( character_in ); )
      {
        if( stream_input.eof() || std::isspace( character_in ) )
        {
          return stream_input;
        }

        string_output += exam::string( character_in );
      }

      return stream_input;
    }
  };
}

#endif