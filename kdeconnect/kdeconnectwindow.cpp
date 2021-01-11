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
#include "kdeconnectwindow.h"

// C++ includes
#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>

// digiKam includes
#include "dplugindialog.h"

namespace DigikamKDEConnectPlugin
{

    KDEConnectWindow::KDEConnectWindow(QWidget *const parent,
                                       DInfoInterface *const iface)
        : DPluginDialog(parent, QLatin1String("KDE Connect Export"))
    {
        setupUi();

        images = iface->currentSelectedItems();

        if (images.isEmpty())
        {
            images = iface->currentAlbumItems();
        }

        std::string device_output = runCommand("kdeconnect-cli -a --id-name-only");

        std::stringstream ss(device_output);
        std::string to;
        while (std::getline(ss, to, '\n'))
        {
            int index = to.find(" ");
            device_names << QString::fromStdString(to.substr(index + 1));
            listWidget->addItem(QString::fromStdString(to.substr(index + 1)));
            device_ids << QString::fromStdString(to.substr(0, index));
        }
        if (listWidget->count() > 0)
        {
            listWidget->setCurrentRow(0);
        }
    }

    void KDEConnectWindow::setupUi()
    {
        resize(400, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("kdeconnect")));
        setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(this);
        label = new QLabel(this);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(this);

        verticalLayout->addWidget(listWidget);

        m_buttons->setOrientation(Qt::Horizontal);
        m_buttons->setStandardButtons(QDialogButtonBox::Cancel |
                                      QDialogButtonBox::Ok);

        verticalLayout->addWidget(m_buttons);

        setWindowTitle(tr("KDE Connect"));
        label->setText(tr("Available Devices:"));

        connect(m_buttons, SIGNAL(accepted()), this, SLOT(sendFiles()));
        connect(m_buttons, SIGNAL(rejected()), this, SLOT(reject()));

        QMetaObject::connectSlotsByName(this);
    }

    std::string KDEConnectWindow::runCommand(const char *cmd)
    {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe)
        {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        {
            result += buffer.data();
        }
        return result;
    }

    void KDEConnectWindow::sendFiles()
    {
        // TODO this has never been tested
        if (device_ids.empty() || images.empty())
        {
            accept();
        }
        for (int i = 0; i < images.length(); i++)
        {
            std::string command = "kdeconnect-cli --share \"" +
                                  images.at(i).toDisplayString().toStdString() +
                                  "\" --device " +
                                  device_ids.at(listWidget->currentRow()).toStdString();
            runCommand(command.c_str());
        }
        accept();
    }

} // namespace DigikamKDEConnectPlugin
