#ifndef __THODD_FUNCTIONAL_OPERATORS_HPP__
#define  __THODD_FUNCTIONAL_OPERATORS_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    template<
        typename operator_t,
        typename left_t,
        typename right_t>
    struct boperator_params
    {
        operator_t m_operation;
        left_t m_left;
        right_t m_right;

        template<
            typename ... args_t>
        constexpr decltype(auto)
        operator ()(
            args_t&&... _args) const
        {
            return m_operation(
                    m_left(static_cast<args_t&&>(_args)...),
                    m_right(static_cast<args_t&&>(_args)...));
        }
    };


    template<
        typename operator_t,
        typename right_t>
    struct uoperator_param
    {

        operator_t m_operation;
        right_t m_right;

        template<
            typename ... args_t>
        constexpr decltype(auto)
        operator ()(
            args_t&&... _args) const
        {
            return m_operation(m_right(static_cast<args_t&&>(_args)...));
        }
    };
}







#  define THODD_BINARY_OP_CONSTEXPR(name, symbol)        \
struct name                                              \
{                                                        \
    template<                                            \
        typename left_t,                                 \
        typename right_t>                                \
    constexpr decltype(auto)                             \
    operator()(                                          \
        left_t&& _left,                                  \
        right_t&& _right) const                          \
    {                                                    \
        return static_cast<left_t&&>(_left)              \
        symbol static_cast<right_t&&>(_right);           \
    }                                                    \
};                                                       \
                                                         \
                                                         \
template<                                                \
    typename base_t,                                     \
    typename base2_t>                                    \
constexpr decltype(auto)                                 \
operator symbol(                                         \
    functor<base_t> const& _functor,                     \
    functor<base2_t> const& _functor2)                   \
{                                                        \
    return as_functor(                                   \
            boperator_params<                            \
                name,                                    \
                functor<base_t>,                         \
                functor<base2_t>>{name{},                \
                                  _functor, _functor2}); \
}                                                        \
                                                         \
template<                                                \
    typename base_t,                                     \
    typename base2_t>                                    \
constexpr decltype(auto)                                 \
operator symbol(                                         \
    functor<base_t>&& _functor,                          \
    functor<base2_t>&& _functor2)                        \
{                                                        \
    return as_functor(                                   \
            boperator_params<                            \
                name,                                    \
                functor<base_t>,                         \
                functor<base2_t>>{name{},                \
                                  _functor, _functor2}); \
}                                                        \
                                                         \
template<                                                \
    typename base_t,                                     \
    typename base2_t>                                    \
constexpr decltype(auto)                                 \
operator symbol(                                         \
    functor<base_t> && _functor,                         \
    functor<base2_t> const& _functor2)                   \
{                                                        \
    return as_functor(                                   \
            boperator_params<                            \
                name,                                    \
                functor<base_t>,                         \
                functor<base2_t>>{name{},                \
                                  _functor, _functor2}); \
}                                                        \
                                                         \
template<                                                \
    typename base_t,                                     \
    typename base2_t>                                    \
constexpr decltype(auto)                                 \
operator symbol(                                         \
    functor<base_t> const& _functor,                     \
    functor<base2_t> && _functor2)                       \
{                                                        \
    return as_functor(                                   \
            boperator_params<                            \
                name,                                    \
                functor<base_t>,                         \
                functor<base2_t>>{name{},                \
                                  _functor, _functor2}); \
}                                                        \






#  define THODD_UNARY_OP_CONSTEXPR(name, symbol)     \
struct name                                          \
{                                                    \
    template<                                        \
        typename right_t>                            \
    constexpr decltype(auto)                         \
    operator()(right_t&& _right) const               \
    {                                                \
        return symbol static_cast<right_t&&>(_right);\
    }                                                \
};                                                   \
                                                     \
template<                                            \
    typename base_t>                                 \
constexpr decltype(auto)                             \
operator symbol(                                     \
    functor<base_t> const& _functor)                 \
{                                                    \
    return as_functor(                               \
            uoperator_param<                         \
                name,                                \
                functor<base_t>>{name{},             \
                         _functor});                 \
}                                                    \
                                                     \
template<                                            \
    typename base_t>                                 \
constexpr decltype(auto)                             \
operator symbol(                                     \
    functor<base_t> && _functor)                     \
{                                                    \
    return as_functor(                               \
            uoperator_param<                         \
                name,                                \
                functor<base_t>>{name{},             \
                         _functor});                 \
}                                                    \


namespace thodd
{
    /// Arithmetics
    THODD_UNARY_OP_CONSTEXPR(inc, ++)
    THODD_UNARY_OP_CONSTEXPR(dec, --)
    THODD_UNARY_OP_CONSTEXPR(negate, -)
    THODD_UNARY_OP_CONSTEXPR(positive, +)

    THODD_BINARY_OP_CONSTEXPR(plus, +)
    THODD_BINARY_OP_CONSTEXPR(minus, -)
    THODD_BINARY_OP_CONSTEXPR(multiplies, *)
    THODD_BINARY_OP_CONSTEXPR(divides, /)
    THODD_BINARY_OP_CONSTEXPR(modulo, %)

    /// Logics
    THODD_BINARY_OP_CONSTEXPR(equal, ==)
    THODD_BINARY_OP_CONSTEXPR(not_equal, !=)
    THODD_BINARY_OP_CONSTEXPR(greater, >)
    THODD_BINARY_OP_CONSTEXPR(less, <)
    THODD_BINARY_OP_CONSTEXPR(greater_equal, >=)
    THODD_BINARY_OP_CONSTEXPR(less_equal, <=)
    THODD_BINARY_OP_CONSTEXPR(bit_and, &)
    THODD_BINARY_OP_CONSTEXPR(bit_or, |)
    THODD_BINARY_OP_CONSTEXPR(bit_xor, ^)
    THODD_BINARY_OP_CONSTEXPR(and_, &&)
    THODD_BINARY_OP_CONSTEXPR(or_, ||)

    THODD_UNARY_OP_CONSTEXPR(not_, !)
    THODD_UNARY_OP_CONSTEXPR(bit_not, ~)

    /// Affectations
    THODD_BINARY_OP_CONSTEXPR(plus_affect, +=)
    THODD_BINARY_OP_CONSTEXPR(minus_affect, -=)
    THODD_BINARY_OP_CONSTEXPR(multiplies_affect, *=)
    THODD_BINARY_OP_CONSTEXPR(divides_affect, /=)
    THODD_BINARY_OP_CONSTEXPR(modulo_affect, %=)
    THODD_BINARY_OP_CONSTEXPR(lshift_affect, <<=)
    THODD_BINARY_OP_CONSTEXPR(rshift_affect, >>=)

    /// Flux
    THODD_BINARY_OP_CONSTEXPR(lshift, <<)
    THODD_BINARY_OP_CONSTEXPR(rshift, >>)

    /// Access
    THODD_UNARY_OP_CONSTEXPR(addressof, &)
    THODD_UNARY_OP_CONSTEXPR(valueof, *)


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

#  define ARGON_COMPLEX_STREAMFLAG(name)                                                           \
    extern constexpr auto name##_  = cref(std::name<detail::cout_char, detail::cout_traits>);      \
    extern constexpr auto w##name##_ = cref(std::name<detail::wcout_char, detail::wcout_traits>);  \


    ARGON_COMPLEX_STREAMFLAG(endl)
    ARGON_COMPLEX_STREAMFLAG(flush)
    ARGON_COMPLEX_STREAMFLAG(ends)


#  define ARGON_SIMPLE_STREAMFLAG(name)                  \
	extern constexpr auto name##_ = cref(std::name);     \


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