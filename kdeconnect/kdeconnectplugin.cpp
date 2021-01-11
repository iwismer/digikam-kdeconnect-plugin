/* ============================================================
 *
 * Date        : 2021-01-11
 * Description : KDE Connect Share plugin.
 *
 * Copyright (C) 2019-2020 by Gilles Caulier <caulier dot gilles at gmail dot
 * com>
 * Copyright (C) 2021 by Isaac Wismer <isaac at iwismer dot ca>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#include "kdeconnectplugin.h"

// Qt includes

#include <QApplication>
#include <QList>
#include <QMessageBox>
#include <QUrl>

// digiKam includes

#include <dinfointerface.h>

// Local includes

#include "i18nutils.h"
#include "kdeconnectwindow.h"

namespace DigikamKDEConnectPlugin
{

    KDEConnectPlugin::KDEConnectPlugin(QObject *const parent)
        : DPluginGeneric(parent)
    {
        s_initI18nResource();
        s_loadI18n(name());
    }

    KDEConnectPlugin::~KDEConnectPlugin() { s_cleanupI18nResource(); }

    QString KDEConnectPlugin::name() const { return tr("KDE Connect"); }

    QString KDEConnectPlugin::iid() const { return QLatin1String(DPLUGIN_IID); }

    QIcon KDEConnectPlugin::icon() const
    {
        return QIcon::fromTheme(QLatin1String("kdeconnect"));
    }

    QString KDEConnectPlugin::description() const
    {
        return tr("A tool to send photos via KDE Connect");
    }

    QString KDEConnectPlugin::details() const
    {
        return tr(
            "<p>This plugin sends photos to other devices using KDE Connect.</p>");
    }

    QList<DPluginAuthor> KDEConnectPlugin::authors() const
    {
        return QList<DPluginAuthor>()
               << DPluginAuthor(QString::fromUtf8("Isaac Wismer"),
                                QString::fromUtf8("isaac at iwismer dot ca"),
                                QString::fromUtf8("(C) 2021"));
    }

    void KDEConnectPlugin::setup(QObject *const parent)
    {
        DPluginAction *const ac = new DPluginAction(parent);
        ac->setIcon(icon());
        ac->setText(tr("Send via KDE Connect"));
        ac->setObjectName(QLatin1String("kdeconnect"));
        ac->setActionCategory(DPluginAction::GenericTool);

        connect(ac, SIGNAL(triggered(bool)), this, SLOT(slotKDEConnect()));

        addAction(ac);
    }

    void KDEConnectPlugin::slotKDEConnect()
    {
        QPointer<KDEConnectWindow> dialog = new KDEConnectWindow(nullptr, infoIface(sender()));
        dialog->setPlugin(this);
        dialog->exec();
        delete dialog;
    }

} // namespace DigikamKDEConnectPlugin
