#include "binding/binding.h"
#include "binding/dynamicbinding/dynamicbinding.h"
#include "binding/dynamicbinding/finitestatebinding.h"
#include "binding/dynamicbinding/numericrangebinding.h"
#include "binding/bindingset.h"

int main( int argc, char *argv[] )
{

    /// @todo  Add configuration file read/write
    /// @todo  Add description to BindingState
    /// @todo  Add dump to file
    /// @todo  Add odometer dynamic bindings (gear)
    /// @todo  Add gui!

    BindingSet bs;

    FiniteStateBindingPtr aliasBinding( new FiniteStateBinding( "name", "alias", "Player name dynamic binding" ) );
    aliasBinding->addState( "primary", "Dusky" );
    aliasBinding->addState( "old", "whiskey.dick" );
    aliasBinding->addState( "alias", "void*" );
    bs.addBinding( "f3", aliasBinding );

    NumericRangeBindingPtr sensitivityBinding( new NumericRangeBinding( "sensitivity", "sense", "Mouse sensitivity dynamic binding" ) );
    sensitivityBinding->setRangeByStep( 0.1, 5.0, 0.1 );
    bs.addBinding( "f4", sensitivityBinding );

    QTextStream out( stdout );
    bs.print( out );
}
