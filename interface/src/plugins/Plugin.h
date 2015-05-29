#pragma once

#include <QString>
#include <QObject>

class PluginContainer {
    virtual void addMenuItem(const QString& path, std::function<void()> onClicked, bool checkable = false, bool checked = false, const QString& groupName = "") = 0;
};

class Plugin : public QObject {
public:
    virtual const QString & getName() = 0;
    virtual bool isSupported() const { return true; }

    virtual void init() {}
    virtual void deinit() {}

    virtual void activate(PluginContainer * container) {}
    virtual void deactivate() {}

    virtual void idle() {}
};
