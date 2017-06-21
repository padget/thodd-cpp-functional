#ifndef __THODD_FUNCTIONAL_BIND_HPP__
#  define  __THODD_FUNCTIONAL_BIND_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/demux.hpp>

namespace
thodd
{
    extern constexpr auto
    bind = 
        [](auto&& __func, auto&&... __funcs) 
        {
            return as_functor(
                demux(static_cast<decltype(__func)&&>(__func))
                (static_cast<decltype(__funcs)&&>(__funcs)...)) ;  
        } ;    
}

#endif