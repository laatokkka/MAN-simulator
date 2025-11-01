#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>

struct PlayerInfo {
    QString full_name;
    int number;
    bool team;
};

// for ADD and for EDIT
class PlayerDialog : public QDialog {
    Q_OBJECT

    private:
        QLineEdit *full_name_;
        QLineEdit *number_;
        QComboBox *position_;
        QPushButton *team_;
        QDialogButtonBox *buttons_;

    public:
        explicit PlayerDialog(QWidget *parent = nullptr);
};