#ifndef __THODD_FUNCTIONAL_ALWAYS_HPP__
#  define  __THODD_FUNCTIONAL_ALWAYS_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto 
    always = 
        [] (auto&& __arg)
        {
            return 
            as_functor(
                [__arg] (auto&&... __args)
                -> decltype(auto)
                {
                    return __arg ;
                }) ;
        } ;
}

#endif