#ifndef __THODD_FUNCTIONAL_WHILE_HPP__
#  define  __THODD_FUNCTIONAL_WHILE_HPP__ 

#  include <utility>

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/statement.hpp>

namespace
thodd
{
    inline constexpr auto
    while_ = 
    [] (auto const & __cond)
    {
        return 
        as_statement (
        [__cond] (auto const & __statements)
        {
            return
            [__cond, __statements] (auto && ... __args)
            {
                while (__cond (std::forward<decltype(__args)>(__args)...))
                    __statements (std::forward<decltype(__args)>(__args)...) ;
            } ;
        }) ;
    } ;
}

#endif