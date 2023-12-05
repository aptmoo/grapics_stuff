#include "window.h"
#include "generic/genericWindow.h"

namespace octo
{
    Scope<Window> Window::Create(const WindowDesc& desc)
    {
        return MakeScope<GenericWindow>(desc);
    }
} // namespace octo
