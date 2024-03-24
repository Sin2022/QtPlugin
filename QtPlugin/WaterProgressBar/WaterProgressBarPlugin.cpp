#include "WaterProgressBarPlugin.h"
#include "WaterProgressBar.h"

#include <QtPlugin>

WaterProgressBarPlugin::WaterProgressBarPlugin(QObject *parent)
    : QObject(parent)
{}

void WaterProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool WaterProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *WaterProgressBarPlugin::createWidget(QWidget *parent)
{
    return new WaterProgressBar(parent);
}

QString WaterProgressBarPlugin::name() const
{
    return QLatin1String("WaterProgressBar");
}

QString WaterProgressBarPlugin::group() const
{
    return QLatin1String("");
}

QIcon WaterProgressBarPlugin::icon() const
{
    return QIcon();
}

QString WaterProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString WaterProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool WaterProgressBarPlugin::isContainer() const
{
    return false;
}

QString WaterProgressBarPlugin::domXml() const
{
    return QLatin1String(R"(<widget class="WaterProgressBar" name="waterProgressBar">
</widget>)");
}

QString WaterProgressBarPlugin::includeFile() const
{
    return QLatin1String("WaterProgressBar.h");
}
