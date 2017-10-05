#ifndef __THODD_FUNCTIONAL_NEW_HPP__
#define  __THODD_FUNCTIONAL_NEW_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        typename type_t>
    inline constexpr auto
    new_ =
        as_functor (
            [] (auto&&... __args)
            {
                return 
                new type_t (
                    static_cast<decltype(__args)&&>(__args)...);
            });
}

#endif