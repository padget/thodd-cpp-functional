#ifndef __THODD_FUNCTIONAL_COMPOSE_HPP__
#  define  __THODD_FUNCTIONAL_COMPOSE_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/demux.hpp>

namespace
thodd
{
    extern constexpr auto
    compose = 
        [](auto&& __fsup, auto&& __finf) 
        {
            return as_functor(
                demux(static_cast<decltype(__fsup)&&>(__fsup))
                (static_cast<decltype(__finf)&&>(__finf))) ;
        } ;
}

#endif