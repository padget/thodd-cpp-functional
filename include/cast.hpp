#ifndef __THODD_FUNCTIONAL_CAST_HPP__
#  define  __THODD_FUNCTIONAL_CAST_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        typename type_t>
    extern constexpr auto 
    cast_ = as_functor(
        [](auto&& __arg)
        -> decltype(auto)
        {
            return 
            (type_t) (
                static_cast<decltype(__arg)&&>(__arg)) ;
        }) ; 

    template<
        typename type_t>
    extern constexpr auto 
    static_cast_ = as_functor(
        [](auto&& __arg)
        -> decltype(auto)
        {
            return 
            static_cast<type_t>(
                static_cast<decltype(__arg)&&>(__arg)) ;
        }) ;  

    template<
        typename type_t>
    extern constexpr auto 
    dynamic_cast_ = as_functor(
        [](auto&& __arg)
        -> decltype(auto)
        {
            return 
            dynamic_cast<type_t>(
                static_cast<decltype(__arg)&&>(__arg)) ;
        }) ; 

    template<
        typename type_t>
    extern constexpr auto 
    const_cast_ = as_functor(
        [](auto&& __arg)
        -> decltype(auto)
        {
            return 
            const_cast<type_t>(
                static_cast<decltype(__arg)&&>(__arg)) ;
        }) ;

    template<
        typename type_t>
    extern constexpr auto 
    reinterpret_cast_ = as_functor(
        [](auto&& __arg)
        -> decltype(auto)
        {
            return 
            reinterpret_cast<type_t>(
                static_cast<decltype(__arg)&&>(__arg)) ;
        }) ;
}

#endif