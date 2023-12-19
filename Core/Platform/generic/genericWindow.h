#ifndef GENERIC_WINDOW_H
#define GENERIC_WINDOW_H
#include "Core/window.h"
#include "Core/types.h"

namespace octo
{
    class GenericWindow : public IWindow
    {
    public: 
        GenericWindow(const WindowDesc& desc);
        virtual ~GenericWindow() override;

        virtual void Update() override;

        virtual void* GetNativeHandle() override { return m_WindowHandle; };

        virtual void* GetNativeDisplay() override;
        virtual void* GetNativeWindow() override;

    private:
        void* m_WindowHandle;
    };
} // namespace octo


#endif