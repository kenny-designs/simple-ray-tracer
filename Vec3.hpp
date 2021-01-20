#ifndef VEC3_HPP
#define VEC3_HPP

/**
 * Represents a 3-dimensional vector.
 */ 
template <typename T>
class Vec3
{
public:
    T x, y, z;

    /** Default constructor zero initializes vector. */
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}

    /** Sets each component of vector to a single value. */
    Vec3(T xx) : x(xx), y(xx), z(xx) {}

    /** Manually set x, y, and z component of vector. */
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

    /**
     * Normalizes the vector.
     * 
     * @return The vector after normalizing.
     */
    Vec3& normalize()
    {
        T nor2 = length2();

        // Only normalize vector if it isn't a zero vector.
        if (nor2 > 0)
        {
            T invNor = 1 / sqrt(nor2);
            x *= invNor;
            y *= invNor;
            z *= invNor;
        }

        return *this;
    }

    /**
     * Perform scalar multiplication and return a new vector.
     * 
     * @f The scalar value to multiply by.
     * @return The resulting scalar multiplied vector.
     */ 
    Vec3<T> operator*(const T &f) const
    {
        return Vec3<T>(x * f, y * f, z * f);
    }

    /**
     * Perform element-wise vector multiplication (Hadamard Product).
     * 
     * @v The vector to multiply by.
     * @return The resulting element-wise multiplication vector.
     */ 
    Vec3<T> operator*(const Vec3<T> &v) const
    {
        return Vec3<T>(x * v.x, y * v.y, z * v.z);
    }

    /**
     * Find the dot product between two vectors.
     * 
     * @v The vector to find the dot product with.
     * @return The resulting scalar value of the dot product.
     */ 
    T dot(const Vec3<T> &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    /**
     * Perform vector subtraction.
     * 
     * @v The vector to subtract from the calling vector.
     * @return The resulting vector difference.
     */ 
    Vec3<T> operator-(const Vec3<T> &v) const
    {
        return Vec3<T>(x - v.x, y - v.y, z - v.z);
    }

    /**
     * Perform vector addition.
     * 
     * @v The vector to add to the calling vector.
     * @return The resulting vector addition.
     */ 
    Vec3<T> operator+(const Vec3<T> &v) const
    {
        return Vec3<T>(x + v.x, y + v.y, z + v.z);
    }

    /**
     * Performs vector addition on the left side vector.
     * 
     * @v The vector to add to the left side vector.
     * @return Reference to the left side vector.
     */
    Vec3<T>& operator+=(const Vec3<T> &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    /**
     * Performs element-wise vector multiplication (Hadamard Product)
     * on the left side vector.
     * 
     * @v The vector to perform element-wise vector multiplication on the
     * left side vector.
     * @return Reference to the left side vector.
     */ 
    Vec3<T>& operator*=(const Vec3<T> &v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    /**
     * Negates each element of the vector.
     * 
     * @return The negated vector.
     */ 
    Vec3<T> operator-() const
    {
        return Vec3<T>(-x, -y, -z);
    }

    /**
     * Finds the squared length of the vector.
     * 
     * @return Vector's length squared.
     */ 
    T length2() const
    {
        return x * x + y * y + z * z;
    }

    /**
     * Finds the actual length of the vector.
     * 
     * @return Vector's length.
     */ 
    T length() const
    {
        return sqrt(length2());
    }

    /**
     * Overload insertion operator to print each element of the vector.
     * 
     * @return The ostream.
     */ 
    friend std::ostream &operator<<(std::ostream &os, const Vec3<T> &v)
    {
        os << "[" << v.x << " " << v.y << " " << v.z << "]";
        return os;
    }
};

/** Alias floating point vectors to just Vec3f. */
typedef Vec3<float> Vec3f;

#endif