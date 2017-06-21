#ifndef __THODD_FUNCTIONAL_WHILE_HPP__
#define  __THODD_FUNCTIONAL_WHILE_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/statement.hpp>

namespace
thodd
{
    extern constexpr auto
    while_ = 
        [](auto&& __cond)
        {
            return 
            as_statement(
            [&__cond] (auto&& __statements)
            {
                return as_functor(
                [__cond, __statements](auto&&... __args)
                {
                    while(__cond(static_cast<decltype(__args)&&>(__args)...))
                        __statements(static_cast<decltype(__args)&&>(__args)...);
                });
            });
        };
}

#endif