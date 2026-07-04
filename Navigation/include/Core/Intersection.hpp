#pragma once
#include <QString>
#include <QVariantMap>
#include <cstdint>

namespace NavApp::Core {
    struct Intersection {
        uint64_t id;
        double x{0.0};
        double y{0.0};

        QString name;
        QVariantMap metadata;

        bool isValid() {return id != 0; }
    };
}
