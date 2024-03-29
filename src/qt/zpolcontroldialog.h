// Copyright (c) 2017-2020 The POLARISNETWORK developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZPOLCONTROLDIALOG_H
#define ZPOLCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zpol/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZpolControlDialog;
}

class CZpolControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZpolControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZpolControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZpolControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZpolControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZpolControlDialog(QWidget *parent);
    ~ZpolControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZpolControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZpolControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZPOLCONTROLDIALOG_H
