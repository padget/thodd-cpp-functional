#ifndef __THODD_FUNCTIONAL_PLACEHOLDER_HPP__
#  define  __THODD_FUNCTIONAL_PLACEHOLDER_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        size_t index_c>
    constexpr auto 
    placeholder ()
    {
        return 
        [] (auto&& __arg, auto&&... __args)
        -> decltype(auto)
        {
            constexpr auto __subrank = placeholder<index_c - 1>(); 
            return __subrank(static_cast<decltype(__args)&&>(__args)...);
        };
    }


    template<> 
    constexpr auto 
    placeholder<0> ()
    {
        return 
        [] (auto&& __arg, auto&&... __args)
        -> decltype(auto)
        {
            return __arg;
        };
    }
    

    inline constexpr auto $0  = as_functor (placeholder<0>());
    inline constexpr auto $1  = as_functor (placeholder<1>());
    inline constexpr auto $2  = as_functor (placeholder<2>());
    inline constexpr auto $3  = as_functor (placeholder<3>());
    inline constexpr auto $4  = as_functor (placeholder<4>());
    inline constexpr auto $5  = as_functor (placeholder<5>());
    inline constexpr auto $6  = as_functor (placeholder<6>());
    inline constexpr auto $7  = as_functor (placeholder<7>());
    inline constexpr auto $8  = as_functor (placeholder<8>());
    inline constexpr auto $9  = as_functor (placeholder<9>());
    inline constexpr auto $10 = as_functor (placeholder<10>());
    inline constexpr auto $11 = as_functor (placeholder<11>());
    inline constexpr auto $12 = as_functor (placeholder<12>());
    inline constexpr auto $13 = as_functor (placeholder<13>());
    inline constexpr auto $14 = as_functor (placeholder<14>());
    inline constexpr auto $15 = as_functor (placeholder<15>());
}

#endif