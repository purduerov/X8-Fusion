/*
Created by Jason King
January 2016
Purdue IEEE ROV
*/
#include "matrices.h"

int dot6(vect6 a, vect6 b)
{
    //return a.L.x * b.L.x + a.L.y * b.L.y + a.L.z * b.L.z + a.R.x * b.R.x + a.R.y * b.R.y + a.R.z * b.R.z; 
    return dot(a.L,b.L) + dot(a.R,b.R);
}

int dot(vect3 a, vect3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int dot2(vect2 a, vect2 b)
{
    return a.a * b.a + a.b * b.b;
}

vect3 cross(vect3 a, vect3 b)
{
    vect3 result;
    
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    
    return result;
}

vect3 add(vect3 a, vect3 b)
{
    vect3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vect6 add6(vect6 a, vect6 b)
{
    vect6 result;
    result.L = add(a.L,b.L);
    result.R = add(a.R,b.R);
    return result;
}

vect2 add2(vect2 a, vect2 b)
{
    vect2 result;
    result.a = a.a + b.a;
    result.b = a.b + b.b;
    return result;
}

vect2_f add2_f(vect2_f a, vect2_f b)
{
    vect2_f result;
    result.a = a.a + b.a;
    result.b = a.b + b.b;
    return result;
}

vect3 sub(vect3 a, vect3 b)
{
    vect3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

vect6 sub6(vect6 a, vect6 b)
{
    vect6 result;
    result.L = sub(a.L,b.L);
    result.R = sub(a.R,b.R);
    return result;
}

vect3 mul(vect3 a, int factor)
{
    vect3 result;
    result.x = a.x * factor;
    result.y = a.y * factor;
    result.z = a.z * factor;
    return result;
}

vect6 mul6(vect6 a, int factor)
{
    vect6 result;
    result.L = mul(a.L, factor);
    result.R = mul(a.R, factor);
    return result;
}

vect2 mul2(vect2 v, int factor)
{
    vect2 result;
    result.a = v.a * factor;
    result.b = v.b * factor;
    return result;
}

vect2_f mul2_f(vect2_f v, int factor)
{
    vect2_f result;
    result.a = v.a * factor;
    result.b = v.b * factor;
    return result;
}

vect3 div(vect3 a, int factor)
{
    vect3 result;
    result.x = a.x / factor;
    result.y = a.y / factor;
    result.z = a.z / factor;
    return result;
}

vect6 div6(vect6 a, int factor)
{
    vect6 result;
    result.L = div(a.L, factor);
    result.R = div(a.R, factor);
    return result;
}

vect3 vect3Make(int a, int b, int c)
{
    vect3 result;
    result.x = a;
    result.y = b;
    result.z = c;
    return result;
}

vect6 vect6Make(int a, int b, int c, int d, int e, int f)
{
    vect6 result;
    result.L = vect3Make(a, b, c);
    result.R = vect3Make(d, e, f);
    return result;
}

vect2 vect2Make(int a, int b)
{
    vect2 result;
    result.a = a;
    result.b = b;
    return result;
}

vect8 matMul_86x61(matrix8_6 mat, vect6 v)
{
    vect8 result;
    result.a = dot6(mat.t1, v);
    result.b = dot6(mat.t2, v);
    result.c = dot6(mat.t3, v);
    result.d = dot6(mat.t4, v);
    result.e = dot6(mat.t5, v);
    result.f = dot6(mat.t6, v);
    result.g = dot6(mat.t7, v);
    result.h = dot6(mat.t8, v);
    return result;
}

vect3 matMul_33x31(matrix3_3 m,vect3 v)
{
    vect3 result;
    result.x = dot(m.a, v);
    result.y = dot(m.b, v);
    result.z = dot(m.c, v);
    return result;
}

matrix2_2 matMul_22x22(matrix2_2 a, matrix2_2 b)
{
    matrix2_2 result;
    result.one.a = dot2(a.one, vect2Make(b.one.a, b.two.a));
    result.one.b = dot2(a.one, vect2Make(b.one.b, b.two.b));
    result.two.a = dot2(a.two, vect2Make(b.one.a, b.two.a));
    result.two.b = dot2(a.two, vect2Make(b.one.b, b.two.b));
    return result;
}

matrix3_3 matMul_33x33(matrix3_3 m1, matrix3_3 m2)
{
    matrix3_3 result;
    result.a.x = dot(m1.a, vect3Make(m2.a.x, m2.b.x, m2.c.x));
    result.a.y = dot(m1.a, vect3Make(m2.a.y, m2.b.y, m2.c.y));
    result.a.z = dot(m1.a, vect3Make(m2.a.z, m2.b.z, m2.c.z));
    
    result.b.x = dot(m1.b, vect3Make(m2.a.x, m2.b.x, m2.c.x));
    result.b.y = dot(m1.b, vect3Make(m2.a.y, m2.b.y, m2.c.y));
    result.b.z = dot(m1.b, vect3Make(m2.a.z, m2.b.z, m2.c.z));
    
    result.c.x = dot(m1.c, vect3Make(m2.a.x, m2.b.x, m2.c.x));
    result.c.y = dot(m1.c, vect3Make(m2.a.y, m2.b.y, m2.c.y));
    result.c.z = dot(m1.c, vect3Make(m2.a.z, m2.b.z, m2.c.z));
    return result;
}

matrix2_2 invert2_2(matrix2_2 m)
{
    matrix2_2 result;
    int det = m.one.a * m.two.b - m.one.b * m.two.a;//ad-bc
    result.one.a = m.two.b*1024/det;
    result.two.b = m.one.a*1024/det;
    result.one.b = -m.one.b*1024/det;
    result.two.a = -m.two.a*1024/det;
    return result;
}