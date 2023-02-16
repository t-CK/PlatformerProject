// Math library has been reused from OnyxEngine -project @ https://github.com/t-CK/OnyxEngine

#pragma once
#include <cmath>

namespace Game

{
	// 3D Vector of X, Y and Z values
	struct Vector
	{
		Vector(float x, float y, float z) :
			X(x), Y(y), Z(z) { }
		inline Vector operator+ (Vector& v1) { return { X + v1.X, Y + v1.Y, Z + v1.Z }; }
		inline Vector operator- (Vector& v1) { return { X - v1.X, Y - v1.Y, Z - v1.Z }; }
		// Returns a dot product of 2 vectors
		inline float operator* (Vector& v1) { return(X * v1.X) + (Y * v1.Y) + (Z * v1.Z); }
		inline Vector operator/ (float value) { return { X / value, Y / value, Z / value }; }
		inline Vector operator/ (Vector& v1) { return { X / v1.X, Y / v1.Y, Z / v1.Z }; }

		// Add another Vector3
		// Overwrites the values in Vector
		inline void Add(Vector v1) { X += v1.X; Y += v1.Y; Z += v1.Z; }

		inline float Length() { return sqrt((*this) * (*this)); }

		inline Vector Normalize(float value) { return (*this) / Length(); }
        
		Vector CrossProduct(Vector& v2);

		float X, Y, Z;
	};

	struct Rotator
	{
		Rotator(float p, float y, float r) :
		    Pitch(p), Yaw(y), Roll(r) { }

		float Pitch, Yaw, Roll;
	};

	// A unit matrix containing location, rotation and scale values
	struct Matrix
	{
	public:
		Matrix(Vector& location, Rotator& rotation, Vector& scale) :
			Location(location), Rotation(rotation), Scale(scale) { }

		
		Vector Location;
		Rotator& Rotation;
		Vector Scale;
	};
}