#ifndef __THODD_FUNCTIONAL_CREF_HPP__
#  define  __THODD_FUNCTIONAL_CREF_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    cref = 
        [](auto const& __cref)
        {
            return as_functor(
            [&__cref] (auto&&... __args)
            -> decltype(auto)
            {
                return __cref;
            });
        };
}

#endif