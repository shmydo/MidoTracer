#ifndef _TEST_TUPLE_H
#define _TEST_TUPLE_H
#include <cmath>
#include <cassert>
#include "tuple.h"

namespace Mido{

    void test_tuple(){
        Tuple _test = Tuple(4.3, -4.2, 3.1, 1.0);

        assert(equal(_test.x,  4.3) && "(Tuple::test_tuple): "
                                       "Tuple.x is not equal to 4.3");
        assert(equal(_test.y, -4.2) && "(Tuple::test_tuple): "
                                       "Tuple.y is not equal to -4.2");
        assert(equal(_test.z,  3.1) && "(Tuple::test_tuple): "
                                       "Tuple.z is not equal to 3.1");
        assert(equal(_test.w,  1.0) && "(Tuple::test_tuple): "
                                       "Tuple.w is not equal to 1.0");
    }
    void test_create_point(){
        Tuple _test = createPoint(4.3, -4.2, 3.1);
        
        assert(equal(_test.x,  4.3) && "(Tuple::test_create_point): "
                                       "Tuple.x is not equal to 4.3");
        assert(equal(_test.y, -4.2) && "(Tuple::test_create_point): "
                                       "Tuple.y is not equal to -4.2");
        assert(equal(_test.z,  3.1) && "(Tuple::test_create_point): "
                                       "Tuple.z is not equal to 3.1");
        assert(equal(_test.w,  1.0) && "(Tuple::test_create_point): "
                                       "Tuple.w is not equal to 1.0");
    }

    void test_create_vector(){
        Tuple _test = createVector(4.3, -4.2, 3.1);

        assert(equal(_test.x,  4.3) && "(Tuple::test_create_vector): "
                                       "Tuple.x is not equal to 4.3");
        assert(equal(_test.y, -4.2) && "(Tuple::test_create_vector): "
                                       "Tuple.y is not equal to -4.2");                             
        assert(equal(_test.z,  3.1) && "(Tuple::test_create_vector): "
                                       "Tuple.z is not equal to 3.1");                              
        assert(equal(_test.w,  0.0) && "(Tuple::test_create_vector): "
                                       "Tuple.w is not equal to 0.0");                              

    }

    void test_tuple_equal_operator(){
        Tuple lhs =   Tuple(1.0, 2.0, 3.0, 1.0);
        Tuple rhs_1 = Tuple(1.0, 2.0, 3.0, 1.0);
        Tuple rhs_2 = Tuple(2.0, 1.0, 4.0, 0.0);

        assert(lhs == rhs_1 && "(Tuple::test_tuple_equal_operator):"
                               "lhs and rhs_1 are not equal");

        assert(!(lhs == rhs_2) && "(Tuple::test_tuple_equal_operator):"
                                  "lhs and rhs_2 are equal");                               
    }
    
    void test_tuple_add_operator(){
        Tuple point  = Tuple(3.0, -2.0, 5.0, 1.0);
        Tuple vector = Tuple(-2.0, 3.0, 1.0, 0.0);
        Tuple result = Tuple(1.0, 1.0, 6.0, 1.0);

        assert(point + vector == result
           && "(Tuple::test_tuple_add_operator): lhs + rhs != result");
    }

    void test_tuple_sub_operator(){
        // first test
        Tuple tup_one  = createPoint(3, 2, 1);
        Tuple tup_two  = createPoint(5, 6, 7);
        Tuple result   = createVector(-2, -4, -6);
        
        assert(tup_one - tup_two == result 
            && "(Tuple::test_tuple_sub_operator): First test failed");
        // second test
        tup_one = createPoint(3, 2, 1);
        tup_two = createVector(5, 6, 7);
        result  = createPoint(-2, -4, -6);

        assert(tup_one - tup_two == result 
            && "(Tuple::test_tuple_sub_operator): Second test failed");

        // third test
        tup_one = createVector(3, 2, 1);
        tup_two = createVector(5, 6, 7);
        result  = createVector(-2 , -4, -6);

        assert(tup_one - tup_two == result 
            && "(Tuple::test_tuple_sub_operator): Third test failed");
    }

    void test_tuple_negate(){
        Tuple tup    = createVector(1, -2, 3);
        Tuple result = createVector(-1, 2, -3);

        assert(-tup == result
            && "(Tuple::test_tuple_negate): Negation is not correct");
    }
    
    void test_tuple_multiply(){
        Tuple tup = Tuple(1, -2, 3, -4);
        
        Tuple result_one = Tuple(3.5, -7, 10.5, -14);
        Tuple result_two = Tuple(0.5, -1, 1.5, -2);

        double scalar = 3.5;
        double fract  = 0.5;

        assert((tup * scalar == result_one)
            && "(Tuple::test_tuple_multiply): tup * scalar != result_one");
        assert((scalar * tup == result_one)
            && "(Tuple::test_tuple_multiply): tup * scalar != result_one");

        assert((fract * tup == result_two)
            && "(Tuple::test_tuple_multiply): tup * fract != result_two");
        
        assert((tup * fract == result_two)
            && "(Tuple::test_tuple_multiply): tup * fract != result_two");        
    }

    void test_tuple_divide(){
        Tuple tup = Tuple(1, -2, 3, -4);
        Tuple result = Tuple(0.5, -1, 1.5, -2);

        double scalar = 2.0;

        assert(tup / scalar == result 
            && "(Tuple::test_tuple_divide): tup / sclar != result");        
    }

    void test_tuple_magnitude(){
        Tuple tup = createVector(1, 0, 0);

        assert(equal(magnitude(tup), 1.0)
            && "(Tuple::test_tuple_magnitude): Incorrect magnitude (Test 1)");
        
        tup = createVector(0, 1, 0);
        assert(equal(magnitude(tup), 1.0)
            && "(Tuple::test_tuple_magnitude): Incorrect magnitude (Test 2)");

        tup = createVector(0, 0, 1);
        assert(equal(magnitude(tup), 1.0)
            && "(Tuple::test_tuple_magnitude): Incorrect magnitude (Test 3)");

        tup = createVector(1, 2, 3);    
        assert(equal(magnitude(tup), std::sqrt(14))
            && "(Tuple::test_tuple_magnitude): Incorrect magnitude (Test 4)");

        tup = createVector(-1, -2, -3);    
        assert(equal(magnitude(tup), std::sqrt(14))
            && "(Tuple::test_tuple_magnitude): Incorrect magnitude (Test 5)");

    }

    void test_tuple_normalize(){
        Tuple tup = createVector(4, 0, 0);
        Tuple unit_tup = createVector(1, 0, 0);

        assert(normalize(tup) == unit_tup
            && "(Tuple::test_tuple_normalize): tup not normalized (Test 1)");
        
        tup = createVector(1, 2, 3);
        unit_tup = createVector(0.26726, 0.53452, 0.80178);
        assert(normalize(tup) == unit_tup
            && "(Tuple::test_tuple_normalize): tup not normalized (Test 2)");
        assert(equal(magnitude(normalize(tup)), 1.0) 
            && "(Tuple::test_tuple_normalize): mag of norm vec != to 1.0");
    }

    void test_tuple_dot(){
        Tuple tup_one = createVector(1, 2, 3);
        Tuple tup_two = createVector(2, 3, 4);
        double result = 20.0;

        assert(equal(dot(tup_one, tup_two), result) 
            && "(Tuple::test_tuple_dot): dot(tup_one, tup_two) != result");
    }

    void test_tuple_cross(){
        Tuple tup_one = createVector(1, 2, 3);
        Tuple tup_two = createVector(2, 3, 4);
        Tuple result = createVector(-1, 2, -1);

        assert(cross(tup_one, tup_two) == result
            && "(Tuple::test_tuple_cross): cross(tup_one,tup_two) != result");

        result = -result;
        assert(cross(tup_two, tup_one) == result
            && "(Tuple::test_tuple_cross): cross(tup_two, tup_one) != result");
            
    }
    void test_tuple_all(){
        test_tuple();
        test_create_point();
        test_create_vector();
        test_tuple_equal_operator();
        test_tuple_add_operator();
        test_tuple_sub_operator();
        test_tuple_negate();
        test_tuple_multiply();
        test_tuple_divide();
        test_tuple_magnitude();
        test_tuple_normalize();
        test_tuple_dot();
        test_tuple_cross();
    }
}
#endif 