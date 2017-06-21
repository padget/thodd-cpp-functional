#ifndef __THODD_FUNCTIONAL_MEMBER_HPP__
#  define  __THODD_FUNCTIONAL_MEMBER_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
	member = 
        [](auto&& _func, auto&& _instance, auto&&... _prebinded)
        {
            return as_functor(
            [=](auto&&... _args) 
            -> decltype(auto)
            {
                using func_t = decltype(_func) ;
                using instance_t = decltype(_instance) ;

                return 
                (static_cast<instance_t&&>(_instance).*static_cast<func_t&&>(_func))
                (_prebinded(static_cast<decltype(_args)&&>(_args)...)...) ;
            }) ;
        } ;
}

#endif