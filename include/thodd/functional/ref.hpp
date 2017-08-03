#ifndef __THODD_FUNCTIONAL_REF_HPP__
#  define  __THODD_FUNCTIONAL_REF_HPP__ 

#  include <thodd/functional/functor.hpp>

namespace
thodd
{    
    /**
     * Ref lambda returns a functor that returns the __ref 
     * captured by reference whatever the passed arguments. 
     * For example:
     * int a = 5; 
     * auto __ref = ref(a);
     * __ref(12, 5, 6, 7, 9) == 5 
     * ++a;
     * __ref(12, 5, 6, 7, 9) == 6 // Captured by reference, so value is reported 
     * __ref(12, 5, 6, 7, 9)++ ; // Update the reference
     * __ref(12, 5, 6, 7, 9) == 7
     */
    extern constexpr auto
    ref = 
        [] (auto& __ref)
        {
            return 
            as_functor(
                [&__ref] (...)
                -> decltype(auto)
                {
                    return 
                    (__ref) ;
                });
        };
}

#endif