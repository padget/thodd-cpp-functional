#ifndef __THODD_FUNCTIONAL_FIX_HPP__
#  define  __THODD_FUNCTIONAL_FIX_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    fix = 
        [](auto&& __func)
        {
            return as_functor(
            [__func](auto&&... __args)
            -> decltype(auto)
            {
                return 
                __func(
                    fix(__func), 
                    static_cast<decltype(__args)&&>(__args)...);
            });
        };
}

#endif