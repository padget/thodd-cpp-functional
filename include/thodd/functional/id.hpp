#ifndef __THODD_FUNCTIONAL_ID_HPP__
#  define __THODD_FUNCTIONAL_ID_HPP__

namespace 
thodd
{
    struct id
    {
        constexpr auto 
        operator()( 
            auto&&... __args) const
        -> decltype(auto) 
        {
            auto&& __first = $0(static_cast<decltype(__args)&&>(__args)...);
            return __first;
        }

        constexpr auto
        operator() () const {}
    };
}

#endif