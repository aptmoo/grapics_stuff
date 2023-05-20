#ifndef COMMON_WINDOW_H
#define COMMON_WINDOW_H
#include "types.h"
#include <string>

struct WindowDesc
{
    std::string name;
    u32 width, height;
};

class Window
{
private:

public:
    virtual ~Window() = default;
    
    // Functions
    /**
     * @brief Swap the window buffers.
     * 
     */
    virtual void Swap();

    // Getters and setters
    /**
     * @brief Get the native window handle, as a void ptr.
     * This handle is platform dependant. Be careful with it.
     * 
     * @return void* 
     */
    virtual void* GetNativeWindowHandle();

    

    // Create
    static Scope<Window> Create(const WindowDesc& desc);
};

#endif