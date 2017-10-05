#ifndef __THODD_FUNCTIONAL_FIX_HPP__
#  define  __THODD_FUNCTIONAL_FIX_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * Fix lambda returns a functor that implements the fix point pattern.
     * For example : 
     * fix(f)(1,2,3) == f(f, 1, 2, 3)
     * f (auto&& func, auto first, auto ... next) 
     * {
     *      if (sizeof...(next))
     *          return 0 ;
     *      else 
     *          return 1 + func(next...) ;  
     * }
     */
    inline constexpr auto
    fix = 
    [] (auto&& __func)
    {
        return
        [__func] (auto&&... __args)
        -> decltype(auto)
        {
            return 
            __func(
                fix(__func), 
                static_cast<decltype(__args)&&>(__args)...);
        } ;
    } ;
}

#endif