#ifndef GRAPHICS_DEVICE_H
#define GRAPHICS_DEVICE_H
#include "Core/types.h"

namespace octo
{
    class IGraphicsDevice
    {
    public:
        virtual ~IGraphicsDevice() = default;


        static Scope<IGraphicsDevice> Create(void* windowHandle);
    };
} // namespace octo


#endif