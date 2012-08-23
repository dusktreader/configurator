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

    Binding::registerFactory( BindingPtr( new FiniteStateBinding() ) );
    Binding::registerFactory( BindingPtr( new NumericRangeBinding() ) );
    Binding::registerFactory( BindingPtr( new DirectBinding() ) );

    BindingSet bs;
    bs.load( "/data/personal/builds/configurator/test_in.xml" );
    bs.dump( "/data/personal/builds/configurator/test.cfg");
    bs.save( "/data/personal/builds/configurator/test_out.xml" );
}
