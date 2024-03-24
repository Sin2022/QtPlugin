#include "ClockWidgetPlugin.h"
#include "ClockWidget.h"

#include <QtPlugin>

ClockWidgetPlugin::ClockWidgetPlugin(QObject *parent)
    : QObject(parent)
{}

void ClockWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ClockWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ClockWidgetPlugin::createWidget(QWidget *parent)
{
    return new ClockWidget(parent);
}

QString ClockWidgetPlugin::name() const
{
    return QLatin1String("ClockWidget");
}

QString ClockWidgetPlugin::group() const
{
    return QLatin1String("");
}

QIcon ClockWidgetPlugin::icon() const
{
    return QIcon();
}

QString ClockWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ClockWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ClockWidgetPlugin::isContainer() const
{
    return false;
}

QString ClockWidgetPlugin::domXml() const
{
    return QLatin1String(R"(<widget class="ClockWidget" name="clockWidget">
</widget>)");
}

QString ClockWidgetPlugin::includeFile() const
{
    return QLatin1String("ClockWidget.h");
}
