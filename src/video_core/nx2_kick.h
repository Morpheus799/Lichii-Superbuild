// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "common/thread.h"

namespace VideoCommon {

/// Wakes the GPU thread while it polls its suspended channels. It slept 1 ms between polls.
/// Ported from Shakoquo/Lichii-sharkiix-version.
inline Common::Event& Nx2GpuKick() {
    static Common::Event event;
    return event;
}

} // namespace VideoCommon
