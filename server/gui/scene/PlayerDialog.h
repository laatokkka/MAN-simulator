#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>

class PlayerDialog : public QDialog {
    Q_OBJECT

    private:
        QLineEdit *full_name_ = nullptr;
        QLineEdit *number_ = nullptr;
        QPushButton *team_ = nullptr;

        QComboBox *position_ = nullptr;
        QDialogButtonBox *buttons_ = nullptr; // TODO : OK | Cancel

    public:
        explicit PlayerDialog(QWidget *parent = nullptr);

        // TODO возможно стоит сделать приватными
        void add_player();
        void edit_player();

        QString getPlayerName() const; 
        int getPlayerNumber() const;
};