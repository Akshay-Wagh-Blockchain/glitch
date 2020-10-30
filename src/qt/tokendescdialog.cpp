#include <qt/tokendescdialog.h>
#include <qt/forms/ui_tokendescdialog.h>

#include <qt/tokenfilterproxy.h>
#include <qt/styleSheet.h>

#include <QModelIndex>

TokenDescDialog::TokenDescDialog(const QModelIndex &idx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TokenDescDialog)
{
    ui->setupUi(this);

    // Set stylesheet
    SetObjectStyleSheet(this, StyleSheetNames::ScrollBarDark);

    setWindowTitle(tr("Details for %1").arg(idx.data(TokenTransactionTableModel::TxHashRole).toString()));
    QString desc = idx.data(TokenTransactionTableModel::LongDescriptionRole).toString();
    ui->detailText->setHtml(desc);
}

TokenDescDialog::~TokenDescDialog()
{
    delete ui;
}
