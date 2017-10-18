
#ifndef __THODD_FUNCTIONAL_DEMUX_HPP__
#  define  __THODD_FUNCTIONAL_DEMUX_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * Demux lambda returns a functor that apply all __funcs to the arguments passed to function __func
     * For example:
     * demux(f)(g1, g2, g3)(1, 2, 3) == f(g1(1, 2, 3), g2(1, 2, 3), g3(1, 2, 3))
     */
    inline constexpr auto 
    demux = 
    [] (auto && __func)
    {
        return 
        [__func] (auto && ... __funcs)
        {
            return
            [__func, __funcs...] (auto && ... __args)
            -> decltype(auto)
            {
                return 
                __func(__funcs(static_cast<decltype(__args)&&>(__args)...)...) ;
            } ;
        } ;
    } ;
}

#endif