#include <iostream>
#include "RingBuffer.h"

using namespace std;

int main()
{

    int size  = 3 ;

    ring <string> text ( size ) ;

    text.add("harsh");
    text.add("saumya");
    text.add("akash");
    text.add("kulveer");

    for( int i = 0 ; i < text.size() ; i++)
    {
        cout << text.get(i) << endl ;
    }

    text.add("John") ;

    for ( ring<string>::iterator it = text.begin() ; it != text.end() ; it++)
    {

    }

    text.add("Reyna");

    for ( auto i : text)
    {
        cout << i << endl ;
    }


/**
    text.add ( "harsh" );
    text.add ( "saumya" );
    text.add ( "akash" );
    text.add ( "kulveer" );
*/

    return 0;
}
