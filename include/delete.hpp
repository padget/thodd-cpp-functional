#ifndef __THODD_FUNCTIONAL_DELETE_HPP__
#  define  __THODD_FUNCTIONAL_DELETE_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{
    extern constexpr auto
    delete_ = 
        as_functor(
            [] (auto* __ptr)
            {
                delete __ptr;
                __ptr = nullptr;
            });
}

#endif