/* ============================================================
 *
 * Date        : 2021-01-11
 * Description : KDE Connect Share plugin.
 *
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
#ifndef KDE_CONNECT_WINDOW_H
#define KDE_CONNECT_WINDOW_H

#include <QDialog>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

#include "dinfointerface.h"
#include "dplugindialog.h"

using namespace Digikam;

namespace DigikamKDEConnectPlugin
{

    class KDEConnectWindow : public DPluginDialog
    {
        Q_OBJECT

    public:
        explicit KDEConnectWindow(QWidget *const parent, DInfoInterface *const iface);

    private:
        std::string runCommand(const char *cmd);
        void setupUi();

        QDialog *dialog;
        QVBoxLayout *verticalLayout;
        QLabel *label;
        QListWidget *listWidget;

        QStringList device_names;
        QStringList device_ids;
        QList<QUrl> images;

    private Q_SLOTS:
        void sendFiles();
    };

} // namespace DigikamKDEConnectPlugin

#endif // KDE_CONNECT_WINDOW_H
