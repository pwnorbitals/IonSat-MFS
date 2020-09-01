#pragma once

namespace RFF::Subsystems::Attitude {
    enum class Modes {
        NADIR,
        RETROGRADE,
        AEROBRAKING,
        SUN,
        SUNAERO,
        BDOT,
        CUSTOM
    };
}