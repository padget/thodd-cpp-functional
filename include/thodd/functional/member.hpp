#ifndef __THODD__fUNCTIONAL_MEMBER_HPP__
#  define  __THODD__fUNCTIONAL_MEMBER_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    /** 
     * Member lambda returns a functor that bind an instance and a method from the same class and some binder expression.
     * For example :
     * std::string str ;
     * auto f = member(&std::string::operator+=, str, $0) ;
     * f(std::string("hello")) <=> str.*operator += (std::string("hello"))   
     */
    extern constexpr auto
	member = 
        [](auto&& __func, auto&& __instance, auto&&... _prebinded)
        {
            return as_functor(
            [=](auto&&... _args) 
            -> decltype(auto)
            {
                using func_t = decltype(__func) ;
                using instance_t = decltype(__instance) ;

                return 
                (static_cast<instance_t&&>(__instance).*static_cast<func_t&&>(__func))
                (_prebinded(static_cast<decltype(_args)&&>(_args)...)...) ;
            }) ;
        } ;
}

#endif