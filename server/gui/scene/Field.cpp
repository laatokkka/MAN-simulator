#include "Field.h"
#include <QShortcut>
#include <QMenu>
#include <QGraphicsItem>
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox> 
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>

Field::Field(QWidget* parent) {
    scene_ = new QGraphicsScene(this);
    setScene(scene_);

    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::NoDrag);
    
    // TODO добавить приближение / отдаление
    //setDragMode(QGraphicsView::ScrollHandDrag);

    setSceneRect(0, 0, 350, 500);
    create_field();
}

void Field::create_field() {
    scene_->clear();

    QColor BORDER_COLOR = QColor(191, 154, 85);
    QColor BACKGROUND_COLOR_DARK = QColor(20, 20, 20);
    QColor BACKGROUND_COLOR_LIGHT = QColor(26, 26, 26);

    // Задний фон
    double stripe_width = 30; // qt round it
    double offset = 20;
    QColor filling_color;

    scene_->addRect(0, 0, 340, 20, QPen(BACKGROUND_COLOR_LIGHT), QBrush(BACKGROUND_COLOR_LIGHT));

    int border = offset;
    for (int i = 0; i < 15; i++) {
        if (i % 2 == 0) filling_color = BACKGROUND_COLOR_DARK;
        else filling_color = BACKGROUND_COLOR_LIGHT;

        scene_->addRect(0, border, 340, stripe_width, QPen(filling_color), QBrush(filling_color));
        border += stripe_width;
    }

    scene_->addRect(0, border, 340, 20, QPen(BACKGROUND_COLOR_LIGHT), QBrush(BACKGROUND_COLOR_LIGHT));

    // TODO границы сцены
    // scene_->addRect(0, 0, 350, 500, QPen(/* Другой цвет */, 1));

    // Границы поля
    scene_->addRect(20, 20, 300, 450, QPen(BORDER_COLOR, 1));
    
    // Ворота
    scene_->addRect(120, 0, 100, 20, QPen(BORDER_COLOR, 1));
    scene_->addRect(120, 470, 100, 20, QPen(BORDER_COLOR, 1));
}

void Field::mousePressEvent(QMouseEvent* event) {
    QPointF mouse_position = mapToScene(event->pos());

    if (event->button() == Qt::LeftButton) {
        // TODO перемещение объекта
        QGraphicsView::mousePressEvent(event);


    } else if (event->button() == Qt::RightButton) {
        QMenu sub_menu;
        sub_menu.addAction("Add Player", [this, mouse_position] {


            // TODO в отдельный класс 
            QDialog dialog(this);
            dialog.setWindowTitle("New Player");

            QFormLayout form;

            QPushButton teamButton("", &dialog);
            teamButton.setStyleSheet("background-color: blue; color: white; font-weight: bold;");
            
            teamButton.setCheckable(true);
            teamButton.setChecked(false); // по умолчанию Team A

            form.addRow("Команда:", &teamButton);

            // реакция на нажатие
            QObject::connect(&teamButton, &QPushButton::toggled, [&](bool checked) {
                if (checked) {
                    teamButton.setText("");
                    teamButton.setStyleSheet("background-color: blue; color: white; font-weight: bold;");
                } else {
                    teamButton.setText("");
                    teamButton.setStyleSheet("background-color: red; color: white; font-weight: bold;");
                } 
            });

            QVBoxLayout layout;
            layout.addLayout(&form);
            //layout.addWidget(&buttons);

            dialog.setLayout(&layout);

            if (dialog.exec() == QDialog::Accepted) {
                // TODO 
            }

            // TODO
            // QComboBox positionBox;
            // positionBox.addItems({"Goalkeeper", "Defender", "Midfielder", "Forward"});

        });

        sub_menu.addAction("Remove Player", [this, mouse_position] {
            // ?
        });

        sub_menu.addAction("Edit Player", [this, mouse_position] {
            // TODO повторное открытие окна при нажатии на игрока
        });

        sub_menu.exec(event->globalPosition().toPoint());
    }


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
}


// TODO сделать чтобы в режиме запущенной симуляции это выполнялось в режиме реального времени
//      а не сразу перемещалось
// rect->setFlag(QGraphicsItem::ItemSendsGeometryChanges);

// TODO какие-то ивенты на кнопки привязать (del)
//void Field::connect_ui() {
//    QShortcut* right_pressed = new QShortcut();
//}