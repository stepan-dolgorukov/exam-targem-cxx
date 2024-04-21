#ifndef STRING_HH
#define STRING_HH

#include <cstddef>
#include <ostream>

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

    ~string( void );

    std::size_t
    length( void ) const
    {
      return _length;
    }

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
  };
}

#endif