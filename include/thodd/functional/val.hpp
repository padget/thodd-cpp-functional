#ifndef __THODD_FUNCTIONAL_VAL_HPP__
#  define  __THODD_FUNCTIONAL_VAL_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    val = 
        [](auto&& __val)
        {
            return as_functor(
            [__val](auto&&... __args)
            -> decltype(auto)
            {
                return __val;
            });
        };
}

#endif