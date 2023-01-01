#pragma once

#include "gfx/WindowSubsystem.hpp"
#include "gfx/GraphicsSubsystem.hpp"

WindowSubsystem initWindowSubsystem();
GraphicsSubsystem initGraphicsSubsystem(WindowSubsystem* wSubSys);
