
#include <windows.h>
int main() {
    // Get a handle to myjavadll.dll's module.
    HINSTANCE hinstLib;
    hinstLib = LoadLibrary(TEXT("myjavadll.dll"));
    
    // If the handle is valid, try to get XorForever's address.
    if (hinstLib != NULL) 
    {
        FARPROC addXor = GetProcAddress(hinstLib, "XorForever");
        
        // If function address is valid try to run the function
        if (addXor != NULL) 
        {
            addXor();
        }
    }
}