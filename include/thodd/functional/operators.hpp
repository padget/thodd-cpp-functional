#ifndef __THODD_FUNCTIONAL_OPERATORS_HPP__
#  define  __THODD_FUNCTIONAL_OPERATORS_HPP__ 

#  include <thodd/functional/functor.hpp>
#  include <thodd/functional/ref.hpp>
#  include <thodd/functional/cref.hpp>
#  include <iostream>

#  define THODD_BINARY_OP_CONSTEXPR(symbol, name)               \
inline constexpr auto                                           \
name =                                                          \
[] (auto && left, auto && ... right)                            \
{                                                               \
    return                                                      \
    [left, right...] (auto && ... args)                         \
    {                                                           \
        return                                                  \
        left (std::forward<decltype(args)>(args)...)            \
        symbol (                                                \
            right (std::forward<decltype(args)>(args)...)       \
            symbol ... ) ;                                      \
    } ;                                                         \
} ;                                                             \



#  define THODD_UNARY_OP_CONSTEXPR(symbol, name)                \
inline constexpr auto                                           \
name =                                                          \
[] (auto && left)                            \
{                                                               \
    return                                                      \
    [left] (auto && ... args)                         \
    {                                                           \
        return                                                  \
        symbol left (std::forward<decltype(args)>(args)...) ;            \
    } ;                                                         \
} ;                                                             \



namespace thodd
{
    /// Arithmetics
    THODD_UNARY_OP_CONSTEXPR(++, inc)
    THODD_UNARY_OP_CONSTEXPR(--, dec)
    THODD_UNARY_OP_CONSTEXPR(-, neg)
    THODD_UNARY_OP_CONSTEXPR(+, pos)

    THODD_BINARY_OP_CONSTEXPR(+, sum)
    THODD_BINARY_OP_CONSTEXPR(-, sub)
    THODD_BINARY_OP_CONSTEXPR(*, mult)
    THODD_BINARY_OP_CONSTEXPR(/, div)
    THODD_BINARY_OP_CONSTEXPR(%, mod)

    /// Logics
    THODD_BINARY_OP_CONSTEXPR(==, equal)
    THODD_BINARY_OP_CONSTEXPR(!=, not_equal)
    THODD_BINARY_OP_CONSTEXPR(>, greater)
    THODD_BINARY_OP_CONSTEXPR(<, lower)
    THODD_BINARY_OP_CONSTEXPR(>=, greater_equal)
    THODD_BINARY_OP_CONSTEXPR(<=, lower_equal)
    THODD_BINARY_OP_CONSTEXPR(&, bit_and)
    THODD_BINARY_OP_CONSTEXPR(|, bit_or)
    THODD_BINARY_OP_CONSTEXPR(^, bit_xor)
    THODD_BINARY_OP_CONSTEXPR(&&, and_)
    THODD_BINARY_OP_CONSTEXPR(||, or_)

    THODD_UNARY_OP_CONSTEXPR(!, not_)
    THODD_UNARY_OP_CONSTEXPR(~, compl_)

    /// Affectations
    THODD_BINARY_OP_CONSTEXPR(+=, sum_ass)
    THODD_BINARY_OP_CONSTEXPR(-=, sub_ass)
    THODD_BINARY_OP_CONSTEXPR(*=, mult_ass)
    THODD_BINARY_OP_CONSTEXPR(/=, div_ass)
    THODD_BINARY_OP_CONSTEXPR(%=, mod_ass)
    THODD_BINARY_OP_CONSTEXPR(<<=, lshift_ass)
    THODD_BINARY_OP_CONSTEXPR(>>=, rshift_ass)

    /// Flux
    THODD_BINARY_OP_CONSTEXPR(<<, lshift)
    THODD_BINARY_OP_CONSTEXPR(>>, rshift)

    /// Access
    THODD_UNARY_OP_CONSTEXPR(&, addr)
    THODD_UNARY_OP_CONSTEXPR(*, indir)


    inline constexpr auto cout_  = ref(std::cout);
    inline constexpr auto wcout_ = ref(std::wcout);

    inline constexpr auto cin_   = ref(std::cin);
    inline constexpr auto wcin_  = ref(std::wcin);

	inline constexpr auto cerr_  = ref(std::cerr);
    inline constexpr auto wcerr_ = ref(std::wcerr);

    namespace detail
    {
        using cout_char = typename decltype(std::cout)::char_type;
        using cout_traits = typename decltype(std::cout)::traits_type;

        using wcout_char = typename decltype(std::wcout)::char_type;
        using wcout_traits = typename decltype(std::wcout)::traits_type;
    }
}

#  define ARGON_COMPLEX_STREAMFLAG(name)                                                           \
    inline constexpr auto name##_  = cref(std::name<detail::cout_char, detail::cout_traits>);      \
    inline constexpr auto w##name##_ = cref(std::name<detail::wcout_char, detail::wcout_traits>);  \

namespace
thodd 
{
    ARGON_COMPLEX_STREAMFLAG(endl)
    ARGON_COMPLEX_STREAMFLAG(flush)
    ARGON_COMPLEX_STREAMFLAG(ends)
}


#  define ARGON_SIMPLE_STREAMFLAG(name)                  \
	inline constexpr auto name##_ = cref(std::name);     \


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