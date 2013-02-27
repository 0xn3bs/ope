#ifndef VECTOR_H__
#define VECTOR_H__

#include <math.h>
#include <ostream>

template <class T>
class Vec1
{
public:
	T x;

	Vec1()
	{
		x = 0;
	}

	Vec1(const T x)
	{
		this->x = x;
	}

	~Vec1()
	{
	}

	T Magnitude()
	{
		return x;
	}

	T DotProduct(const Vec1 &vec1)
	{
		return (vec1.x * x);
	}

	Vec1<T> &operator=(const Vec1<T> &rhs)
	{
		x = rhs.x;
		return *this;
	}

	Vec1<T> &operator+=(const T rhs) 
	{
		x += rhs;
		return *this;
	}

	Vec1<T> operator+(const T rhs) const
	{
		return Vec1(*this)+=rhs;
	}

	Vec1<T> &operator+=(const Vec1<T> &rhs) 
	{
		x += rhs.x;
		return *this;
	}

	Vec1<T> operator+(const Vec1<T> &rhs) const
	{
		return Vec1(*this)+=rhs;
	}

	Vec1<T> &operator-=(const Vec1<T> &rhs) 
	{
		x -= rhs.x;
		return *this;
	}

	Vec1<T> operator-(const Vec1<T> &rhs) const
	{
		return Vec1(*this)-=rhs;
	}

	Vec1<T> &operator*=(const T rhs)
	{
		x *= rhs;
		return *this;
	}

	Vec1<T> operator*(const T rhs) const
	{
		return Vec1(*this)*=rhs;
	}

	Vec1<T> &operator*=(const Vec1<T> &rhs)
	{
		*this = DotProduct(rhs);
		return *this;
	}

	Vec1<T> operator*(const Vec1<T> &rhs) const
	{
		return Vec1(*this)*=rhs;
	}

	Vec1<T> &operator/=(const T rhs)
	{
		x /= rhs;
		return *this;
	}

	Vec1<T> operator/(const T rhs) const
	{
		return Vec1(*this)/=rhs;
	}

	T& operator[] (unsigned int i)
	{
		if(i > 0)
		{
			std::cerr << "Vec1 subscript out of range";
			throw SUBCRIPT_OUT_OF_RANGE;
		}
		return x;
	}

	friend std::ostream &operator<<(std::ostream &stream, Vec1<T> rhs)
	{
		stream << "<" << rhs.x << ">";
		return stream;
	}
};

template <class T>
class Vec2
{
public:
	T x, y;

	Vec2()
	{
		x = y = 0;
	}

	Vec2(const T x, const T y)
	{
		this->x = x;
		this->y = y;
	}

	~Vec2()
	{
	}

	T Magnitude()
	{
		return sqrt(x*x + y*y);
	}

	T DotProduct(const Vec2 &vec2)
	{
		return (vec2.x * x) + (vec2.y * y);
	}

	Vec2<T> & operator=(const Vec2<T> &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Vec2<T> &operator+=(const T rhs) 
	{
		x += rhs;
		y += rhs;
		return *this;
	}

	Vec2<T> operator+(const T rhs) const
	{
		return Vec2(*this)+=rhs;
	}

	Vec2<T> &operator+=(const Vec2<T> &rhs) 
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vec2<T> operator+(const Vec2<T> &rhs) const
	{
		return Vec2(*this)+=rhs;
	}

	Vec2<T> &operator-=(const Vec2<T> &rhs) 
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vec2<T> operator-(const Vec2<T> &rhs) const
	{
		return Vec2(*this)-=rhs;
	}

	Vec2<T> &operator*=(const T rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	Vec2<T> operator*(const T rhs) const
	{
		return Vec2(*this)*=rhs;
	}

	Vec2<T> &operator*=(const Vec2<T> &rhs)
	{
		*this = DotProduct(rhs);
		return *this;
	}

	Vec2<T> operator*(const Vec2<T> &rhs) const
	{
		return Vec2(*this)*=rhs;
	}

	Vec2<T> &operator/=(const T rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	Vec2<T> operator/(const T rhs) const
	{
		return Vec2(*this)/=rhs;
	}

	T& operator[] (unsigned int i)
	{
		if(i > 1)
		{
			std::cerr << "Vec2 subscript out of range";
			throw SUBCRIPT_OUT_OF_RANGE;
		}
		return i == 0 ? x : y;
	}

	Vec2<int> ToInts()
	{
		return Vec2<int>(this->x, this->y);
	}

	Vec2<float> ToFloats()
	{
		return Vec2<float>(this->x, this->y);
	}

	Vec2<double> ToDoubles()
	{
		return Vec2<double>(this->x, this->y);
	}

	friend std::ostream &operator<<(std::ostream &stream, Vec2<T> rhs)
	{
		stream << "<" << rhs.x << ", " << rhs.y << ">";
		return stream;
	}
};

template <class T>
class Vec3
{
public:
	T x, y, z;

	Vec3()
	{
		x = y = z = 0;
	}

	Vec3(const T x, const T y, const T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	~Vec3()
	{
	}

	T Magnitude()
	{
		return sqrt(x*x + y*y + z*z);
	}

	T DotProduct(const Vec3 &vec3)
	{
		return (vec3.x * x) + (vec3.y * y) + (vec3.z * z);
	}

	Vec3<T> Normalize()
	{
		return Vec3(*this)/=Magnitude();
	}

	Vec3<T> CrossProduct(const Vec3 &vec3)
	{
		return 
			Vec3<T>((this->y * vec3.z - this->z * vec3.y), 
			(this->z * vec3.x - this->x * vec3.z),
			(this->x * vec3.y - this->y * vec3.x));
	}

	Vec3<T> &operator=(const Vec3<T> &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	Vec3<T> &operator+=(const T rhs) 
	{
		x += rhs;
		y += rhs;
		z += rhs;
		return *this;
	}

	Vec3<T> operator+(const T rhs) const
	{
		return Vec3(*this)+=rhs;
	}

	Vec3<T> &operator+=(const Vec3<T> &rhs) 
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Vec3<T> operator+(const Vec3<T> &rhs) const
	{
		return Vec3(*this)+=rhs;
	}

	Vec3<T> &operator-=(const Vec3<T> &rhs) 
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Vec3<T> operator-(const Vec3<T> &rhs) const
	{
		return Vec3(*this)-=rhs;
	}

	Vec3<T> &operator*=(const T rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}

	Vec3<T> operator*(const T rhs) const
	{
		return Vec3(*this)*=rhs;
	}

	Vec3<T> &operator*=(const Vec3<T> &rhs)
	{
		*this = DotProduct(rhs);
		return *this;
	}

	Vec3<T> operator*(const Vec3<T> &rhs) const
	{
		return Vec3(*this)*=rhs;
	}

	Vec3<T> &operator/=(const T rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}

	Vec3<T> operator/(const T &rhs) const
	{
		return Vec3(*this)/=rhs;
	}

	//	Cross product
	Vec3<T> &operator%=(const Vec3<T> &rhs) 
	{
		*this = CrossProduct(rhs);
		return *this;
	}

	Vec3<T> operator%(const Vec3<T> &rhs) const
	{
		return Vec3(*this)%=rhs;
	}

	T& operator[] (unsigned int i)
	{
		if(i > 2)
		{
			std::cerr << "Vec3 subscript out of range";
			throw SUBCRIPT_OUT_OF_RANGE;
		}

		return i == 0 ? x : i == 1 ? y : z;
	}

	Vec3<int> ToInts()
	{
		return Vec2<int>(this->x, this->y, this->z);
	}

	Vec3<float> ToFloats()
	{
		return Vec2<float>(this->x, this->y, this->z);
	}

	Vec3<double> ToDoubles()
	{
		return Vec2<double>(this->x, this->y, this->z);
	}

	friend std::ostream &operator<<(std::ostream &stream, Vec3<T> rhs)
	{
		stream << "<" << rhs.x << ", " << rhs.y << ", " << rhs.z << ">";
		return stream;
	}
};

template <class T>
class Vec4
{
public:
	T x, y, z, u;

	Vec4()
	{
		x = y = z = u = 0;
	}

	Vec4(const T &x, const T &y, const T &z, const T &u)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->u = u;
	}

	~Vec4()
	{
	}

	T Magnitude()
	{
		return sqrt(x*x + y*y + z*z + u*u);
	}

	T DotProduct(const Vec4 &vec4)
	{
		return (vec4.x * x) + (vec4.y * y) + (vec4.z * z) + (vec4.u * u);
	}

	Vec4<T> & operator=(const Vec4<T> &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		u = rhs.u;
		return *this;
	}

	Vec4<T> &operator+=(const T rhs) 
	{
		x += rhs;
		y += rhs;
		z += rhs;
		u += rhs.u;
		return *this;
	}

	Vec4<T> operator+(const T rhs) const
	{
		return Vec4(*this)+=rhs;
	}

	Vec4<T> &operator+=(const Vec4<T> &rhs) 
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		u += rhs.u;
		return *this;
	}

	Vec4<T> operator+(const Vec4<T> &rhs) const
	{
		return Vec4(*this)+=rhs;
	}

	Vec4<T> &operator-=(const Vec4<T> &rhs) 
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		u -= rhs.u;
		return *this;
	}

	Vec4<T> operator-(const Vec4<T> &rhs) const
	{
		return Vec4(*this)-=rhs;
	}

	Vec4<T> &operator*=(const T rhs)
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		u *= rhs;
		return *this;
	}

	Vec4<T> operator*(const T rhs) const
	{
		return Vec4(*this)*=rhs;
	}

	Vec4<T> &operator*=(const Vec4<T> &rhs)
	{
		*this = DotProduct(rhs);
		return *this;
	}

	Vec4<T> operator*(const Vec4<T> &rhs) const
	{
		return Vec4(*this)*=rhs;
	}

	Vec4<T> &operator/=(const T rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		u /= rhs;
		return *this;
	}

	Vec4<T> operator/(const T rhs) const
	{
		return Vec4(*this)/=rhs;
	}

	T& operator[] (unsigned int i)
	{
		if(i > 3)
		{
			std::cerr << "Vec4 subscript out of range";
			throw SUBCRIPT_OUT_OF_RANGE;
		}
		return i == 0 ? x : i == 1 ? y : i == 2 ? z : u;
	}

	Vec4<int> ToInts()
	{
		return Vec4<int>(this->x, this->y, this->z, this->u);
	}

	Vec4<float> ToFloats()
	{
		return Vec4<float>(this->x, this->y, this->z, this->u);
	}

	Vec4<double> ToDoubles()
	{
		return Vec4<double>(this->x, this->y, this->z, this->u);
	}

	friend std::ostream &operator<<(std::ostream &stream, Vec4<T> rhs)
	{
		stream << "<" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.u << ">";
		return stream;
	}
};

#endif  /*VECTOR_H_*/
