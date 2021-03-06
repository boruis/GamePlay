/*
    Copyright 2016 Andrew Karpushin (reven86@gmail.com).

    This source file is a Derivative Work from orignal Gameplay3D source files.
    The Gameplay3D project is distributed under the terms of Apache 2.0 License.
    Original Gameplay3D source files can be found at https://github.com/gameplay3d/GamePlay

    Changes to orginal document were done in lines: 13, 68, 74.
*/

#ifndef MATHUTIL_H_
#define MATHUTIL_H_

namespace gameplay
{
/**
 * Defines a math utility class.
 *
 * This is primarily used for optimized internal math operations.
 */
class MathUtil
{
    friend class Matrix;
    friend class Matrix3;
    friend class Vector3;

public:

    /**
     * Updates the given scalar towards the given target using a smoothing function.
     * The given response time determines the amount of smoothing (lag). A longer
     * response time yields a smoother result and more lag. To force the scalar to
     * follow the target closely, provide a response time that is very small relative
     * to the given elapsed time.
     *
     * @param x the scalar to update.
     * @param target target value.
     * @param elapsedTime elapsed time between calls.
     * @param responseTime response time (in the same units as elapsedTime).
     */
    static void smooth(float* x, float target, float elapsedTime, float responseTime);

    /**
     * Updates the given scalar towards the given target using a smoothing function.
     * The given rise and fall times determine the amount of smoothing (lag). Longer
     * rise and fall times yield a smoother result and more lag. To force the scalar to
     * follow the target closely, provide rise and fall times that are very small relative
     * to the given elapsed time.
     *
     * @param x the scalar to update.
     * @param target target value.
     * @param elapsedTime elapsed time between calls.
     * @param riseTime response time for rising slope (in the same units as elapsedTime).
     * @param fallTime response time for falling slope (in the same units as elapsedTime).
     */
    static void smooth(float* x, float target, float elapsedTime, float riseTime, float fallTime);

private:

    inline static void addMatrix(const float* m, float scalar, float* dst);

    inline static void addMatrix(const float* m1, const float* m2, float* dst);

    inline static void subtractMatrix(const float* m1, const float* m2, float* dst);

    inline static void multiplyMatrix(const float* m, float scalar, float* dst);

    inline static void multiplyMatrix(const float* m1, const float* m2, float* dst);

    inline static void negateMatrix(const float* m, float* dst);

    inline static void transposeMatrix(const float* m, float* dst);

    inline static void transformVector4(const float* m, float x, float y, float z, float w, float* dst);

    inline static void transformVector4(const float* m, const float* v, float* dst);

    inline static void crossVector3(const float* v1, const float* v2, float* dst);


    inline static void addMatrix3(const float* m, float scalar, float* dst);

    inline static void addMatrix3(const float* m1, const float* m2, float* dst);

    inline static void subtractMatrix3(const float* m1, const float* m2, float* dst);

    inline static void multiplyMatrix3(const float* m, float scalar, float* dst);

    inline static void multiplyMatrix3(const float* m1, const float* m2, float* dst);

    inline static void negateMatrix3(const float* m, float* dst);

    inline static void transposeMatrix3(const float* m, float* dst);

    inline static void transformVector3(const float* m, float x, float y, float z, float* dst);

    inline static void transformVector3(const float* m, const float* v, float* dst);

    MathUtil();
};

}

#define MATRIX_SIZE ( sizeof(float) * 16 )
#define MATRIX3_SIZE ( sizeof(float) * 9 )

#ifdef GP_USE_NEON
#include "MathUtilNeon.inl"
#else
#include "MathUtil.inl"
#endif

#endif
