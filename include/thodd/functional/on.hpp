#ifndef __THODD_FUNCTIONAL_ON_HPP__
#define  __THODD_FUNCTIONAL_ON_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /**
     * On lambda returns a functor that applies __applied to each own passed arguments.
     * For example :
     * on(f, a, args...) <=> f(a(args)...)
     */
    extern constexpr auto 
    on = [] (auto&& __func, 
             auto&& __applied)
        {
            return 
            as_functor(
                [__func, __applied] (auto&&... __args)
                -> decltype(auto)
                {
                    return 
                    __func(
                        __applied(
                            static_cast<decltype(__args)&&>(__args))...) ;
                }) ;
        } ;
}

#endif