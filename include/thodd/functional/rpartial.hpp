#ifndef __THODD_FUNCTIONAL_RPARTIAL_HPP__
#  define  __THODD_FUNCTIONAL_RPARTIAL_HPP__

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    inline constexpr auto
    rpartial = 
        [] (auto&& __func, auto&&... __params)
        {
            return as_functor (
            [__func, &__params...] (auto&&... __args)
            -> decltype(auto)
            {
                return 
                __func (static_cast<decltype(__args)&&>(__args)..., 
                       static_cast<decltype(__params)&&>(__params)...) ;
            }) ;
        } ;
}

#endif