#include "PlayerDialog.h"

#include <QIntValidator>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>

PlayerDialog::PlayerDialog(QWidget *parent) {
    full_name_ = new QLineEdit(this);
    number_ = new QLineEdit(this);

    // Валидация для ввода
    QIntValidator *validator = new QIntValidator(1, 99, this);
    number_->setValidator(validator);

    position_ = new QComboBox(this);

    // TODO уточнить наименования в RoboCup
    position_->addItems({"Goalie", "Defender", "Midfielder", "Forward"});

    team_ = new QPushButton("", this);
    team_->setCheckable(true);
    team_->setStyleSheet("background-color: #ff5a5f; color: white; font-weight: bold;");

    connect(team_, &QPushButton::toggled, this, [this](bool checked) {
        if (checked) {
            team_->setText("");
            team_->setStyleSheet("background-color: #4da3ff; color: white; font-weight: bold;");
        } else {
            team_->setText("");
            team_->setStyleSheet("background-color: #ff5a5f; color: white; font-weight: bold;");
        }
    });

    // TODO центрировать блок
    buttons_ = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttons_, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons_, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // TODO центрировать все
    QFormLayout *forms_ = new QFormLayout;
    forms_->addRow("Name:", full_name_);
    forms_->addRow("Number:", number_);
    forms_->addRow("Position:", position_);

    // TODO переделать без левой части с подписыванием
    forms_->addRow("", team_); 

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(forms_);
    mainLayout->addWidget(buttons_);

    setLayout(mainLayout);
}

void PlayerDialog::add_player() {
    // TODO to server add player (на сервере ему выдается id)

    setWindowTitle("Add Player");
}

void PlayerDialog::edit_player() {
    // TODO импорт данных с сервера с настройками для этого игрока

    setWindowTitle("Edit Player");
}

QString PlayerDialog::getPlayerName() const {
    return full_name_->text();
}

int PlayerDialog::getPlayerNumber() const {
    return number_->text().toInt(); 
}