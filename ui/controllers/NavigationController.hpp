#pragma once

#include <QObject>

#include <application/RoutePresentationData.hpp>

#include <core/types/Types.hpp>

namespace application
{
class NavigationService;
}

class NavigationController : public QObject
{
    Q_OBJECT

public:

    explicit NavigationController(
        application::NavigationService& service,
        QObject* parent = nullptr
    );

public slots:

    void requestRoute(
        core::types::NodeId start,
        core::types::NodeId destination
    );

signals:

    void routeReady(
        const application::RoutePresentationData& route
    );

    void navigationFailed(
        const QString& message
    );

private:

    application::NavigationService& navigationService;
};
