#include "kernelUtil.h"
#include "userinput/keyboard.h"

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;
    uint32_t colour = GlobalRenderer->Colour;
    GlobalRenderer->Colour = 0x0000ff00;
    GlobalRenderer->Print("Horizon Kernel Initialized Successfully");
    GlobalRenderer->Colour = colour;
    GlobalRenderer->NewLine();
    GlobalRenderer->Colour = 0xffff00;
    GlobalRenderer->Print("Continuing in 5 seconds..");
    GlobalRenderer->Colour = colour;
    
    //TODO Pause for 5 seconds.

    GlobalRenderer->Clear();
    GlobalRenderer->CursorPosition = {0, 0};
    GlobalRenderer->Print("Welcome to Horizon OS!");
	Keyboard::Initialize();


    while(true){
        ProcessMousePacket();
    }

    while(true);
}