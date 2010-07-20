//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_NEQ_MATRIX_2_1_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_NEQ_MATRIX_2_1_HPP_INCLUDED

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
        template <class A,class B>
        BOOST_LA_INLINE_OPERATIONS
        typename enable_if_c<
            matrix_traits<A>::rows==2 && matrix_traits<B>::rows==2 &&
            matrix_traits<A>::cols==1 && matrix_traits<B>::cols==1,
            bool>::type
        operator!=( A const & a, B const & b )
            {
            return
                !(matrix_traits<A>::template r<0,0>(a)==matrix_traits<B>::template r<0,0>(b)) ||
                !(matrix_traits<A>::template r<1,0>(a)==matrix_traits<B>::template r<1,0>(b));
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct matrix_neq_matrix_defined;

            template <>
            struct
            matrix_neq_matrix_defined<2,1>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
