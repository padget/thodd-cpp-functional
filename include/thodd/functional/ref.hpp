#ifndef __THODD_FUNCTIONAL_REF_HPP__
#  define  __THODD_FUNCTIONAL_REF_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    ref = 
        [](auto& __ref)
        {
            return as_functor(
            [&__ref](auto&&... __args)
            -> decltype(auto)
            {
                return __ref;
            });
        };
}

#endif