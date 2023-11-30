#pragma once
#include <memory>

#define STRAIGHT_API __declspec(dllexport)

#ifdef WITH_STRAIGHT_DEBUG
	#define STRAIGHT_DEBUG

	#define STRAIGHT_ASSERT(cond, pr) { if (!(cond)) { fprintf(stderr, "Fatal error: %s\n", pr); __debugbreak(); } }
	#define STRAIGHT_ASSERT_S(cond) { if (!(cond)) { __debugbreak(); } }
	#define STRAIGHT_NOT_IMPLEMENTED() STRAIGHT_ASSERT(false, "Not implemented function reached.");
#else
	#define STRAIGHT_ASSERT(x, msg); 
	#define STRAIGHT_ASSERT_S(x); 
	#define STRAIGHT_NOT_IMPLEMENTED();
#endif

namespace Straight
{
	template<typename T>
	using UPtr = std::unique_ptr<T>;
	template<typename T>
	using SPtr = std::shared_ptr<T>;
	template<typename T>
	using WPtr = std::weak_ptr<T>;
}