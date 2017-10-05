#ifndef __THODD_FUNCTIONAL_VAL_HPP__
#  define  __THODD_FUNCTIONAL_VAL_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * Val lambda returns a functor that returns the __ref 
     * captured by reference whatever the passed arguments. 
     * For example:
     * int a = 5; 
     * auto __v = val(a) ;
     * __v() == 5
     */
    inline constexpr auto
    val = 
    [] (auto&& __val)
    {
        return 
        [=] (...) { return __val ; } ;
    } ;
}

#endif