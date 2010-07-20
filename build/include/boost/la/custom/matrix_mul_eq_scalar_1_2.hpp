//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_MUL_EQ_SCALAR_1_2_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_MUL_EQ_SCALAR_1_2_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A>
        BOOST_LA_INLINE_OPERATIONS
        typename enable_if_c<
            matrix_traits<A>::rows==1 && matrix_traits<A>::cols==2,
            A &>::type
        operator*=( A & a, typename matrix_traits<A>::scalar_type b )
            {
            matrix_traits<A>::template w<0,0>(a)*=b;
            matrix_traits<A>::template w<0,1>(a)*=b;
            return a;
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct matrix_mul_eq_scalar_defined;

            template <>
            struct
            matrix_mul_eq_scalar_defined<1,2>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
