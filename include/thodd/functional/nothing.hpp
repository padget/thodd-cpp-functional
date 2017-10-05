#ifndef __THODD_FUNCTIONAL_NOTHING_HPP__
#  define  __THODD_FUNCTIONAL_NOTHING_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * Nothing lambda returns a functor that returns nothing :D whatever the passed arguments.
     */
    inline constexpr auto 
    nothing = [] (auto && ... __args) {} ;
}

#endif