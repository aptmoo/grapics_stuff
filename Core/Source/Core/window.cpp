#include "window.h"
#include "generic/genericWindow.h"

namespace octo
{
    Scope<IWindow> IWindow::Create(const WindowDesc& desc)
    {
        return MakeScope<GenericWindow>(desc);
    }
} // namespace octo
