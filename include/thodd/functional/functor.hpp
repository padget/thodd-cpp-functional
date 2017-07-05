#ifndef __THODD_FUNCTIONAL_FUNCTOR_HPP__
#  define __THODD_FUNCTIONAL_FUNCTOR_HPP__

#  include <type_traits>

namespace 
thodd
{
    template<
        typename base_t>
    struct functor ;


    constexpr auto
    as_functor(
        auto&& __base)
    {
        return 
        functor<std::decay_t<decltype(__base)>>
        { static_cast<decltype(__base)&&>(__base) } ;
    }


    template<
        typename base_t>
    struct functor
    {
        std::decay_t<base_t> base ;

        constexpr auto
        operator () (
            auto&&... __args) const
        -> decltype(auto)
        {
            return 
            base(
                static_cast<decltype(__args)&&>(__args)...) ;
        }


        template<
            typename obase_t>
        struct assignement
        {
            functor<base_t> this_;
            functor<obase_t> other;

            constexpr auto
            operator () (
                auto&&... __args) const
            -> decltype(auto)
            {
                return 
                this_(static_cast<decltype(__args)&&>(__args)...) = 
                    other(static_cast<decltype(__args)&&>(__args)...) ;
            }
        } ;


        template<
            typename obase_t>
        constexpr auto
        operator = (
            functor<obase_t> const& __other) const
        {
            return 
            as_functor(
                assignement<obase_t>{*this, __other}) ;
        }

        template<
            typename obase_t>
        constexpr auto
        operator = (
            functor<obase_t> && __other) const
        {
            return 
            as_functor(
                assignement<obase_t>{*this, __other}) ;
        }
    };
}


#endif