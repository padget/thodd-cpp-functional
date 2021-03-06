#ifndef __THODD_FUNCTIONAL_ALWAYS_HPP__
#  define  __THODD_FUNCTIONAL_ALWAYS_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{ 
    /**
     * Always lambda returns the __arg passed as parameter whatever the arguments.
     * For example :
     * always(2)('a', 12, "foo") == 2 
     */ 
    inline constexpr auto 
    always = 
    [] (auto && __arg)
    {
        return 
        [&] (auto && ... __args)
        -> decltype(auto)
        {
            return __arg ;
        } ;
    } ;
}

#endif
