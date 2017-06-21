#ifndef __THODD_FUNCTIONAL_PARTIAL_HPP__
#  define  __THODD_FUNCTIONAL_PARTIAL_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    partial = 
        [](auto&& __func, auto&&... __params)
        {
            return as_functor(
            [__func, &__params...](auto&&... __args)
            -> decltype(auto)
            {
                return 
                __func(static_cast<decltype(__params)&&>(__params)..., 
                       static_cast<decltype(__args)&&>(__args)...) ;
            }) ; 
        } ;
}

#endif