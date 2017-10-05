#ifndef __THODD_FUNCTIONAL_CREF_HPP__
#  define  __THODD_FUNCTIONAL_CREF_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * Cref lambda returns a functor that returns the __cref 
     * captured by reference whatever the passed arguments. 
     * For example:
     * int a = 5; 
     * auto __cref = cref(a);
     * __cref(12, 5, 6, 7, 9) == 5 
     * ++a;
     * __cref(12, 5, 6, 7, 9) == 6 // the value has changed thanks to reference capturing 
     */
    inline constexpr auto
    cref = 
    [] (auto const & __cref)
    {
        return 
        [&__cref] (...) constexpr
        -> decltype(auto)
        {
            return __cref ;
        } ;
    } ;
}

#endif