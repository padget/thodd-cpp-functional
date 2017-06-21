
#ifndef __THODD_FUNCTIONAL_DEMUX_HPP__
#  define  __THODD_FUNCTIONAL_DEMUX_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto 
    demux = 
        [](auto&& __func)
        {
            return 
            [&__func](auto&&... __funcs)
            {
                return 
                as_functor( 
                    [__func, __funcs...](auto&&... __args)
                    -> decltype(auto)
                    {
                        return __func(__funcs(static_cast<decltype(__args)&&>(__args)...)...) ;
                    }) ;
            } ;
        } ;
}

#endif