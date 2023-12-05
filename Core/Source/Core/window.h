#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H
#include "Core/types.h"
#include <string>

namespace octo
{ 
    struct WindowDesc
    {
        std::string Title;
        u32 Width, Height;
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        /**
         * @brief Update this window.
         * Should be called after rendering a frame.
         * 
         */
        virtual void Update() = 0;

        /**
         * @brief Returns the internal handle to the window object.
         * 
         * @return void* 
         */
        virtual void* GetNativeHandle() = 0;

        virtual void* GetNativeDisplay() = 0;
        virtual void* GetNativeWindow() = 0;

        static Scope<Window> Create(const WindowDesc& desc);
    };
} // namespace name


#endif