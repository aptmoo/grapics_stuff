#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H
#include <cstdint>
#include <cstddef>
#include <memory>

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;

typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;

typedef float       f32;
typedef double      f64;

typedef size_t      usize;

template <typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename... TArgs>
constexpr Ref<T> MakeRef(TArgs&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename... TArgs>
constexpr Scope<T> MakeScope(TArgs&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

#endif