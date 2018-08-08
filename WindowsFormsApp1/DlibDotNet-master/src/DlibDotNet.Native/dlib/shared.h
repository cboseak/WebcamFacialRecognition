enum struct array2d_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    RgbPixel,
    RgbAlphaPixel,
    HsiPixel,
    Matrix,
};

enum struct matrix_element_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    RgbPixel,
    RgbAlphaPixel,
    HsiPixel
};

enum struct vector_element_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

enum element_type : int
{

    OpHeatmap = 0,

    OpJet,

    OpArray2dToMat,
    
    OpTrans,
    
    OpStdVectToMat,
    
    OpJoinRows

};

enum struct interpolation_type : int
{

    NearestNeighbor = 0,

    Bilinear,

    Quadratic

};

enum struct point_mapping_type : int
{

    Rotator = 0,

    Transform,
    
    TransformAffine,
        
    TransformProjective

};

enum struct mlp_kernel_type : int
{

    Kernel1 = 0 // mlp_kernel_1

};

enum struct running_stats_type : int
{

    Float = 0,

    Double

};

enum struct pyramid_type : int
{

    Down = 0

};

enum struct fhog_feature_extractor_type : int
{

    Default = 0

};

typedef struct
{
    // uint8_t
    uint8_t uint8_t_start;
    uint8_t uint8_t_inc;
    uint8_t uint8_t_end;
    bool use_uint8_t_inc;

    // uint16_t
    uint16_t uint16_t_start;
    uint16_t uint16_t_inc;
    uint16_t uint16_t_end;
    bool use_uint16_t_inc;

    // int8_t
    int8_t int8_t_start;
    int8_t int8_t_inc;
    int8_t int8_t_end;
    bool use_int8_t_inc;

    // int16_t
    int16_t int16_t_start;
    int16_t int16_t_inc;
    int16_t int16_t_end;
    bool use_int16_t_inc;

    // int32_t
    int32_t int32_t_start;
    int32_t int32_t_inc;
    int32_t int32_t_end;
    bool use_int32_t_inc;

    // float
    float float_start;
    float float_inc;
    float float_end;
    bool use_float_inc;

    // double
    double double_start;
    double double_inc;
    double double_end;
    bool use_double_inc;

    bool use_num;
    int num;
} matrix_range_exp_create_param;

#define ERR_OK                                 0
#define ERR_ARRAY_TYPE_NOT_SUPPORT            -1
#define ERR_INPUT_ARRAY_TYPE_NOT_SUPPORT      -2
#define ERR_OUTPUT_ARRAY_TYPE_NOT_SUPPORT     -3
#define ERR_ELEMENT_TYPE_NOT_SUPPORT          -4
#define ERR_INPUT_ELEMENT_TYPE_NOT_SUPPORT    -5
#define ERR_OUTPUT_ELEMENT_TYPE_NOT_SUPPORT   -6
#define ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT   -7
// #define ERR_INPUT_OUTPUT_ARRAY_NOT_SAME_SIZE  -8
// #define ERR_INPUT_OUTPUT_MATRIX_NOT_SAME_SIZE -9
#define ERR_MLP_KERNEL_NOT_SUPPORT            -8

// statistics/statistics.h
#define ERR_RUNNING_STATS_TYPE_NOT_SUPPORT    -9
#define ERR_VECTOR_TYPE_NOT_SUPPORT          -10

// fhog
#define ERR_FHOG_ERROR                                       0x7D000000
#define ERR_FHOG_NOT_SUPPORT_EXTRACTOR      ERR_FHOG_ERROR | 0x00000001

// pyramid
#define ERR_PYRAMID_ERROR                                    0x7E000000
#define ERR_PYRAMID_NOT_SUPPORT_RATE     ERR_PYRAMID_ERROR | 0x00000001
#define ERR_PYRAMID_NOT_SUPPORT_TYPE     ERR_PYRAMID_ERROR | 0x00000002

// Dnn
#define ERR_DNN_ERROR                                        0x7F000000
#define ERR_DNN_NOT_SUPPORT_NETWORKTYPE      ERR_DNN_ERROR | 0x00000001