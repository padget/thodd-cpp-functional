#ifndef __THODD_FUNCTIONAL_DELETE_HPP__
#  define  __THODD_FUNCTIONAL_DELETE_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    inline constexpr auto
    delete_ = 
    [] (auto* __ptr)
    {
        delete __ptr;
        __ptr = nullptr;
    } ;
}

#endif