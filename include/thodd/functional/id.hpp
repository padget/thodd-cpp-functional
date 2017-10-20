#ifndef __THODD_FUNCTIONAL_ID_HPP__
#  define __THODD_FUNCTIONAL_ID_HPP__

#  include <thodd/functional/placeholder.hpp>

namespace 
thodd
{
    inline constexpr auto
    id = 
    [] (auto && ... args) -> decltype(auto)
    {
        if constexpr (sizeof...(args) > 0)
            return 
            ($0 (static_cast<decltype(args)&&>(args)...)) ;
    } ;
}

#endif