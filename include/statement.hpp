#ifndef __THODD_FUNCTIONAL_STATEMENT_HPP__
#  define  __THODD_FUNCTIONAL_STATEMENT_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <type_traits>

namespace
thodd
{
    template<
        typename builder_t>
    struct statement
    {
         builder_t builder;

        constexpr auto
        operator[] (
            auto&& __statements) const
        {
            return 
              builder(
                static_cast<decltype(__statements)&&>(__statements));
        }
    };

      
    constexpr auto
    as_statement(
        auto&& __builder)
    {
        return statement<std::decay_t<decltype(__builder)>>{__builder}; 
    }
}

#endif