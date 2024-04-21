#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

#include "string.hh"

int
main( void )
{
  std::vector< exam::string > strings;

  for( exam::string string_input; std::cin >> string_input; )
  {
    strings.push_back( std::move( string_input ) );
  }

  auto greater_lexicographically{
    []( const exam::string& left,
        const exam::string& right ) -> bool
    {
      std::size_t length{ std::max( left.length(),
                                    right.length() ) };

      for( std::size_t i{}; i < length; ++i )
      {
        char character_left{}, character_right{};

        if ( i < left.length() )
        {
          character_left = std::tolower( left[ i ] );
        }

        if( i < right.length() )
        {
          character_right = std::tolower( right[ i ] );
        }

        if( character_left != character_right )
        {
          return character_left > character_right;
        }
      }

      return false;
    }
  };

  std::sort( strings.begin(),
             strings.end(),
             greater_lexicographically );

  for( const auto& string: strings )
  {
    std::cout << string << '\n';
  }
}