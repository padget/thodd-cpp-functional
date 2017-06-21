#ifndef __THODD_FUNCTIONAL_PLACEHOLDER_HPP__
#  define  __THODD_FUNCTIONAL_PLACEHOLDER_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        size_t index_c>
    constexpr auto 
    placeholder()
    {
        return 
        [](auto&& __arg, auto&&... __args)
        -> decltype(auto)
        {
            constexpr auto __subrank = placeholder<index_c - 1>(); 
            return __subrank(static_cast<decltype(__args)&&>(__args)...);
        };
    }


    template<> 
    constexpr auto 
    placeholder<0>()
    {
        return 
        [](auto&& __arg, auto&&... __args)
        -> decltype(auto)
        {
            return __arg;
        };
    }
    

    extern constexpr auto $0  = as_functor(placeholder<0>());
    extern constexpr auto $1  = as_functor(placeholder<1>());
    extern constexpr auto $2  = as_functor(placeholder<2>());
    extern constexpr auto $3  = as_functor(placeholder<3>());
    extern constexpr auto $4  = as_functor(placeholder<4>());
    extern constexpr auto $5  = as_functor(placeholder<5>());
    extern constexpr auto $6  = as_functor(placeholder<6>());
    extern constexpr auto $7  = as_functor(placeholder<7>());
    extern constexpr auto $8  = as_functor(placeholder<8>());
    extern constexpr auto $9  = as_functor(placeholder<9>());
    extern constexpr auto $10 = as_functor(placeholder<10>());
    extern constexpr auto $11 = as_functor(placeholder<11>());
    extern constexpr auto $12 = as_functor(placeholder<12>());
    extern constexpr auto $13 = as_functor(placeholder<13>());
    extern constexpr auto $14 = as_functor(placeholder<14>());
    extern constexpr auto $15 = as_functor(placeholder<15>());
}

#endif