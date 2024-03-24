#include "circleprogressbarplugin.h"
#include "circleprogressbar.h"

#include <QtPlugin>

CircleProgressBarPlugin::CircleProgressBarPlugin(QObject *parent)
    : QObject(parent)
{}

void CircleProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CircleProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CircleProgressBarPlugin::createWidget(QWidget *parent)
{
    return new circleprogressbar(parent);
}

QString CircleProgressBarPlugin::name() const
{
    return QLatin1String("CircleProgressBar");
}

QString CircleProgressBarPlugin::group() const
{
    return QLatin1String("");
}

QIcon CircleProgressBarPlugin::icon() const
{
    return QIcon();
}

QString CircleProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString CircleProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool CircleProgressBarPlugin::isContainer() const
{
    return false;
}

QString CircleProgressBarPlugin::domXml() const
{
    return QLatin1String(R"(<widget class="CircleProgressBar" name="circleProgressBar">
</widget>)");
}

QString CircleProgressBarPlugin::includeFile() const
{
    return QLatin1String("circleprogressbar.h");
}
