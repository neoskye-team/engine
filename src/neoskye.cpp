#include "neoskye.hpp"
#include "gfx/GraphicsSubsystem.hpp"

WindowSubsystem initWindowSubsystem() {
    WindowSubsystem wSubSys;
    wSubSys.initWindow();
    return wSubSys;
}

GraphicsSubsystem initGraphicsSubsystem(WindowSubsystem* wSubSys) {
    GraphicsSubsystem gSubSys;
    gSubSys.init(wSubSys);
    return gSubSys;
}
