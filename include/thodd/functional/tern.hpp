#ifndef __THODD_FUNCTIONAL_TERN_HPP__
#  define  __THODD_FUNCTIONAL_TERN_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/statement.hpp>

namespace
thodd
{
    inline constexpr auto
    tern = 
        [](auto&& __cond)
        {
            return 
            as_statement (
            [__cond] (auto && __statements)
            {
                return 
                as_statement (
                [__cond, __statements] (auto && __else_statements)
                {
                    return
                    [__cond, __statements, __else_statements](auto && ... __args)
                    -> decltype(auto)
                    {
                        return 
                        __cond (static_cast<decltype(__args)&&>(__args)...) ?
                            __statements (static_cast<decltype(__args)&&>(__args)...) :
                            __else_statements (static_cast<decltype(__args)&&>(__args)...) ;
                    } ;
                }) ;
            }) ;
        } ;
}

#endif