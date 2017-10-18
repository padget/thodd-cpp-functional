#ifndef __THODD_FUNCTIONAL_COMPOSE_HPP__
#  define  __THODD_FUNCTIONAL_COMPOSE_HPP__ 

#  include <thodd/functional/demux.hpp>

namespace
thodd
{
    /**
     * Compose lambda returns the composition between __fsup and __finf ((__fsup o __finf)(...)).
     * For example :
     * compose(__fsup, __finf)(1, 2, 3) == __fsup(__finf(1, 2, 3)) 
     */
    inline constexpr auto 
    compose =
    [] (auto && __ffirst, auto && ... __fnext)
    {
        if constexpr (sizeof...(__fnext) > 1)
            return 
            demux (compose(static_cast<decltype(__fnext)&&>(__fnext)...)) 
                (static_cast<decltype(__ffirst)&&>(__ffirst));
        else if constexpr (sizeof...(__fnext) == 1)
            return 
            demux (static_cast<decltype(__fnext)&&>(__fnext)...) 
                (static_cast<decltype(__ffirst)&&>(__ffirst));
        else 
            return 
            static_cast<decltype(__ffirst)&&>(__ffirst) ;
    } ;
}

#endif