#include "LoadingPlugin.h"
#include "Loading.h"

#include <QtPlugin>

LoadingPlugin::LoadingPlugin(QObject *parent)
    : QObject(parent)
{}

void LoadingPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LoadingPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LoadingPlugin::createWidget(QWidget *parent)
{
    return new Loading(parent);
}

QString LoadingPlugin::name() const
{
    return QLatin1String("Loading");
}

QString LoadingPlugin::group() const
{
    return QLatin1String("");
}

QIcon LoadingPlugin::icon() const
{
    return QIcon();
}

QString LoadingPlugin::toolTip() const
{
    return QLatin1String("");
}

QString LoadingPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool LoadingPlugin::isContainer() const
{
    return false;
}

QString LoadingPlugin::domXml() const
{
    return QLatin1String(R"(<widget class="Loading" name="loading">
</widget>)");
}

QString LoadingPlugin::includeFile() const
{
    return QLatin1String("Loading.h");
}
