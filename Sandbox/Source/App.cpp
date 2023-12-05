#include "Core/window.h"

using namespace octo;

int main()
{
    Scope<Window> window = Window::Create({"Title", 1280, 720});
}