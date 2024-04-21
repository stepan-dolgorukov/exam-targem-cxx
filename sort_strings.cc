#include <iostream>
#include <vector>
#include <algorithm>

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
        const exam::string& right )
    {
      std::size_t length{ std::max( left.length(),
                                    right.length() ) };

      for( std::size_t i{}; i < length; ++i )
      {
        if( left[ i ] != right[ i ] )
        {
          return left[ i ] > right[ i ];
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