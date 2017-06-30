#ifndef __THODD_FUNCTIONAL_OPERATORS_HPP__
#  define  __THODD_FUNCTIONAL_OPERATORS_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/ref.hpp>
#  include <thodd/functional/cref.hpp>
#  include <iostream>

#  define THODD_BINARY_OP_CONSTEXPR(symbol)                            \
operator symbol (                                                      \
    functor<auto> const & __l,                                         \
    functor<auto> const & __r)                                         \
{                                                                      \
    return                                                             \
    as_functor(                                                        \
        [=] (auto&& ... __args)                                          \
        {                                                              \
            return __l(static_cast<decltype(__args)&&>(__args)...)     \
            symbol __r(static_cast<decltype(__args)&&>(__args)...) ;   \
        }) ;                                                           \
}                                                                      \


#  define THODD_UNARY_OP_CONSTEXPR(symbol)                             \
operator symbol (                                                      \
    functor<auto> const & __r)                                         \
{                                                                      \
    return                                                             \
    as_functor(                                                        \
        [=] (auto&& ... __args)                                          \
        {                                                              \
            return                                                     \
            symbol __r(static_cast<decltype(__args)&&>(__args)...) ;   \
        }) ;                                                           \
}                                                                      \


namespace thodd
{
    /// Arithmetics
    THODD_UNARY_OP_CONSTEXPR(++)
    THODD_UNARY_OP_CONSTEXPR(--)
    THODD_UNARY_OP_CONSTEXPR(-)
    THODD_UNARY_OP_CONSTEXPR(+)

    THODD_BINARY_OP_CONSTEXPR(+)
    THODD_BINARY_OP_CONSTEXPR(-)
    THODD_BINARY_OP_CONSTEXPR(*)
    THODD_BINARY_OP_CONSTEXPR(/)
    THODD_BINARY_OP_CONSTEXPR(%)

    /// Logics
    THODD_BINARY_OP_CONSTEXPR(==)
    THODD_BINARY_OP_CONSTEXPR(!=)
    THODD_BINARY_OP_CONSTEXPR(>)
    THODD_BINARY_OP_CONSTEXPR(<)
    THODD_BINARY_OP_CONSTEXPR(>=)
    THODD_BINARY_OP_CONSTEXPR(<=)
    THODD_BINARY_OP_CONSTEXPR(&)
    THODD_BINARY_OP_CONSTEXPR(|)
    THODD_BINARY_OP_CONSTEXPR(^)
    THODD_BINARY_OP_CONSTEXPR(&&)
    THODD_BINARY_OP_CONSTEXPR(||)

    THODD_UNARY_OP_CONSTEXPR(!)
    THODD_UNARY_OP_CONSTEXPR(~)

    /// Affectations
    THODD_BINARY_OP_CONSTEXPR(+=)
    THODD_BINARY_OP_CONSTEXPR(-=)
    THODD_BINARY_OP_CONSTEXPR(*=)
    THODD_BINARY_OP_CONSTEXPR(/=)
    THODD_BINARY_OP_CONSTEXPR(%=)
    THODD_BINARY_OP_CONSTEXPR(<<=)
    THODD_BINARY_OP_CONSTEXPR(>>=)

    /// Flux
    THODD_BINARY_OP_CONSTEXPR(<<)
    THODD_BINARY_OP_CONSTEXPR(>>)

    /// Access
    THODD_UNARY_OP_CONSTEXPR(&)
    THODD_UNARY_OP_CONSTEXPR(*)


    extern constexpr auto cout_  = ref(std::cout);
    extern constexpr auto wcout_ = ref(std::wcout);

    extern constexpr auto cin_   = ref(std::cin);
    extern constexpr auto wcin_  = ref(std::wcin);

	extern constexpr auto cerr_  = ref(std::cerr);
    extern constexpr auto wcerr_ = ref(std::wcerr);

    namespace detail
    {
        using cout_char = typename decltype(std::cout)::char_type;
        using cout_traits = typename decltype(std::cout)::traits_type;

        using wcout_char = typename decltype(std::wcout)::char_type;
        using wcout_traits = typename decltype(std::wcout)::traits_type;
    }
}

#  define ARGON_COMPLEX_STREAMFLAG(name)                                                           \
    extern constexpr auto name##_  = cref(std::name<detail::cout_char, detail::cout_traits>);      \
    extern constexpr auto w##name##_ = cref(std::name<detail::wcout_char, detail::wcout_traits>);  \

namespace
thodd 
{

    ARGON_COMPLEX_STREAMFLAG(endl)
    ARGON_COMPLEX_STREAMFLAG(flush)
    ARGON_COMPLEX_STREAMFLAG(ends)
}


#  define ARGON_SIMPLE_STREAMFLAG(name)                  \
	extern constexpr auto name##_ = cref(std::name);     \


namespace
thodd
{
    ARGON_SIMPLE_STREAMFLAG(boolalpha)
    ARGON_SIMPLE_STREAMFLAG(showbase)
    ARGON_SIMPLE_STREAMFLAG(noshowbase)
    ARGON_SIMPLE_STREAMFLAG(showpoint)
    ARGON_SIMPLE_STREAMFLAG(noshowpoint)
    ARGON_SIMPLE_STREAMFLAG(showpos)
    ARGON_SIMPLE_STREAMFLAG(skipws)
    ARGON_SIMPLE_STREAMFLAG(noskipws)
    ARGON_SIMPLE_STREAMFLAG(uppercase)
    ARGON_SIMPLE_STREAMFLAG(nouppercase)
    ARGON_SIMPLE_STREAMFLAG(unitbuf)
    ARGON_SIMPLE_STREAMFLAG(nounitbuf)
    ARGON_SIMPLE_STREAMFLAG(left)
    ARGON_SIMPLE_STREAMFLAG(right)
    ARGON_SIMPLE_STREAMFLAG(internal)
    ARGON_SIMPLE_STREAMFLAG(dec)
    ARGON_SIMPLE_STREAMFLAG(hex)
    ARGON_SIMPLE_STREAMFLAG(oct)
    ARGON_SIMPLE_STREAMFLAG(fixed)
    ARGON_SIMPLE_STREAMFLAG(scientific)
    ARGON_SIMPLE_STREAMFLAG(hexfloat)
    ARGON_SIMPLE_STREAMFLAG(defaultfloat)

}

#endif