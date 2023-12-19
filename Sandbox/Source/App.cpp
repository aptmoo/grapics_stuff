#include "Core/window.h"

using namespace octo;

int main()
{
    Scope<IWindow> window = IWindow::Create({"Title", 1280, 720});

    while (true)
    {
        window->Update();
    }
}