#ifndef __THODD_FUNCTIONAL_BIND_HPP__
#  define  __THODD_FUNCTIONAL_BIND_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/demux.hpp>

namespace
thodd
{
    /**
     * Bind lambda returns a functor that bind the function __func and the argument __args.
     * For example :
     * constexpr auto add = [](auto&& __a, auto&& __b) { return a + b ; } ;
     * bind(add, val(4), $0)(1) == add(4, 1) == 5 
     */ 
    extern constexpr auto
    bind = 
        [](auto&& __func, auto&&... __args) 
        {
            return as_functor(
                demux(static_cast<decltype(__func)&&>(__func))
                (static_cast<decltype(__args)&&>(__args)...)) ;  
        } ;    
}

#endif