#ifndef _CPP_MATRIX_UTILITIES_H_
#define _CPP_MATRIX_UTILITIES_H_

#include "../export.h"
#include <dlib/matrix.h>
#include <dlib/matrix/matrix_utilities.h>
#include <dlib/geometry/rectangle.h>
#include <dlib/geometry/vector.h>
#include "../shared.h"

using namespace dlib;
using namespace std;

#define OP_TYPE type
#define ELEMENT_IN element
#define ELEMENT_OUT element
#undef OP_TYPE
#undef ELEMENT_IN
#undef ELEMENT_OUT

#define matrix_length_template(matrix, templateRows, templateColumns, ret) \
do {\
    if (templateRows == 0 && templateColumns == 0)\
    {\
        dlib::matrix<ELEMENT_IN>& mat = *static_cast<dlib::matrix<ELEMENT_IN>*>(matrix);\
        *ret = dlib::length(mat);\
    }\
    else if (templateRows == 0 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 0, 1>& mat = *static_cast<dlib::matrix<ELEMENT_IN, 0, 1>*>(matrix);\
        *ret = dlib::length(mat);\
    }\
    else if (templateRows == 31 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 31, 1>& mat = *static_cast<dlib::matrix<ELEMENT_IN, 31, 1>*>(matrix);\
        *ret = dlib::length(mat);\
    }\
} while (0)

#define matrix_mean_op_std_vect_to_mat_template(type, matrix, templateRows, templateColumns, ret, err) \
do {\
    if (templateRows == 0 && templateColumns == 0)\
    {\
        switch(type)\
        {\
            case matrix_element_type::UInt8:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint8_t>, allocator<dlib::matrix<uint8_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint8_t>(r);\
                }\
                break;\
            case matrix_element_type::UInt16:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint16_t>, allocator<dlib::matrix<uint16_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint16_t>(r);\
                }\
                break;\
            case matrix_element_type::UInt32:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint32_t>, allocator<dlib::matrix<uint32_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint32_t>(r);\
                }\
                break;\
            case matrix_element_type::Int8:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int8_t>, allocator<dlib::matrix<int8_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int8_t>(r);\
                }\
                break;\
            case matrix_element_type::Int16:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int16_t>, allocator<dlib::matrix<int16_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int16_t>(r);\
                }\
                break;\
            case matrix_element_type::Int32:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int32_t>, allocator<dlib::matrix<int32_t>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int32_t>(r);\
                }\
                break;\
            case matrix_element_type::Float:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<float>, allocator<dlib::matrix<float>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<float>(r);\
                }\
                break;\
            case matrix_element_type::Double:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<double>, allocator<dlib::matrix<double>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<double>(r);\
                }\
                break;\
            case matrix_element_type::RgbPixel:\
            case matrix_element_type::HsiPixel:\
            case matrix_element_type::RgbAlphaPixel:\
            default:\
                err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT;\
                break;\
        }\
    }\
    else if (templateRows == 0 && templateColumns == 1)\
    {\
        switch(type)\
        {\
            case matrix_element_type::UInt8:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint8_t, 0, 1>, allocator<dlib::matrix<uint8_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint8_t>(r);\
                }\
                break;\
            case matrix_element_type::UInt16:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint16_t, 0, 1>, allocator<dlib::matrix<uint16_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint16_t>(r);\
                }\
                break;\
            case matrix_element_type::UInt32:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<uint32_t, 0, 1>, allocator<dlib::matrix<uint32_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<uint32_t>(r);\
                }\
                break;\
            case matrix_element_type::Int8:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int8_t, 0, 1>, allocator<dlib::matrix<int8_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int8_t>(r);\
                }\
                break;\
            case matrix_element_type::Int16:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int16_t, 0, 1>, allocator<dlib::matrix<int16_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int16_t>(r);\
                }\
                break;\
            case matrix_element_type::Int32:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<int32_t, 0, 1>, allocator<dlib::matrix<int32_t, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<int32_t>(r);\
                }\
                break;\
            case matrix_element_type::Float:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<float, 0, 1>, allocator<dlib::matrix<float, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<float>(r);\
                }\
                break;\
            case matrix_element_type::Double:\
                {\
                    typedef dlib::matrix_op<dlib::op_std_vect_to_mat<std::vector<dlib::matrix<double, 0, 1>, allocator<dlib::matrix<double, 0, 1>>>>> op;\
                    op& mat = *static_cast<op*>(matrix);\
                    auto r = dlib::mean(mat);\
                    *ret = new dlib::matrix<double>(r);\
                }\
                break;\
            case matrix_element_type::RgbPixel:\
            case matrix_element_type::HsiPixel:\
            case matrix_element_type::RgbAlphaPixel:\
            default:\
                err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT;\
                break;\
        }\
    }\
} while (0)

#define matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret)\
do {\
    if (templateRows == 0 && templateColumns == 0)\
    {\
        dlib::matrix<ELEMENT_IN>& mat1 = *static_cast<dlib::matrix<ELEMENT_IN>*>(matrix1);\
        dlib::matrix<ELEMENT_IN>& mat2 = *static_cast<dlib::matrix<ELEMENT_IN>*>(matrix2);\
        auto joinedMat = dlib::join_rows(mat1, mat2);\
        *ret = new matrix_op<op_join_rows<matrix<ELEMENT_IN>, matrix<ELEMENT_IN>>>(joinedMat);\
    }\
    else if (templateRows == 0 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 0, 1>& mat1 = *static_cast<dlib::matrix<ELEMENT_IN, 0, 1>*>(matrix1);\
        dlib::matrix<ELEMENT_IN, 0, 1>& mat2 = *static_cast<dlib::matrix<ELEMENT_IN, 0, 1>*>(matrix2);\
        auto joinedMat = dlib::join_rows(mat1, mat2);\
        *ret = new matrix_op<op_join_rows<matrix<ELEMENT_IN, 0, 1>, matrix<ELEMENT_IN, 0, 1>>>(joinedMat);\
    }\
    else if (templateRows == 31 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 31, 1>& mat1 = *static_cast<dlib::matrix<ELEMENT_IN, 31, 1>*>(matrix1);\
        dlib::matrix<ELEMENT_IN, 31, 1>& mat2 = *static_cast<dlib::matrix<ELEMENT_IN, 31, 1>*>(matrix2);\
        auto joinedMat = dlib::join_rows(mat1, mat2);\
        *ret = new matrix_op<op_join_rows<matrix<ELEMENT_IN, 31, 1>, matrix<ELEMENT_IN, 31, 1>>>(joinedMat);\
    }\
} while (0)

#define matrix_trans_template(matrix, templateRows, templateColumns, ret) \
do {\
    if (templateRows == 0 && templateColumns == 0)\
    {\
        dlib::matrix<ELEMENT_IN>& mat = *static_cast<dlib::matrix<ELEMENT_IN>*>(matrix);\
        auto transedMat = dlib::trans(mat);\
        *ret = new matrix_op<op_trans<dlib::matrix<ELEMENT_IN>>>(transedMat);\
    }\
    else if (templateRows == 0 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 0, 1>& mat = *static_cast<dlib::matrix<ELEMENT_IN, 0, 1>*>(matrix);\
        auto transedMat = dlib::trans(mat);\
        *ret = new matrix_op<op_trans<dlib::matrix<ELEMENT_IN, 0, 1>>>(transedMat);\
    }\
    else if (templateRows == 31 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT_IN, 31, 1>& mat = *static_cast<dlib::matrix<ELEMENT_IN, 31, 1>*>(matrix);\
        auto transedMat = dlib::trans(mat);\
        *ret = new matrix_op<op_trans<dlib::matrix<ELEMENT_IN, 31, 1>>>(transedMat);\
    }\
} while (0)

#pragma endregion template

DLLEXPORT void* linspace(double start, double end, int num)
{
    matrix_range_exp<double> ret = dlib::linspace(start, end, num);
    return new matrix_range_exp<double>(ret);
}

DLLEXPORT int matrix_length(matrix_element_type type, void* matrix, int templateRows, int templateColumns, double* ret) 
{ 
    int err = ERR_OK; 
    switch(type) 
    { 
        case matrix_element_type::UInt8:
            #define ELEMENT_IN uint8_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt16:
            #define ELEMENT_IN uint16_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt32:
            #define ELEMENT_IN uint32_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int8:
            #define ELEMENT_IN int8_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int16:
            #define ELEMENT_IN int16_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int32:
            #define ELEMENT_IN int32_t
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Float:
            #define ELEMENT_IN float
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Double:
            #define ELEMENT_IN double
            matrix_length_template(matrix, templateRows, templateColumns, ret);
            break; 
        case matrix_element_type::RgbPixel:
        case matrix_element_type::HsiPixel:
        case matrix_element_type::RgbAlphaPixel:
        default: 
            err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT; 
            break; 
    } 
 
    return err; 
}

DLLEXPORT int matrix_join_rows(matrix_element_type type, void* matrix1, void* matrix2, int templateRows, int templateColumns, void** ret) 
{ 
    int err = ERR_OK; 
    switch(type) 
    { 
        case matrix_element_type::UInt8:
            #define ELEMENT_IN uint8_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt16:
            #define ELEMENT_IN uint16_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt32:
            #define ELEMENT_IN uint32_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int8:
            #define ELEMENT_IN int8_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int16:
            #define ELEMENT_IN int16_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int32:
            #define ELEMENT_IN int32_t
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Float:
            #define ELEMENT_IN float
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Double:
            #define ELEMENT_IN double
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            break; 
        case matrix_element_type::RgbPixel:
            #define ELEMENT_IN rgb_pixel
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            break; 
        case matrix_element_type::HsiPixel:
            #define ELEMENT_IN hsi_pixel
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            break; 
        case matrix_element_type::RgbAlphaPixel:
            #define ELEMENT_IN rgb_alpha_pixel
            matrix_join_rows_template(matrix1, matrix2, templateRows, templateColumns, ret);
            break; 
        default: 
            err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT; 
            break; 
    } 
 
    return err; 
}

DLLEXPORT int matrix_max_point(matrix_element_type type, void* matrix, dlib::point** ret)
{
    int err = ERR_OK;
    switch(type)
    {
        case matrix_element_type::UInt8:
            {
                auto mat_op = static_cast<matrix_op<op_array2d_to_mat<array2d<uint8_t>>>*>(matrix);
                auto p = dlib::max_point(*mat_op);
                *ret = new dlib::point(p);;
            }
            break;
        case matrix_element_type::UInt16:
            {
                auto mat_op = static_cast<matrix_op<op_array2d_to_mat<array2d<uint16_t>>>*>(matrix);
                auto p = dlib::max_point(*mat_op);
                *ret = new dlib::point(p);;
            }
            break;
        case matrix_element_type::Int32:
            {
                auto mat_op = static_cast<matrix_op<op_array2d_to_mat<array2d<int32_t>>>*>(matrix);
                auto p = dlib::max_point(*mat_op);
                *ret = new dlib::point(p);;
            }
            break;
        case matrix_element_type::Float:
            {
                auto mat_op = static_cast<matrix_op<op_array2d_to_mat<array2d<float>>>*>(matrix);
                auto p = dlib::max_point(*mat_op);
                *ret = new dlib::point(p);;
            }
            break;
        case matrix_element_type::Double:
            {
                auto mat_op = static_cast<matrix_op<op_array2d_to_mat<array2d<double>>>*>(matrix);
                auto p = dlib::max_point(*mat_op);
                *ret = new dlib::point(p);;
            }
            break;
        case matrix_element_type::RgbPixel:
        case matrix_element_type::HsiPixel:
        case matrix_element_type::RgbAlphaPixel:
        default:
            err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT;
            break;
    }

    return err;
}

DLLEXPORT int matrix_mean(matrix_element_type type, void* matrix, int templateRows, int templateColumns, element_type opType, void** ret) 
{ 
    int err = ERR_OK; 
    switch(opType) 
    { 
        case element_type::OpStdVectToMat:
            matrix_mean_op_std_vect_to_mat_template(type, matrix, templateRows, templateColumns, ret, err);
            break;
        default:
            err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT;
            break; 
    }
 
    return err; 
}

DLLEXPORT int matrix_trans(matrix_element_type type, void* matrix, int templateRows, int templateColumns, void** ret) 
{ 
    int err = ERR_OK; 
    switch(type) 
    { 
        case matrix_element_type::UInt8:
            #define ELEMENT_IN uint8_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt16:
            #define ELEMENT_IN uint16_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::UInt32:
            #define ELEMENT_IN uint32_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int8:
            #define ELEMENT_IN int8_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int16:
            #define ELEMENT_IN int16_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Int32:
            #define ELEMENT_IN int32_t
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Float:
            #define ELEMENT_IN float
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            #undef ELEMENT_IN
            break; 
        case matrix_element_type::Double:
            #define ELEMENT_IN double
            matrix_trans_template(matrix, templateRows, templateColumns, ret);
            break; 
        case matrix_element_type::RgbPixel:
        case matrix_element_type::HsiPixel:
        case matrix_element_type::RgbAlphaPixel:
        default: 
            err = ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT; 
            break; 
    } 
 
    return err; 
}

#endif