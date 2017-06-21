#ifndef __THODD_FUNCTIONAL_IF_HPP__
#  define  __THODD_FUNCTIONAL_IF_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/statement.hpp>

namespace
thodd
{
    extern constexpr auto
    if_ = 
        [](auto&& __cond)
        {
            return 
            as_statement(
            [&__cond] (auto&& __statements)
            {
                return as_functor(
                [__cond, __statements](auto&&... __args)
                {
                    if(__cond(static_cast<decltype(__args)&&>(__args)...))
                        __statements(static_cast<decltype(__args)&&>(__args)...);
                });
            });
        };
}

#endif