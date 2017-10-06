#ifndef __THODD_FUNCTIONAL_TUPLE_HPP__
#  define  __THODD_FUNCTIONAL_TUPLE_HPP__ 

#  include <utility>

#  include <thodd/functional/placeholder.hpp>

namespace
thodd
{
    inline constexpr auto
    tuple =
    [] (auto && ... item)
    {
        return 
        [item...] (auto && accessor)
        -> decltype(auto)
        {
            return 
            std::forward<decltype(accessor)>(accessor) (item...) ;
        } ;
    } ;

    inline constexpr auto
    size = 
    [] (auto && t)
    {
        return 
        std::forward<decltype(t)>(t) (
            [] (auto && ... item) { return sizeof...(item) ; }) ;
    } ;
        
    inline constexpr auto
    nth = 
    [] (auto && t, auto index)
    -> decltype(auto)
    {
        return
        std::forward<decltype(t)>(t) (
            placeholder<decltype(index)::value>()) ;
    } ;
        
    template <
        auto index_c>
    using index = std::integral_constant<decltype(index_c), index_c> ;

    inline constexpr auto idx0 = index<0>{} ;
    inline constexpr auto idx1 = index<1>{} ;
    inline constexpr auto idx2 = index<2>{} ;
    inline constexpr auto idx3 = index<3>{} ;
    inline constexpr auto idx4 = index<4>{} ;
    inline constexpr auto idx5 = index<5>{} ;
    inline constexpr auto idx6 = index<6>{} ;
    inline constexpr auto idx7 = index<7>{} ;
    inline constexpr auto idx8 = index<8>{} ;
    inline constexpr auto idx9 = index<9>{} ;
    inline constexpr auto idx10 = index<10>{} ;
    inline constexpr auto idx11 = index<11>{} ;
    inline constexpr auto idx12 = index<12>{} ;
    inline constexpr auto idx13 = index<13>{} ;
    inline constexpr auto idx14 = index<14>{} ;
}

#endif
