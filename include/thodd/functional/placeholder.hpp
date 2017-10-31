#ifndef __THODD_FUNCTIONAL_PLACEHOLDER_HPP__
#  define  __THODD_FUNCTIONAL_PLACEHOLDER_HPP__ 

#  include <utility>



namespace
thodd
{
    template <
        auto index_c>
    inline constexpr auto 
    placeholder = 
    [] {
        return 
        [] (auto && first, auto && ... next)
        -> decltype(auto)
        {
            constexpr auto subrank = placeholder<index_c - 1>() ; 
            
            if constexpr (index_c == 0)
                return (first) ;
            else 
                return (subrank (std::forward<decltype(next)>(next)...)) ;
        } ;
    } ;

    

    inline constexpr auto $0  = placeholder<0>() ;
    inline constexpr auto $1  = placeholder<1>() ;
    inline constexpr auto $2  = placeholder<2>() ;
    inline constexpr auto $3  = placeholder<3>() ;
    inline constexpr auto $4  = placeholder<4>() ;
    inline constexpr auto $5  = placeholder<5>() ;
    inline constexpr auto $6  = placeholder<6>() ;
    inline constexpr auto $7  = placeholder<7>() ;
    inline constexpr auto $8  = placeholder<8>() ;
    inline constexpr auto $9  = placeholder<9>() ;
    inline constexpr auto $10 = placeholder<10>() ;
    inline constexpr auto $11 = placeholder<11>() ;
    inline constexpr auto $12 = placeholder<12>() ;
    inline constexpr auto $13 = placeholder<13>() ;
    inline constexpr auto $14 = placeholder<14>() ;
    inline constexpr auto $15 = placeholder<15>() ; 
}

#endif
