#ifndef GENERIC_WINDOW_H
#define GENERIC_WINDOW_H
#include "Core/window.h"
#include "Core/types.h"

namespace octo
{
    class GenericWindow : public Window
    {
    public: 
        GenericWindow(const WindowDesc& desc);
        virtual ~GenericWindow();

        virtual void Update();

        virtual void* GetNativeHandle(){ return m_WindowHandle; };

    private:
        void* m_WindowHandle;
    };
} // namespace octo


#endif