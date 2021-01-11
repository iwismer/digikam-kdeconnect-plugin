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

#ifndef DIGIKAM_KDE_CONNECT_PLUGIN_H
#define DIGIKAM_KDE_CONNECT_PLUGIN_H

// C++ includes
#include <string>

// Local includes
#include "dplugingeneric.h"

#define DPLUGIN_IID "org.kde.digikam.plugin.generic.KDEConnect"

using namespace Digikam;

namespace DigikamKDEConnectPlugin
{

    class KDEConnectPlugin : public DPluginGeneric
    {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID DPLUGIN_IID)
        Q_INTERFACES(Digikam::DPluginGeneric)

    public:
        explicit KDEConnectPlugin(QObject *const parent = nullptr);
        ~KDEConnectPlugin();

        QString name() const override;
        QString iid() const override;
        QIcon icon() const override;
        QString details() const override;
        QString description() const override;
        QList<DPluginAuthor> authors() const override;

        void setup(QObject *const) override;

    private Q_SLOTS:

        void slotKDEConnect();
    };

} // namespace DigikamKDEConnectPlugin

#endif // DIGIKAM_KDE_CONNECT_PLUGIN_H
