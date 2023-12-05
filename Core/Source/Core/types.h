/**
 * @file types.h
 * @brief Commonly used types.
 * Aliases for ints, uints, floats and smart pointers are found here.
 * Any future aliases should be placed here!
 * @version 0.1
 * @date 2023-07-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H
#include <cstdint>
#include <cstddef>
#include <memory>

typedef std::uint8_t u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;

typedef std::int8_t i8;
typedef std::int16_t i16;
typedef std::int32_t i32;
typedef std::int64_t i64;

typedef float f32;
typedef double f64;

typedef std::size_t usize;

namespace octo
{
    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename T, typename... TArgs>
    constexpr Ref<T> MakeRef(TArgs &&...args)
    {
        return std::make_shared<T>(std::forward<TArgs>(args)...);
    };

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T, typename... TArgs>
    constexpr Scope<T> MakeScope(TArgs &&...args)
    {
        return std::make_unique<T>(std::forward<TArgs>(args)...);
    };
} // namespace octo

#endif