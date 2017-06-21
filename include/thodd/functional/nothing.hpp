#ifndef __THODD_FUNCTIONAL_NOTHING_HPP__
#  define  __THODD_FUNCTIONAL_NOTHING_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto 
    nothing = as_functor([](auto&&... __args) {}) ;
}

#endif