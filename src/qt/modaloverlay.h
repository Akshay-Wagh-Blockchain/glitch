// Copyright (c) 2016-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GLITCH_QT_MODALOVERLAY_H
#define GLITCH_QT_MODALOVERLAY_H

#include <QDateTime>
#include <QWidget>

//! The required delta of headers to the estimated number of available headers until we show the IBD progress
static constexpr int HEADER_HEIGHT_DELTA_SYNC = 24;

namespace Ui {
    class ModalOverlay;
}

/** Modal overlay to display information about the chain-sync state */
class ModalOverlay : public QWidget
{
    Q_OBJECT

public:
    enum OverlayType
    {
        Sync = 0,
        Backup = 1
    };

    explicit ModalOverlay(QWidget *parent, OverlayType _type = OverlayType::Sync);
    ~ModalOverlay();

public Q_SLOTS:
    void tipUpdate(int count, const QDateTime& blockDate, double nVerificationProgress);
    void setKnownBestHeight(int count, const QDateTime& blockDate);

    void toggleVisibility();
    // will show or hide the modal layer
    void showHide(bool hide = false, bool userRequested = false);
    void closeClicked();
    void backupWalletClicked();
    bool isLayerVisible() const { return layerIsVisible; }

Q_SIGNALS:
    void backupWallet();

protected:
    bool eventFilter(QObject * obj, QEvent * ev);
    bool event(QEvent* ev);

private:
    Ui::ModalOverlay *ui;
    int bestHeaderHeight; //best known height (based on the headers)
    QDateTime bestHeaderDate;
    QVector<QPair<qint64, double> > blockProcessTime;
    bool layerIsVisible;
    bool userClosed;
    OverlayType type;
};

#endif // GLITCH_QT_MODALOVERLAY_H
