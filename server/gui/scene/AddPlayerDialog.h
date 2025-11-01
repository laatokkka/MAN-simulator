#pragma once

#include <QDialog>

struct PlayerInfo {
    QString full_name;
    int number;
    // TODO add-position
    bool team;
};

class AddPlayerDialog : public QDialog {
    Q_OBJECT

    private:

    public:
        explicit AddPlayerDialog(QWidget *parent = nullptr);
};