#ifndef __THODD_FUNCTIONAL_STATEMENTS_HPP__
#  define __THODD_FUNCTIONAL_STATEMENTS_HPP__

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        typename left_t,
        typename right_t>
    struct statements
    {
        std::decay_t<left_t> left;
        std::decay_t<right_t> right;

        template<
            typename ... args_t>
        constexpr auto
        operator () (
            args_t&&... _args) const
        -> decltype(auto)
        {
            left(static_cast<decltype(_args)&&>(_args)...) ;
            
            return right(static_cast<decltype(_args)&&>(_args)...) ;
        }
    };

    template<
        typename base_t,
        typename base2_t>
    constexpr auto
    operator , (
        functor<base_t> const& _functor,
        functor<base2_t> const& _functor2)
    {
        return 
        as_functor(
            statements<base_t, base2_t>
            { _functor.base, 
              _functor2.base }) ;
    }
}

#endif