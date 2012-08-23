#include "binding.h"
#include "dynamicbinding.h"
#include "finitestatebinding.h"
#include "bindingset.h"

int main( int argc, char *argv[] )
{

    /// @todo  Add configuration file read/write
    /// @todo  Add description to BindingState
    /// @todo  Add dump to file
    /// @todo  Add int and real range dynamic bindings
    /// @todo  Add odometer dynamic bindings (gear)
    /// @todo  Add gui!

    BindingSet bs;
    FiniteStateBindingPtr binding0( new FiniteStateBinding( "name", "alias", "Player name dynamic binding" ) );
    binding0->addState( "primary", "Dusky" );
    binding0->addState( "old", "whiskey.dick" );
    binding0->addState( "alias", "void*" );
    bs.addBinding( "f3", binding0 );

    QTextStream out( stdout );
    bs.print( out );
}
