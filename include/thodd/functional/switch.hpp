#ifndef __THODD_FUNCTIONAL_SWITCH_HPP__
#  define __THODD_FUNCTIONAL_SWITCH_HPP__

#  include <thodd/functional/fix.hpp>
#  include <thodd/functional/tuple.hpp>

namespace
thodd
{
    inline constexpr auto
    case_ = bind (tuple, $0, $1) ;

    inline constexpr auto
    switch_ = 
    [] (auto object) 
    {
        return
        [object] (auto c, auto ... cs)
        {
            constexpr auto 
            first_of = fix([] (
                auto const & fpt,
                auto && object, 
                auto const & c, 
                auto const & ... cs) 
            {
                return 
                [fpt, object, c, cs...] (auto && ... args)
                {
                    if (nth(c, idx0)(object(std::forward<decltype(args)>(args)...)))
                        nth(c, idx1)(object(std::forward<decltype(args)>(args)...)) ;  
                    else if constexpr (sizeof...(cs) > 0)
                        fpt (object, cs...) (std::forward<decltype(args)>(args)...);     
                } ;
            }) ; 

            return 
            [first_of, object, c, cs...] (auto && ... args)
            { first_of (object, c, cs...) (std::forward<decltype(args)>(args)...) ; } ;
        } ;
    } ;
}

#endif