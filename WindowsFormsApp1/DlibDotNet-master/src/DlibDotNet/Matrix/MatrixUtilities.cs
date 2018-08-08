﻿using System;
using System.Runtime.InteropServices;
using DlibDotNet.Extensions;

// ReSharper disable once CheckNamespace
namespace DlibDotNet
{

    public static partial class Dlib
    {

        #region Methods

        public static MatrixOp JoinRows(MatrixBase matrix1, MatrixBase matrix2)
        {
            if (matrix1 == null)
                throw new ArgumentNullException(nameof(matrix1));
            if (matrix2 == null)
                throw new ArgumentNullException(nameof(matrix2));

            matrix1.ThrowIfDisposed();
            matrix2.ThrowIfDisposed();

            var templateRows = matrix1.TemplateRows;
            var templateColumns = matrix1.TemplateColumns;

            if (templateRows != matrix2.TemplateRows)
                throw new ArgumentException();
            if (templateColumns != matrix2.TemplateColumns)
                throw new ArgumentException();

            var type1 = matrix1.MatrixElementType.ToNativeMatrixElementType();
            var type2 = matrix2.MatrixElementType.ToNativeMatrixElementType();
            if (type1 != type2)
                throw new ArgumentException();

            var ret = Native.matrix_join_rows(type1,
                                              matrix1.NativePtr,
                                              matrix2.NativePtr,
                                              templateRows,
                                              templateColumns,
                                              out var matrixOp);
            switch (ret)
            {
                case Native.ErrorType.MatrixElementTypeNotSupport:
                    throw new ArgumentException($"{type1} is not supported.");
            }

            var imageType = matrix1.MatrixElementType;
            return new MatrixOp(Native.ElementType.OpJoinRows, imageType, matrixOp, templateRows, templateColumns);
        }

        public static double Length(MatrixBase matrix)
        {
            if (matrix == null)
                throw new ArgumentNullException(nameof(matrix));

            matrix.ThrowIfDisposed();

            var type = matrix.MatrixElementType.ToNativeMatrixElementType();
            var ret = Native.matrix_length(type, matrix.NativePtr, matrix.TemplateRows, matrix.TemplateColumns, out var length);
            switch (ret)
            {
                case Native.ErrorType.MatrixElementTypeNotSupport:
                    throw new ArgumentException($"{type} is not supported.");
            }

            return length;
        }

        public static MatrixRangeExp<double> Linspace(double start, double end, int num)
        {
            var matrixRange = Native.linspace(start, end, num);
            return new MatrixRangeExp<double>(matrixRange);
        }

        public static Point MaxPoint(MatrixOp matrix)
        {
            if (matrix == null)
                throw new ArgumentNullException(nameof(matrix));

            matrix.ThrowIfDisposed();

            var type = matrix.Array2DType;
            var ret = Native.matrix_max_point(type, matrix.NativePtr, out var point);
            switch (ret)
            {
                case Native.ErrorType.MatrixElementTypeNotSupport:
                    throw new ArgumentException($"{type} is not supported.");
            }

            return new Point(point);
        }

        public static Matrix<T> Mean<T>(MatrixOp matrix)
            where T : struct
        {
            if (matrix == null)
                throw new ArgumentNullException(nameof(matrix));

            matrix.ThrowIfDisposed();

            Matrix<T>.TryParse<T>(out var type);
            var ret = Native.matrix_mean(type.ToNativeMatrixElementType(),
                                         matrix.NativePtr,
                                         matrix.TemplateRows,
                                         matrix.TemplateColumns,
                                         matrix.ElementType,
                                         out var value);
            switch (ret)
            {
                case Native.ErrorType.MatrixElementTypeNotSupport:
                    throw new ArgumentException($"{type} is not supported.");
            }

            return new Matrix<T>(value, matrix.TemplateRows, matrix.TemplateColumns);
        }

        public static MatrixOp Trans(MatrixBase matrix)
        {
            if (matrix == null)
                throw new ArgumentNullException(nameof(matrix));

            matrix.ThrowIfDisposed();

            var templateRows = matrix.TemplateRows;
            var templateColumns = matrix.TemplateColumns;

            var type = matrix.MatrixElementType.ToNativeMatrixElementType();
            var ret = Native.matrix_trans(type, matrix.NativePtr, templateRows, templateColumns, out var matrixOp);
            switch (ret)
            {
                case Native.ErrorType.MatrixElementTypeNotSupport:
                    throw new ArgumentException($"{type} is not supported.");
            }

            var imageType = matrix.MatrixElementType;
            return new MatrixOp(Native.ElementType.OpTrans, imageType, matrixOp, templateRows, templateColumns);
        }

        #endregion

        internal sealed partial class Native
        {

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern IntPtr linspace(double start, double end, int num);

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern ErrorType matrix_join_rows(MatrixElementType type, IntPtr matrix1, IntPtr matrix2, int templateRows, int templateColumns, out IntPtr ret);

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern ErrorType matrix_length(MatrixElementType type, IntPtr matrix, int templateRows, int templateColumns, out double ret);

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern ErrorType matrix_mean(MatrixElementType array2DType, IntPtr matrix_op, int templateRows, int templateColumns, ElementType type, out IntPtr point);

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern ErrorType matrix_max_point(Array2DType array2DType, IntPtr matrix_op, out IntPtr point);

            [DllImport(NativeMethods.NativeLibrary, CallingConvention = NativeMethods.CallingConvention)]
            public static extern ErrorType matrix_trans(MatrixElementType elementType, IntPtr matrix, int templateRows, int templateColumns, out IntPtr matrix_op);
        }

    }

}