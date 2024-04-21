#ifndef STRING_HH
#define STRING_HH

#include <cstddef>
#include <ostream>
#include <istream>

namespace exam
{
  class string
  {
  private:
    char* _content{ nullptr };

    std::size_t
      _length{ 0u },
      _capacity{ 0u };

  public:
    string( void ) = default;
    string( const char initial[] );
    string( const exam::string& source );
    string( char initial );

    ~string( void );

    std::size_t
    length( void ) const;

    exam::string&
    operator=( const exam::string& source );

    exam::string
    operator+( const exam::string& operand_right );

    exam::string&
    operator+=( const exam::string& operand_right );

    friend
    std::ostream&
    operator<<( std::ostream& stream_out,
                const exam::string& str_out )
    {
      for( std::size_t i{ 0u }; i < str_out.length(); ++i )
      {
        stream_out << str_out._content[ i ];
      }

      return stream_out;
    }

    friend
    std::istream&
    operator>>( std::istream& stream_input,
                exam::string& str_output    )
    {
      for( char character_in;
           stream_input >> character_in; )
      {
        str_output += exam::string( character_in );
      }

      return stream_input;
    }
  };
}

#endif