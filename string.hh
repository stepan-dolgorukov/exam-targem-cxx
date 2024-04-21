#ifndef STRING_HH
#define STRING_HH

#include <cstddef>

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

    ~string( void );

    std::size_t
    length( void ) const
    {
      return _length;
    }
  };
}

#endif