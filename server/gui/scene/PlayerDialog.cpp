#include "PlayerDialog.h"

#include <QIntValidator>

PlayerDialog::PlayerDialog(QWidget *parent) {

    full_name_ = new QLineEdit(this);
    number_ = new QLineEdit(this);

    // Валидация для ввода
    QIntValidator *validator = new QIntValidator(1, 99, this);
    number_->setValidator(validator);

    


}





            // TODO
            // QComboBox positionBox;
            // positionBox.addItems({"Goalkeeper", "Defender", "Midfielder", "Forward"});

/*
            QLineEdit nameEdit;
            QSpinBox numberSpin;
            numberSpin.setRange(1, 99);
            QDialogButtonBox buttons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

            // Компоновка
            
            form.addRow("Имя игрока:", &nameEdit);
            form.addRow("Номер:", &numberSpin);

            
            form.addRow("Позиция:", &positionBox);

            QString position = positionBox.currentText();

            

            // Реакция на кнопки
            QObject::connect(&buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
            QObject::connect(&buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

            if (dialog.exec() == QDialog::Accepted) {
                QString name = nameEdit.text();
                int number = numberSpin.value();

                auto *circle = scene_->addEllipse(
                    mouse_position.x() - 10,
                    mouse_position.y() - 10,
                    20, 20,
                    QPen(Qt::blue),
                    QBrush(Qt::darkBlue)
                );

                circle->setToolTip(QString("%1 (#%2)").arg(name).arg(number));
                circle->setFlag(QGraphicsItem::ItemIsMovable);
                circle->setFlag(QGraphicsItem::ItemIsSelectable);
            }
        });

*/



    // else if (event->button() == Qt::RightButton) {
    //     QMenu sub_menu;
    //     sub_menu.addAction("Add Player", [this, mouse_position] {
    //         // TODO окно добавления игрока

    //         auto* circle = scene_->addEllipse(mouse_position.x() - 10, mouse_position.y() - 10, 20, 20, QPen(Qt::blue), QBrush(Qt::darkBlue));
            
    //         circle->setFlag(QGraphicsItem::ItemIsMovable);
    //         circle->setFlag(QGraphicsItem::ItemIsSelectable);
    //     });

    //     sub_menu.exec(event->globalPosition().toPoint());
    // }
//}


// TODO сделать чтобы в режиме запущенной симуляции это выполнялось в режиме реального времени
//      а не сразу перемещалось
// rect->setFlag(QGraphicsItem::ItemSendsGeometryChanges);

// TODO какие-то ивенты на кнопки привязать (del)
//void Field::connect_ui() {
//    QShortcut* right_pressed = new QShortcut();
//}

// // TODO в отдельный класс 
//             QDialog dialog(this);
//             dialog.setWindowTitle("New Player");

//             QFormLayout form;

//             QPushButton teamButton("", &dialog);
//             teamButton.setStyleSheet("background-color: blue; color: white; font-weight: bold;");

//             teamButton.setCheckable(true);
//             teamButton.setChecked(false); // по умолчанию Team A

//             form.addRow("Team:", &teamButton);

//             // реакция на нажатие
//             QObject::connect(&teamButton, &QPushButton::toggled, [&](bool checked) {
//                 if (checked) {
//                     teamButton.setText("");
//                     teamButton.setStyleSheet("background-color: blue; color: white; font-weight: bold;");
//                 } else {
//                     teamButton.setText("");
//                     teamButton.setStyleSheet("background-color: red; color: white; font-weight: bold;");
//                 } 
//             });

//             QVBoxLayout layout;
//             layout.addLayout(&form);
//             //layout.addWidget(&buttons);

//             dialog.setLayout(&layout);

//             if (dialog.exec() == QDialog::Accepted) {
//                 // TODO 
//             }